#include "Games.hpp"
#include "LogGames.hpp"
#include "UI/UIManager.hpp"
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"

namespace VX
{
	bool LogGames::IsInitialized()
	{
		return m_Initialized;
	}

	ScriptType LogGames::GetType()
	{
		return ScriptType::D3D;
	}

	void LogGames::Initialize()
	{
		m_Initialized = true;
	}

	void LogGames::Destroy()
	{
	}

	namespace
	{
		std::size_t s_LastLogCount = 0;
	}

	void LogGames::Tick()
	{
		if (g_Ui->m_Opened && g_Settings.m_LogWindow)
		{
			ImGui::SetNextWindowSize(ImVec2(500, 250), ImGuiCond_FirstUseEver);
			ImGui::SetNextWindowPos(ImVec2(50, 50), ImGuiCond_FirstUseEver);
			if (ImGui::Begin("Log", 0, ImGuiWindowFlags_NoTitleBar))
			{
				std::lock_guard lock(g_LogMenu->GetMutex());
				auto msgs = g_LogMenu->GetMessages();

				for (std::size_t i = 0; i < msgs.second; ++i)
				{
					ImGui::TextUnformatted(msgs.first[i].get());
				}

				if (s_LastLogCount != msgs.second)
				{
					s_LastLogCount = msgs.second;
					ImGui::SetScrollHereY(1.f);
				}
			}  ImGui::End();
		}
	}
}
