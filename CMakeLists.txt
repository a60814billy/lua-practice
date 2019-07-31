cmake_minimum_required(VERSION 3.14)
project(lua_practice)

include_directories(lua)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_COMPILER /usr/local/bin/x86_64-apple-darwin18-gcc-9)
set(CMAKE_CXX_COMPILER /usr/local/bin/x86_64-apple-darwin18-g++-9)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-undefined dynamic_lookup")

set(CMAKE_CXX_STANDARD 17)

file(GLOB LUA_SOURCE ${PROJECT_SOURCE_DIR}/lua/*.c)

list(REMOVE_ITEM LUA_SOURCE "${PROJECT_SOURCE_DIR}/lua/lua.c")

add_executable(lua_practice main.cpp ${LUA_SOURCE})