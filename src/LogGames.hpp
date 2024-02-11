#pragma once
#include "Script.hpp"

namespace VX
{
	class LogGames : public Script
	{
	public:
		explicit LogGames() = default;
		~LogGames() noexcept = default;

		bool IsInitialized() override;
		ScriptType GetType() override;
		void Initialize() override;
		void Destroy() override;
		void Tick() override;
	private:
		bool m_Initialized{};
	};

	inline std::shared_ptr<LogGames> g_LogGames;
}
