#pragma once
#include <windows.h>

#ifndef LuaCFunctionsHeaderGuard
#define LuaCFunctionsHeaderGuard

#define ScanAddr(addr)(addr - 0x400000 + (int)GetModuleHandle(0)) //someone move this to Memory

#define getfield_addr 	ScanAddr(0x72A510);
#define pushstring_addr ScanAddr(0x72B8B0);
#define pushvalue_addr  ScanAddr(0x72B970);
#define pushnil_addr	ScanAddr();
#define pcall_addr	ScanAddr();
#define call_addr 	ScanAddr(0x729E80);
#define setfield_addr 	ScanAddr(0x72C270);
#define pushnumber_addr	ScanAddr(0x72B820);
#define rawrjz_addr	ScanAddr();

extern DWORD rL;

typedef void(*Lua_getfield)	(DWORD, int, const char*);
typedef void(*Lua_setfield)	(DWORD, int, const char*);
typedef void(*Lua_pushstring)	(DWORD, const char*);
typedef void(*Lua_pushnumber)	(DWORD, __int64);
typedef void(*Lua_pushvalue)	(DWORD, int);
typedef void(*Lua_pushnil)	(DWORD);
typedef void(*Lua_pcall)	(DWORD, int, int, int);
typedef void(*Lua_call)		(DWORD, int, int);

Lua_getfield rLua_getfield = (Lua_getfield)getfield_addr;
Lua_setfield rLua_setfield = (Lua_setfield)setfield_addr;
Lua_pushstring rLua_pushstring = (Lua_pushstring)pushstring_addr;
Lua_pushnumber rLua_pushnumber = (Lua_pushnumber)pushnumber_addr;
Lua_pushvalue rLua_pushvalue = (Lua_pushvalue)pushvalue_addr;
Lua_pushnil rLua_pushnil = (Lua_pushnil)pushnil_addr;
Lua_pcall rLua_pcall = (Lua_pcall)pcall_addr;
Lua_call rLua_call = (Lua_call)call_addr;

namespace LuaC {
	void getfield(DWORD L = rL, int idx, std::string k)
	{
		rLua_getfield(L, idx, k.c_str());
	}
	
	void setfield(DWORD L = rL, int idx, std::string k)
	{
		rLua_setfield(L, idx, k.c_str());
	}
	
	void getglobal(DWORD L = rL, int idx, std::string k)
	{
		getfield(L, -10002, k);
	}
	
	void setglobal(DWORD L = rL, int idx, std::string k)
	{
		setfield(L, -10002, k);
	}
	
	void pushstring(DWORD L = rL, std::string s)
	{
		rbxLua_pushstring(L, s.c_str());
	}
	
	void pushnumber(DWORD L = rL, __int64 n)
	{
		rbxLua_pushnumber(L, n);
	}
	
	void pushvalue(DWORD L = rL, int v)
	{
		rbxLua_pushvalue(L, v);
	}
	
	void pushnil(DWORD L = rL)
	{
		rbxLua_pushnil(L);
	}
	
	void pcall(DWORD L = rL, int nargs, int nresults, int errfunc) 
	{
		WriteProcessMemory(GetCurrentProcess(), (void*)&rawrjz_addr, "\xEB", 1, 0);
		rbxLua_pcall(L, nargs, nresults, errfunc);
		WriteProcessMemory(GetCurrentProcess(), (void*)&rawrjz_addr, "\x74", 1, 0);
	}
	
	void call(DWORD L = rL, int a, int b)
	{
		rbxLua_call(L, a, b);
	}
}

#endif
