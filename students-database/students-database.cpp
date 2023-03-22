// students-database.cpp : Defines the entry point for the application.

#include <windows.h>
#include "./ConsoleInteraction/ConsloleInteraction.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	HWND hWindowConsole = GetConsoleWindow();
	RECT r;
	GetWindowRect(hWindowConsole, &r); 
	MoveWindow(hWindowConsole, r.left, r.top, 1200, 700, TRUE);

	ConsoleInteraction::Start();
}
