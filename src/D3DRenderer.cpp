#include "D3DRenderer.hpp"
#include "Games.hpp"
#include "UI/UIManager.hpp"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"

IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace VX
{
	D3DRenderer::D3DRenderer() :
		m_Swapchain(g_GameVariables->m_Swapchain)
	{
		if (FAILED(m_Swapchain->GetDevice(__uuidof(ID3D11Device), (void**)(&m_Device))))
			g_LogMenu->Error("Failed to get D3D Device");
		m_Device->GetImmediateContext(&m_Context);

		ImGui::CreateContext();
		ImGui_ImplDX11_Init(m_Device, m_Context);
		ImGui_ImplWin32_Init(g_GameVariables->m_GameWindow);

		auto& style = ImGui::GetStyle();
		ImGui::StyleColorsDark();
	}

	D3DRenderer::~D3DRenderer() noexcept
	{
		ImGui_ImplDX11_Shutdown();
		ImGui_ImplWin32_Shutdown();
		ImGui::DestroyContext();
	}

	void D3DRenderer::BeginFrame()
	{
		if (g_Ui->m_Opened && g_Settings.m_LockMouse)
		{
			ImGui::GetIO().MouseDrawCursor = true;
			ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NoMouse;
		}
		else
		{
			ImGui::GetIO().MouseDrawCursor = false;
			ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouse;
		}

		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
	}

	void D3DRenderer::EndFrame()
	{
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

	void D3DRenderer::PreResize()
	{
		ImGui_ImplDX11_InvalidateDeviceObjects();
	}

	void D3DRenderer::PostResize()
	{
		ImGui_ImplDX11_CreateDeviceObjects();
	}

	void D3DRenderer::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (g_Ui->m_Opened && msg == WM_KEYUP && wParam == 'X')
			g_Settings.m_LockMouse = !g_Settings.m_LockMouse;

		if (ImGui::GetCurrentContext())
			ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam);
	}
}
