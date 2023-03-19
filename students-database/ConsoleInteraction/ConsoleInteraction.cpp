#include <iostream>
#include "ConsloleInteraction.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include <string>

using namespace std;

int ConsoleInteraction::GetValue() {
	int value;
	while (!(cin >> value))
	{
		cin.clear(); 
		cin.ignore(1000, '\n');
		cout << "Неверное значение перематра\n";
	}
	return value;
}

string ConsoleInteraction::editStudentHandler(int studentId, string value, int param) {
	string message = "";
	switch (param) {
	case 1:
		cout << "hui";
		FileInteraction::EditStudent(studentId, value, param - 1);
		cout << "Abobaaaaaaaaaaa";
		break;
	case (3, 4, 5):
		break;
	case 6:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13: // Session
		break;
	default:
		return message;
	}
}

void ConsoleInteraction::Start() {
	int command;
	int param;
	int studentId = -1;
	char recordBook[10];
	string value;
	string message;
	while (true) {
		cout << "Доступные команды:\n1 - Показать список студентов\n2 - Добавить нового студента\n" <<
			"3 - Редактировать студента\n4 - Удалить студента\n";
		command = ConsoleInteraction::GetValue();

		vector<Student> students = FileInteraction::ReadData();
		vector<string> studentColumnNames = {"Фамилия", "Имя", "Отчество", "Дата рождения", "Год поступления", 
			"Факультет", "Кафедра", "Группа", "Номер зачетной книжки", "Пол"};
		vector<vector<string>> studentLines = Tools::StructToString(students);
		string studentTitle = "Студент";
		switch (command) {
		case 1:
			for (auto line : studentLines) {
				Table::DrawTable({ line }, studentColumnNames, studentTitle);
			}
			break;
		case 2:
			break;
		case 3:
			//while (studentId < 0) {
			//	cout << "Введите номер зачетной книжки студента\n";
			//	cin >> recordBook;
			//	studentId = FileInteraction::FindStudentByRecordBook(recordBook) - 1;
			//};
			//cout << "Введите номер изменяемого параметра\n" <<
			//	"1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Число рождения\n5 - Месяц роэждения\n6 - Год рождения\n" <<
			//	"7 - Год поступления в институт\n8 - Факультет (институт)\n9 - Кафедра\n10 - Группа\n11 - Номер зачетной книжки\n12 - Пол\n";
			//
			//param = ConsoleInteraction::GetValue();
			//cout << "Введите значение для параметра\n";
			//cin >> value;
			//cout << studentId << endl << value << endl << param << endl;
			//message = ConsoleInteraction::editStudentHandler(studentId, value, param);
			//if (message.length()) {
			//	// неправильно, попробуй еще раз
			//	cout << message;
			//}
			//cout << "Данные успешно изменены\n";
			break;
		case 4:
			break;
		}
	}
}