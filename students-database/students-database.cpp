// students-database.cpp : Defines the entry point for the application.

#include <windows.h>
#include "./ConsoleInteraction/ConsloleInteraction.h"

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ConsoleInteraction::Start();
}
