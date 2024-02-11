#include "Hooking.hpp"
#include "Games.hpp"
#include "ScriptManager.hpp"
#include "CustomText.hpp"
#include "Util.hpp"
#include "D3DRenderer.hpp"
#include "UI/UIManager.hpp"
#include "Natives.hpp"
#include <MinHook.h>
#include "LogMenu.hpp"
#include <Psapi.h>


namespace VX
{
	namespace
	{
		std::uint32_t g_HookFrameCount{};
	}

	// By using this to hook natives, we are sacrificing performance for safety 
	// Detouring it is faster, but cockstar detects that
	void Hooks::GetStatInt(rage::scrNativeCallContext* src)
	{
		const auto statHash = src->get_arg<Hash>(0);
		const auto outValue = src->get_arg<int*>(1);
		const auto p2 = src->get_arg<int>(2);

		if (m_CheatRunning && g_HookFrameCount != *g_GameVariables->m_FrameCount)
		{
			g_HookFrameCount = *g_GameVariables->m_FrameCount;
			g_ScriptManager->OnGameTick();
		}

		src->set_return_value(STATS::STAT_GET_INT(statHash, outValue, p2));
	}

	void Hooks::GetEventData(rage::scrNativeCallContext* src)
	{
		const auto eventGroup = src->get_arg<int>(0);
		const auto eventIndex = src->get_arg<int>(1);
		const auto args = src->get_arg<Any*>(2);
		const auto argCount = src->get_arg<Hash>(3);


		src->set_return_value(SCRIPT::GET_EVENT_DATA(eventGroup, eventIndex, args, argCount));
	}

	const char* Hooks::GetLabelText(void* unk, const char* label)
	{
		if (m_CheatRunning)
			if (auto text = g_CustomText->GetText(Joaat(label)))
				return text;

		return static_cast<decltype(&GetLabelText)>(g_Hooking->m_OriginalGetLabelText)(unk, label);
	}

	LRESULT Hooks::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		g_D3DRenderer->WndProc(hWnd, msg, wParam, lParam);
		return static_cast<decltype(&WndProc)>(g_Hooking->m_OriginalWndProc)(hWnd, msg, wParam, lParam);
	}

	HRESULT Hooks::Present(IDXGISwapChain* dis, UINT syncInterval, UINT flags)
	{
		if (m_CheatRunning)
		{
			g_D3DRenderer->BeginFrame();
			g_ScriptManager->OnD3DTick();
			g_D3DRenderer->EndFrame();
		}

		return g_Hooking->m_D3DHook.GetOriginal<decltype(&Present)>(PresentIndex)(dis, syncInterval, flags);
	}

	HRESULT Hooks::ResizeBuffers(IDXGISwapChain* dis, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags)
	{
		if (m_CheatRunning)
		{
			g_D3DRenderer->PreResize();
			auto hr = g_Hooking->m_D3DHook.GetOriginal<decltype(&ResizeBuffers)>(ResizeBuffersIndex)(dis, bufferCount, width, height, newFormat, swapChainFlags);
			if (SUCCEEDED(hr))
			{
				g_D3DRenderer->PostResize();
			}

			return hr;
		}

		return g_Hooking->m_D3DHook.GetOriginal<decltype(&ResizeBuffers)>(ResizeBuffersIndex)(dis, bufferCount, width, height, newFormat, swapChainFlags);
	}

	bool IsAddressInGameRegion(std::uint64_t address)
	{
		static std::uint64_t moduleBase = NULL;
		static std::uint64_t moduleSize = NULL;
		if ((!moduleBase) || (!moduleSize))
		{
			MODULEINFO info;
			if (!GetModuleInformation(GetCurrentProcess(), GetModuleHandle(0), &info, sizeof(info)))
			{
				return true;
			}
			else
			{
				moduleBase = (std::uint64_t)GetModuleHandle(0);
				moduleSize = (std::uint64_t)info.SizeOfImage;
			}
		}
		return address > moduleBase && address < (moduleBase + moduleSize);
	}

	bool IsJumpInstruction(__int64 fptr)
	{
		if (!IsAddressInGameRegion(fptr))
			return false;

		auto value = *(std::uint8_t*)(fptr);
		return value == 0xE9;
	}

	bool IsUnwantedDependency(__int64 cb)
	{
		auto f1 = *(__int64*)(cb + 0x60);
		auto f2 = *(__int64*)(cb + 0x100);
		auto f3 = *(__int64*)(cb + 0x1A0);

		if (!IsAddressInGameRegion(f1) || !IsAddressInGameRegion(f2) || !IsAddressInGameRegion(f3))
			return false;

		return IsJumpInstruction(f1) || IsJumpInstruction(f2) || IsJumpInstruction(f3);
	}

	void Hooks::QueueDependency(void* dependency)
	{
		if (IsUnwantedDependency((__int64)dependency))
			return;

		return static_cast<decltype(&QueueDependency)>(g_Hooking->m_OriginalQueueDependency)(dependency);
	}

	Hooking::Hooking() :
		m_D3DHook(g_GameVariables->m_Swapchain, 18)
	{

		MH_Initialize();
		MH_CreateHook(g_GameFunctions->m_GetLabelText, &Hooks::GetLabelText, &m_OriginalGetLabelText);
		g_LogMenu->Info("Found Hook GLT");
		MH_CreateHook(g_GameFunctions->m_WndProc, &Hooks::WndProc, &m_OriginalWndProc);
		g_LogMenu->Info("Found Hook WND");
		MH_CreateHook(g_GameFunctions->m_QueueDependency, &Hooks::QueueDependency, &m_OriginalQueueDependency);
		g_LogMenu->Info("Found Hook QD");

		m_D3DHook.Hook(&Hooks::Present, Hooks::PresentIndex);
		m_D3DHook.Hook(&Hooks::ResizeBuffers, Hooks::ResizeBuffersIndex);
	}

	Hooking::~Hooking() noexcept
	{
		MH_RemoveHook(g_GameFunctions->m_GetLabelText);
		MH_RemoveHook(g_GameFunctions->m_WndProc);
		MH_RemoveHook(g_GameFunctions->m_QueueDependency);

		g_LogMenu->Info("Disabled all Hooks!");
		MH_Uninitialize();
	}

	void Hooking::Hook()
	{
		m_D3DHook.Enable();
		MH_EnableHook(MH_ALL_HOOKS);
	}

	void Hooking::Unhook()
	{
		m_D3DHook.Disable();
		MH_DisableHook(MH_ALL_HOOKS);
	}
}
