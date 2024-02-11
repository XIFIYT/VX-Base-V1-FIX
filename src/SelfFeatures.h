#include "Common.hpp"
#pragma once

namespace Self
{
	void Invincible(bool toggle)
	{
		if (toggle)
		{
			ENTITY::SET_ENTITY_INVINCIBLE(playerPED, 1);
		}
		else
		{
			ENTITY::SET_ENTITY_INVINCIBLE(playerPED, 0);
		}
	}
	void Invisible(bool toggle)
	{
		if (!PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			if (toggle)
			{
				ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), false, 0);
			}
			else ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true, 0);
		}

	}
	void Suicide()
	{
		ENTITY::SET_ENTITY_HEALTH(playerPED, 0, 0);
	}

	void SelfLoop()
	{
		//your fonction to save
		Invincible(g_settings.options["Self_Invincible"].get<bool>());
		Invisible(g_settings.options["Self_Invisible"].get<bool>());
	}
}