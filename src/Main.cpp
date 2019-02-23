#include <iostream>
#include <Windows.h>
#include "Cheat.h"

int main()
{
	//HWND hwnd = FindWindow(NULL, TEXT("GTA:SA:MP"));

	HWND hwnd = FindWindow(NULL, TEXT("GTA: San Andreas"));

	if (hwnd == NULL)
	{
		std::cout << "Couldn't find game. " << GetLastError() << std::endl;
	}
	else
	{
		Cheat cheat(hwnd);

		cheat.SetHealth(50.0f);
		cheat.SetArmor(100.0f);
	}
	std::cin.get();
	return 0;
}