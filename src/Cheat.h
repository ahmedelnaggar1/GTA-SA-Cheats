#pragma once
#include "Base.h"
#include "offsets.h"
#include "addresses.h"
class Cheat
{
	public:
		Cheat(HWND hWnd);
		~Cheat();
		void SetHealth(float health);
		void SetArmor(float armor);

	private:
		Base func;
		HANDLE hProcess;
		DWORD CPedAddr;
		HWND WindowHandle;
};

