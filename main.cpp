#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

using namespace std;

int main(int argc, char *argv[]) {
    string luaLaunchScriptName = "main.lua";
    lua_State *luaState = luaL_newstate();
    luaL_openlibs(luaState);
    if (argc > 1) {
        luaL_dofile(luaState, argv[1]);
    } else {
        luaL_dofile(luaState, luaLaunchScriptName.c_str());
    }
    lua_close(luaState);
    return 0;
}