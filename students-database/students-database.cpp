// students-database.cpp : Defines the entry point for the application.
//
#include <iostream>
#include <windows.h>
#include "./ConsoleInteraction/ConsloleInteraction.h"
#include "Models/Subject.h"
#include "Models/Student.h"
#include "FileInteraction/FileInteraction.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Session session = { 1, { {"footbal", 4} , {"matan", 4}} , 2 };
	vector<Student> student = { {"Aboba", "Testov", "Testovich", {1, 2, 1010},
	1000, "ER", "KB-1", "BASO", "FWJIO43E", 1, session, 1 } };
	FileInteraction::AddStudent(student);
	vector<Student> students = FileInteraction::ReadData();
	/*for (auto s : students) {
		cout << s.RecordBook << endl;
	}*/
	Student s = { "wer" };
	//FileInteraction::AddStudent({ s });
	FileInteraction::DeleteStudent(2);

	ConsoleInteraction::Start();

	return 0;
}
