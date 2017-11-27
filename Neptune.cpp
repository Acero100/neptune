#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <istream>
//we might not need all of these

extern "C" {
#include "Lua\lua.h"
#include "Lua\lua.hpp"
#include "Lua\lualib.h"
#include "Lua\lauxlib.h"
#include "Lua\luaconf.h"
}
//someone should add these files to the github ^

#define debug true

DWORD rL, *scriptContext;

void Console() {
	WriteProcessMemory(GetCurrentProcess(), (void*)FreeConsole, "\xC2", 5, 0); //whenever ROBLOX calls FreeConsole() this will bypass it
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	freopen("CONIN$", "r", stdin);
	ShowWindow(GetConsoleWindow(), SW_SHOWNORMAL);
	SetWindowLong(GetConsoleWindow(), GWL_STYLE, WS_CAPTION | DS_MODALFRAME | WS_MINIMIZEBOX | WS_SYSMENU);
	SetWindowPos(GetConsoleWindow(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_SHOWWINDOW);
	SetConsoleTitle("Neptune Debug Console");
	PVOID H = GetStdHandle(STD_OUTPUT_HANDLE);
} //you can mess with this if you dont like it

int main() {
      if (debug) Console();
      scriptContext = (PDWORD)vftableScan((PCHAR)&scriptcontextvftable_addr); //todo: add the addresses
      rL = ScriptState(0, scriptContext); //todo: make this function (just paste psuedocode)
      if (debug) {
          std::cout << "Scanned!" << std::endl;
		      for (;;) {
				   std::string input;
				   std::getline(std::cin, input);
           //todo: create a thread and execute "input" on that thread
			  }
     }
}
