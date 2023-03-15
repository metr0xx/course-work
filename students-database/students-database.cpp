// students-database.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <windows.h>
#include "students-database.h"
#include "FileInteraction.h"
#include "Student.h"
#include <vector>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	/*vector<Subject> subjects = { {"footbal", 5}, {"matan", 4} };
	Student student = { "Aboba", "Testov", "Testovich", {1, 2, 1010},
	1000, "ER", "KB-1", "BASO", "FWJIO43E", 1,{1, subjects} };
	FileInteraction::AddStudent(student);
	vector<vector<string>> students = FileInteraction::ReadData();
	vector<string> columns = { "" };


	for (auto s : students[0]) {
		cout << s << endl;
	}*/
	int command;
	int param;
	string value;
	while (true) {
		cout << "Доступные команды:\n0 - Показать список студентов\n1 - Добавить нового студента\n" << 
			"2 - Редактировать студента\n3 - Удалить студента\n";
		try {
			cin >> command;
		}
		catch (...) {
			cout << "Недействительный номер параметра\n";
		}
		switch (command) {
			case 0:
				//drawTable();
				break;
			case 1:
				break;
			case 2:
				cout << "Введите номер изменяемого параметра\n";
				try {
					cin >> param;
					cout << "Введите значение для параметра\n";
					cin >> value;
					Student::EditStudent(param, value);
				}
				catch (...) {
					cout << "Недействительный номер параметра\n";
				}


		}
	}

	
	return 0;
}
