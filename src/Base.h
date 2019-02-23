#pragma once
#include <Windows.h>
#include <iostream>

class Base
{
	public:
		Base();
		~Base();
		HANDLE GetHProccess(HWND hwnd);
		void ChangeMemoryValue(DWORD addr, HANDLE hProcess, float val);
		void ChangeMemoryValue(DWORD addr, HANDLE hProcess, int val);
		bool GrantMemoryPermission(HANDLE hProcess, DWORD addr);
		DWORD GetCPedBaseAddr(HANDLE hProcess, DWORD CPedPointerAddr);
		HWND GetWindowHandle(HANDLE hProcess, DWORD addr);
		
};

