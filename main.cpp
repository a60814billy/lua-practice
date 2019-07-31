#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

extern "C" {
    static int c_addTest (lua_State *L) {
        double arg1 = luaL_checknumber(L, 1);
        double arg2 = luaL_checknumber(L, 2);
        double result = arg1 + arg2;
        lua_pushnumber(L, result);

        return 1;
    }
}

using namespace std;

int main(int argc, char *argv[]) {
    string luaLaunchScriptName = "main.lua";
    lua_State *luaState = luaL_newstate();
    luaL_openlibs(luaState);

    lua_register(luaState, "addTest", c_addTest);

    if (argc > 1) {
        luaL_dofile(luaState, argv[1]);
    } else {
        luaL_dofile(luaState, luaLaunchScriptName.c_str());
    }
    lua_close(luaState);
    return 0;
}