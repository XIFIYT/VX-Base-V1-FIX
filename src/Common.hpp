#pragma once
#include <winsdkver.h>
#include <sdkddkver.h>
#include <windows.h>
#include <winternl.h>
#include <d3d11.h>

#include <cassert>
#include <cinttypes>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <deque>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <type_traits>
#include <unordered_map>
#include <vector>

// JSON
#include <nlohmann/json.hpp>
#include <nlohmann/json_fwd.hpp>

// GTA-V
#include <script/scrNativeHandler.hpp>
#include <script/scrNativeRegistration.hpp>
#include <script/scrNativeRegistrationTable.hpp>
#include "ImGui/imgui.h"

#define BIGBASE_WIDE_IMPL(str) L ## str
#define BIGBASE_WIDE(str) BIGBASE_WIDE_IMPL(str)

#define BIGBASE_STRINGIZE_IMPL(x) #x
#define BIGBASE_STRINGIZE(x) BIGBASE_STRINGIZE_IMPL(x)

#define VX_NAME "VX Base"

/*
*	SELF
*/

#define playerPED PLAYER::PLAYER_PED_ID()
#define playerID PLAYER::PLAYER_ID()
#define playerCoord ENTITY::GET_ENTITY_COORDS(playerPED, 1)
#define playerCurrentVeh PED::GET_VEHICLE_PED_IS_USING(playerPED)

namespace VX
{
	using namespace std;
	using namespace std::chrono_literals;
	namespace fs = std::filesystem;

	inline HMODULE m_Module{};
	inline uint32_t selectedPlayer{};
	inline atomic_bool m_CheatRunning = 1;

	inline bool m_LogSE = 0;
}

#include "Settings.hpp"
#include "LogMenu.hpp"
#include "Util.hpp"
#include "Memory.hpp"
#include "Games.hpp"
#include "ScriptGlobal.hpp"

#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Lists.hpp"
#include "Natives.hpp"
#include "Timer.hpp"
#include "CustomText.hpp"
#include "UI/UIManager.hpp"
#include "UI/BoolOption.hpp"
#include "UI/ChooseOption.hpp"
#include "UI/NumberOption.hpp"
#include "UI/RegularOption.hpp"
#include "UI/SubOption.hpp"
#include "UI/RegularSubmenu.hpp"
#include "UI/PlayerSubmenu.hpp"
#include "Settings.h"

using namespace VX;