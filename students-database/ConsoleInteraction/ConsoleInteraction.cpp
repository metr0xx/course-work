#include <iostream>
#include "ConsloleInteraction.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include <string>

using namespace std;

void ConsoleInteraction::GetValue(int& value) {
	while (!(cin >> value))
	{
		cin.clear(); 
		cin.ignore(1000, '\n');
		cout << "Неверное значение перематра\n";
	}
}

void ConsoleInteraction::GetValue() {
	
	char value[100];
	while (!(gets_s(value)))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Неверное значение перематра\n";
	}
}

string ConsoleInteraction::editStudentHandler(int studentId, string value, int param) {
	string message = "";
	switch (param) {
	case 1:
		FileInteraction::EditStudent(studentId, value, param - 1);
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
		ConsoleInteraction::GetValue(command);

		vector<Student> students = FileInteraction::ReadData();
		vector<string> studentColumnNames = {"Фамилия", "Имя", "Отчество", "Дата рождения", "Год поступления", 
			"Факультет", "Кафедра", "Группа", "Номер зачетной книжки", "Пол"};
		vector<string> examColumnNames = { "Номер семестра", "Название предмета", "Оценка" };
		vector<vector<string>> studentLines = Tools::StructToString(students);
		vector<vector<string>> subjects;
		vector<vector<string>> examRecords;

		Student newStudent = {};

		int sessionsCount;
		int currSubjectsCount;
		char sur[256];
		//gets_s(sur);
		
		switch (command) {
		case 1:
			for (int i = 0; i < studentLines.size(); i++) {
				Table::DrawTable({ studentLines[i]}, studentColumnNames, "Студент " + to_string(i + 1));
				Tools::StructToString(students[i].StudentSession, subjects);
				Table::DrawTable(subjects, examColumnNames, "Сессии");
				subjects = {};
			}
			break;
		case 2:
			cout << "Type val\n";
			gets_s(sur);
			strcpy_s(newStudent.Name, sur);
			//cout << "Введите фамилию студента\n";

			//ConsoleInteraction::GetValue(sur);
			//strcpy(newStudent.Surname, sur);

			/*cout << "Введите имя студента\n";
			ConsoleInteraction::GetValue(newStudent.Name);

			cout << "Введите отчество студента\n";
			ConsoleInteraction::GetValue(newStudent.Patronymic);

			cout << "Введите число рождения студента\n";
			ConsoleInteraction::GetValue(newStudent.BirthData.Day);

			cout << "Введите месяц рождения студента (от 1 до 12)\n";
			ConsoleInteraction::GetValue(newStudent.BirthData.Month);

			cout << "Введите год рождения студента\n";
			ConsoleInteraction::GetValue(newStudent.BirthData.Year);

			cout << "Введите год поступления в институт студента\n";
			ConsoleInteraction::GetValue(newStudent.AdmissionYear);

			cout << "Введите факультет студента\n";
			ConsoleInteraction::GetValue(newStudent.Institute);

			cout << "Введите кафедру студента\n";
			ConsoleInteraction::GetValue(newStudent.Department);

			cout << "Введите группу студента\n";
			ConsoleInteraction::GetValue(newStudent.Group);

			cout << "Введите номер зачетной книжки студента\n";
			ConsoleInteraction::GetValue(newStudent.RecordBook);

			cout << "Введите пол студента (Число, отличное от 0 - мужчина, 0 - женщина)\n";
			ConsoleInteraction::GetValue(newStudent.Gender);*/

			/*cout << "Введите количество сданных сессий (максимум 9)\n";
			ConsoleInteraction::GetValue(sessionsCount);*/

			/*for (int i = 0; i < sessionsCount; i++) {
				newStudent.StudentSession[i].Semester = i + 1;
				cout << "Введите количество предметов в сессии " << i + 1 << " (максимум 10)\n";
				ConsoleInteraction::GetValue(currSubjectsCount);
				for (int j = 0; j < currSubjectsCount; j++) {
					cout << "Введите название " << j + 1 << "-го предмета в " << i + 1 << "-й сессии\n";
					ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Name);
					cout << "Введите оценку за " << j + 1 << "-й предмет в " << i + 1 << "-й сессии\n";
					ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Mark);*/
				//}
			//}
			FileInteraction::AddStudent({ newStudent });

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