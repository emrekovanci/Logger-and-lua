#include <iostream>
#include <plog/Log.h>

extern "C"
{
	#include <lua.h>
	#include <lualib.h>
	#include <lauxlib.h>
}

#include "Player.hpp"

bool CheckLua(lua_State* L, int r)
{
	if (r != LUA_OK)
	{
		std::string errorMsg = lua_tostring(L, -1);
		PLOG(plog::error) << errorMsg;
		return false;
	}

	return true;
}

int main()
{
	// init logger
    plog::init(plog::debug, "Log.txt");

	// initialize lua
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    int r = luaL_dofile(L, "Player.lua");

	// create the player object
    Player player;
	
	if (r == LUA_OK)
	{
		// initialize the lua function
		lua_getglobal(L, "GetPlayer");
		if (lua_isfunction(L, -1))
		{
			lua_pushnumber(L, 0);

			if (CheckLua(L, lua_pcall(L, 1, 1, 0)))
			{
				if (lua_istable(L, -1))
				{
					lua_pushstring(L, "Title");
					lua_gettable(L, -2);
					player._title = lua_tostring(L, -1);
					lua_pop(L, 1);

					lua_pushstring(L, "Name");
					lua_gettable(L, -2);
					player._name = lua_tostring(L, -1);
					lua_pop(L, 1);

					lua_pushstring(L, "Family");
					lua_gettable(L, -2);
					player._family = lua_tostring(L, -1);
					lua_pop(L, 1);

					lua_pushstring(L, "Level");
					lua_gettable(L, -2);
					player._level = lua_tonumber(L, -1);
					lua_pop(L, 1);
				}

				PLOG(plog::info) << "PLAYER INFO... " << "Title: " << player._title << ", "
					<< "Name: " << player._name << ", "
					<< "Family: " << player._family << ", "
					<< "Level: " << player._level; 
			}
		}
	}
    else
    {
	    const std::string errorMsg = lua_tostring(L, -1);
	    PLOG(plog::error) << errorMsg;
    }

	
    lua_close(L);
    return 0;
}
