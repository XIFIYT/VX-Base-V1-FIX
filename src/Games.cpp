#include "Games.hpp"
#include "Invoker.hpp"

namespace VX
{
	GameVariables::GameVariables() :
		m_GameState(Signature("#1","48 85 C9 74 4B 83 3D").Scan().Add(7).Rip().As<decltype(m_GameState)>()),
		m_FrameCount(Signature("#2", "8B 15 ? ? ? ? 41 FF CF").Scan().Add(2).Rip().As<decltype(m_FrameCount)>()),
		m_GameWindow(FindWindowA("grcWindow", "Grand Theft Auto V")),
		m_Swapchain(Signature("#3", "48 8B 0D ? ? ? ? 48 8B 01 44 8D 43 01 33 D2 FF 50 40 8B C8").Scan().Add(3).Rip().As<decltype(m_Swapchain)&>()),
		m_ScriptProgramTable(Signature("#4", "48 8B 1D ? ? ? ? 41 83 F8 FF").Scan().Add(3).Rip().As<decltype(m_ScriptProgramTable)>()),
		m_NativeRegistrations(Signature("#5", "48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A").Scan().Add(3).Rip().As<decltype(m_NativeRegistrations)>()),
		m_GlobalBase(Signature("#6", "48 85 FF 48 89 1D").Scan().Sub(12).Rip().As<decltype(m_GlobalBase)>()),
		m_ModelSpawnBypass(Signature("#7", "48 8B C8 FF 52 30 84 C0 74 05 48").Scan().Add(8).As<decltype(m_ModelSpawnBypass)>())
	{
	}

	void GameVariables::PostInit()
	{
	}

	GameFunctions::GameFunctions() :
		m_GetLabelText(Signature("#8", "48 89 5C 24 ? 57 48 83 EC 20 48 8B DA 48 8B F9 48 85 D2 75 44 E8").Scan().As<decltype(m_GetLabelText)>()),
		m_GetNativeHandler(Signature("#9", "48 8D 0D ? ? ? ? 48 8B 14 FA E8 ? ? ? ? 48 85 C0 75 0A").Scan().Add(12).Rip().As<decltype(m_GetNativeHandler)>()),
		m_WndProc(Signature("#10","48 8B 0D ? ? ? ? 48 8D 55 EF FF 15").Scan().Sub(901).As<decltype(m_WndProc)>()),
		m_FixVectors(Signature("#11", "83 79 18 ? 48 8B D1 74 4A FF 4A 18").Scan().As<decltype(m_FixVectors)>()),
		m_QueueDependency(Signature("#12", "48 89 5C 24 ? 57 48 83 EC ? 0F B6 99").Scan().As<decltype(m_QueueDependency)>())

	{
	}
}
