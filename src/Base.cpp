#include "Base.h"


Base::Base()
{
}


Base::~Base()
{
}

HANDLE Base::GetHProccess(HWND hWnd)
{
	DWORD proccess_ID;
	GetWindowThreadProcessId(hWnd, &proccess_ID);
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, proccess_ID);
	return hProcess;
}

void Base::ChangeMemoryValue(DWORD addr, HANDLE hProcess, float val)
{
	WriteProcessMemory(hProcess, (LPVOID) addr, &val, sizeof(val), NULL);
}
void Base::ChangeMemoryValue(DWORD addr, HANDLE hProcess, int val)
{
	WriteProcessMemory(hProcess, (LPVOID) addr, &val, sizeof(val), NULL);
}

bool Base::GrantMemoryPermission(HANDLE hProcess, DWORD addr)
{
	if (VirtualProtectEx(hProcess, (LPVOID) addr, 256, PAGE_EXECUTE_READWRITE, NULL) == NULL)
	{
		return false;
	}
	return true;
}

DWORD Base::GetCPedBaseAddr(HANDLE hProcess, DWORD CPedPointerAddr)
{
	GrantMemoryPermission(hProcess, CPedPointerAddr);

	DWORD val;

	//Since CPedPointerAddr is a pointer
	//We have to retrive the value of it which is a memory address
	//We then return that memory address' value.

	ReadProcessMemory(hProcess, (LPCVOID) CPedPointerAddr, &val, sizeof(val), 0);

	return val;
}

HWND Base::GetWindowHandle(HANDLE hProcess, DWORD addr)
{
	GrantMemoryPermission(hProcess, addr);

	HWND handle = NULL;

	ReadProcessMemory(hProcess, (LPCVOID) addr, &handle, sizeof(handle), 0);

	return handle;
}