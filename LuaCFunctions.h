#pragma once
#include <Windows.h>

#define ScanAddr(addr)(addr - 0x400000 + (int)GetModuleHandle(0))

namespace RBXLuaC {
	DWORD getFieldAddr = ScanAddr(0x72A510);
	DWORD pushStringAddr = ScanAddr(0x72B8B0);
	DWORD pushValueAddr = ScanAddr(0x72B970);
	DWORD callAddr = ScanAddr(0x729E80);
	DWORD setFieldAddr = ScanAddr(0x72C270);
	DWORD pushNumbAddr = ScanAddr(0x72B820);

	typedef void(*Lua_getField)(int luaState, int index, const char* Obj);
	typedef void(*Lua_pushString)(int luaState, const char* String);
	typedef void(*Lua_pushValue)(int luaState, int Index);
	typedef void(*Lua_call)(int luaState, int arg1, int arg2);
	typedef void(*Lua_setField)(int luaState, int index, const char* Obj);
	typedef void(*Lua_pushNumber)(int luaState, int numb);
	
	Lua_getField rbxLua_getfield = (Lua_getField)getFieldAddr;
	Lua_pushString rbxLua_pushString = (Lua_pushString)pushStringAddr;
	Lua_pushValue rbxLua_pushValue = (Lua_pushValue)pushValueAddr;
	Lua_call rbxLua_call = (Lua_call)callAddr;
	Lua_setField rbxLua_setField = (Lua_setField)setFieldAddr;
	Lua_pushNumber rbxLua_pushNumber = (Lua_pushNumber)pushNumbAddr;
}
