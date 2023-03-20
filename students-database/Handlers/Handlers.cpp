#include <iostream>
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include "../Models/Student.h"
#include "Handlers.h"
#include <string>
#include "../ConsoleInteraction/ConsloleInteraction.cpp"

void Handlers::AddStudentHandler() {
	Student newStudent = {};

	cout << "¬ведите фамилию студента\n";
	ConsoleInteraction::GetValue(newStudent.Surname, 1);

	cout << "¬ведите им€ студента\n";
	ConsoleInteraction::GetValue(newStudent.Name);

	cout << "¬ведите отчество студента\n";
	ConsoleInteraction::GetValue(newStudent.Patronymic);

	cout << "¬ведите число рождени€ студента\n";
	ConsoleInteraction::GetValue(newStudent.BirthData.Day);

	cout << "¬ведите мес€ц рождени€ студента (от 1 до 12)\n";
	ConsoleInteraction::GetValue(newStudent.BirthData.Month);

	cout << "¬ведите год рождени€ студента\n";
	ConsoleInteraction::GetValue(newStudent.BirthData.Year);

	cout << "¬ведите год поступлени€ в институт студента\n";
	ConsoleInteraction::GetValue(newStudent.AdmissionYear);

	cout << "¬ведите факультет студента\n";
	ConsoleInteraction::GetValue(newStudent.Institute, 1);

	cout << "¬ведите кафедру студента\n";
	ConsoleInteraction::GetValue(newStudent.Department);

	cout << "¬ведите группу студента\n";
	ConsoleInteraction::GetValue(newStudent.Group);

	cout << "¬ведите номер зачетной книжки студента\n";
	ConsoleInteraction::GetValue(newStudent.RecordBook);

	cout << "¬ведите пол студента („исло, отличное от 0 - мужчина, 0 - женщина)\n";
	ConsoleInteraction::GetValue(newStudent.Gender);

	cout << "¬ведите количество сданных сессий (максимум 9)\n";
	ConsoleInteraction::GetValue(newStudent.SessionCount);

	for (int i = 0; i < newStudent.SessionCount; i++) {
		newStudent.StudentSession[i].Semester = i + 1;
		cout << "¬ведите количество предметов в сессии " << i + 1 << " (максимум 10)\n";
		ConsoleInteraction::GetValue(newStudent.StudentSession[i].SubjectsCount);
		for (int j = 0; j < newStudent.StudentSession[i].SubjectsCount; j++) {
			cout << "¬ведите название " << j + 1 << "-го предмета в " << i + 1 << "-й сессии\n";
			ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Name, 1);
			cout << "¬ведите оценку за " << j + 1 << "-й предмет в " << i + 1 << "-й сессии\n";
			ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Mark);
		}
	}
	FileInteraction::AddStudent({ newStudent });
	ConsoleInteraction::GetValue(newStudent.Surname);
}

void Handlers::EditStudentHandler(int studentId, vector<Student> studentsList, int param) {
	vector<Student> students = FileInteraction::ReadData();


	if (!param) return;

	switch (param) {
	case 1:
		cout << "¬ведите новую фамилию студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Surname, 1);
		break;
	case 2:
		cout << "¬ведите новое им€ студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Name);
		break;
	case 3:
		cout << "¬ведите новое отчество студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Patronymic);
		break;
	case 4:
		cout << "¬ведите новое число рождени€ студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].BirthData.Day);
		break;
	case 5:
		cout << "¬ведите новый мес€ц рождени€ студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].BirthData.Month);
		break;
	case 6:
		cout << "¬ведите новый год рождени€\n";
		ConsoleInteraction::GetValue(studentsList[studentId].BirthData.Year);
		break;
	case 7:
		cout << "¬ведите новое им€ студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Name);
		break;
	case 8:
		cout << "¬ведите новое им€ студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Name);
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13: // Session
		break;
	}

	FileInteraction::EditStudent(studentsList);
}

