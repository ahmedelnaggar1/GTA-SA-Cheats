#include "Cheat.h"

Cheat::Cheat(HWND hWnd)
{
	hProcess = func.GetHProccess(hWnd);
	if (!hProcess)
	{
		MessageBox(NULL, L"Couldn't open game", L"Error", MB_OK | MB_ICONERROR);
	}
	else
	{
		CPedAddr = func.GetCPedBaseAddr(hProcess, ptr_CPed);
		WindowHandle = hWnd;
	}
}


Cheat::~Cheat()
{

}

void Cheat::SetHealth(float health)
{
	/*
	if (!func.GrantMemoryPermission(hProcess, static_cast<DWORD>(ptr_HEALTH)))
		MessageBox(NULL, L"Couldn't get permissions to modify memory.", L"Error", MB_OK | MB_ICONERROR);*/

	DWORD addr = CPedAddr + ofst_HEALTH;

	func.GrantMemoryPermission(hProcess, addr);

	func.ChangeMemoryValue(addr, hProcess, health);
	
}

void Cheat::SetArmor(float armor)
{
	DWORD addr = CPedAddr + ofst_ARMOR;

	func.GrantMemoryPermission(hProcess, addr);

	//std::cout << std::hex << addr << std::endl;

	func.ChangeMemoryValue(addr, hProcess, armor);
}