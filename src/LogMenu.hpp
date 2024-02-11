#pragma once
#include "Common.hpp"

namespace VX
{
	class LogMenu
	{
	public:
		explicit LogMenu();
		~LogMenu() noexcept;

		LogMenu(LogMenu const&) = delete;
		LogMenu(LogMenu&&) = delete;
		LogMenu& operator=(LogMenu const&) = delete;
		LogMenu& operator=(LogMenu&&) = delete;

		void ShowLoading();

		void Info(const char* format, ...);
		void Pattern(const char* format, ...);
		void Error(const char* format, ...);
		void Raw(const char8_t* format, ...);
		void Loading(const char* format, ...);
		void Log(const char* type, const char* format, std::va_list args);

		std::mutex& GetMutex();
		std::pair<std::unique_ptr<char[]>*, std::size_t> GetMessages();
		std::istream& GetInput();
	private:
		std::mutex m_Mutex;
		std::vector<std::unique_ptr<char[]>> m_Messages;

		fs::path m_FilePath;
		std::ofstream m_File;
		std::ofstream m_Console;
		std::ifstream m_Input;

	};

	inline std::unique_ptr<LogMenu> g_LogMenu;
}
