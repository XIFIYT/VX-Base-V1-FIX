#include "Games.hpp"
#include "Hooking.hpp"
#include "NativeHook.hpp"
#include "ScriptManager.hpp"
#include "LogGames.hpp"
#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Invoker.hpp"
#include "CustomText.hpp"
#include "D3DRenderer.hpp"
#include "UI/UIManager.hpp"

#include "Settings.h"
#include "LogMenu.hpp"

BOOL DllMain(HINSTANCE hInstance, DWORD reason, LPVOID)
{
	using namespace VX;

	if (reason == DLL_PROCESS_ATTACH)
	{
		m_Module = hInstance;
		CreateThread(0, 0, [](LPVOID) -> DWORD
		{
			g_LogMenu = std::make_unique<LogMenu>();
			g_LogMenu->Info(VX_NAME " Injected successfully! ");

			g_GameFunctions = std::make_unique<GameFunctions>();
			g_GameVariables = std::make_unique<GameVariables>();

			g_settings.load();

			while (*g_GameVariables->m_GameState != 0)
			{
				std::this_thread::sleep_for(2ms);
				std::this_thread::yield();
			}

			g_GameVariables->PostInit();

			g_CustomText = std::make_unique<CustomText>();
			g_D3DRenderer = std::make_unique<D3DRenderer>();
			g_Ui = std::make_unique<UserInterface::UIManager>();
			g_ScriptManager = std::make_unique<ScriptManager>();
			g_MainScript = std::make_shared<MainScript>();
			g_LogGames = std::make_shared<LogGames>();
			g_FiberScript = std::make_shared<FiberScript>();
			g_ScriptManager->AddScript(g_MainScript);
			g_ScriptManager->AddScript(g_LogGames);
			g_ScriptManager->AddScript(g_FiberScript);

			g_Hooking = std::make_unique<Hooking>();
			g_Hooking->Hook();

			auto g_NativeHook = std::make_unique<NativeHooks>();

			while (m_CheatRunning)
			{
				if (IsKeyPressed(VK_DELETE))
					m_CheatRunning = false;
				std::this_thread::sleep_for(3ms);
				std::this_thread::yield();
			}

			std::this_thread::sleep_for(100ms);

			g_NativeHook.reset();

			g_Hooking->Unhook();

			g_ScriptManager.reset();
			g_LogGames.reset();
			g_MainScript.reset();
			g_FiberScript.reset();
			g_Ui.reset();
			g_D3DRenderer.reset();
			g_CustomText.reset();

			std::this_thread::sleep_for(100ms);

			g_Hooking.reset();

			g_GameVariables.reset();
			g_GameFunctions.reset();

			g_LogMenu->Info("Called uninjection!");
			g_LogMenu.reset();

			FreeLibraryAndExitThread(m_Module, 0);
		},
		0,
		0,
		0);
	}

	return 1;
}
