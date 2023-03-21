#include <iostream>
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include "../Models/Student.h"
#include "Handlers.h"
#include <string>
#include "../ConsoleInteraction/ConsloleInteraction.h"

void Handlers::AddStudentHandler() {
	Student newStudent = {};

	cout << "Введите фамилию студента\n";
	ConsoleInteraction::GetValue(newStudent.Surname, 1);

	cout << "Введите имя студента\n";
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
	ConsoleInteraction::GetValue(newStudent.Institute, 1);

	cout << "Введите кафедру студента\n";
	ConsoleInteraction::GetValue(newStudent.Department);

	cout << "Введите группу студента\n";
	ConsoleInteraction::GetValue(newStudent.Group);

	cout << "Введите номер зачетной книжки студента\n";
	ConsoleInteraction::GetValue(newStudent.RecordBook);

	cout << "Введите пол студента (Число, отличное от 0 - мужчина, 0 - женщина)\n";
	ConsoleInteraction::GetValue(newStudent.Gender);

	cout << "Введите количество сданных сессий (максимум 9)\n";
	ConsoleInteraction::GetValue(newStudent.SessionCount);

	for (int i = 0; i < newStudent.SessionCount; i++) {
		newStudent.StudentSession[i].Semester = i + 1;
		cout << "Введите количество предметов в сессии " << i + 1 << " (максимум 10)\n";
		ConsoleInteraction::GetValue(newStudent.StudentSession[i].SubjectsCount);
		for (int j = 0; j < newStudent.StudentSession[i].SubjectsCount; j++) {
			cout << "Введите название " << j + 1 << "-го предмета в " << i + 1 << "-й сессии\n";
			ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Name, 1);
			cout << "Введите оценку за " << j + 1 << "-й предмет в " << i + 1 << "-й сессии\n";
			ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Mark);
		}
	}
	FileInteraction::AddStudent({ newStudent });
	ConsoleInteraction::GetValue(newStudent.Surname);
}

void Handlers::EditStudentHandler(int studentId, vector<Student> studentsList, int param) {
	vector<Student> students = FileInteraction::ReadData();

	int sessionParam;
	int sessionNumber;
	int prevSubjectsCount;
	int sessionEditNumber;
	int subjectEditNumber;
	int subjectEditParam;
	if (!param) return;

	switch (param) {
	case 1:
		cout << "Введите новую фамилию студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Surname, 1);
		break;
	case 2:
		cout << "Введите новое имя студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Name);
		break;
	case 3:
		cout << "Введите новое отчество студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Patronymic, 1);
		break;
	case 4:
		cout << "Введите число рождения студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].BirthData.Day);
		break;
	case 5:
		cout << "Введите месяц рождения студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].BirthData.Month);
		break;
	case 6:
		cout << "Введите год рождения студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].BirthData.Year);
		break;
	case 7:
		cout << "Введите год поступления в институт студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].AdmissionYear);
		break;
	case 8:
		cout << "Введите факультет студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Institute);
		break;
	case 9:
		cout << "Введите кафедру студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Department);
		break;
	case 10:
		cout << "Введите группу студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Group);
		break;
	case 11:
		cout << "Введите номер зачетной книжки студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].RecordBook);
		break;
	case 12:
		cout << "Введите пол студента (1 - мужчина, 0 - женщина)\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Institute);
		break;
	case 13:
		cout << "Укажите, что нужно изменить в сессиях\n";
		cout << "1 - Добавить сессию\n2 - Изменить сессию\n";
		do {
			ConsoleInteraction::GetValue(sessionParam);
			if (sessionParam != 1 && sessionParam != 2) cout << "Нужно ввести либо 1, либо 2\n";
		} while (sessionParam != 1 && sessionParam != 2);
		switch (sessionParam)
		{
		case 1:
			if (studentsList[studentId].SessionCount == 9) {
				cout << "Уже имеется максимальное количество сессий (9)\n";
				break;
			}
			sessionNumber = studentsList[studentId].SessionCount++;
			studentsList[studentId].StudentSession[sessionNumber].Semester = sessionNumber + 1;
			cout << "Введите количество предметов в сессии (максимум 10)\n";
			ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionNumber].SubjectsCount);
			for (int i = 0; i < studentsList[studentId].StudentSession[sessionNumber].SubjectsCount; i++) {
				cout << "Введите название " << i + 1 << "-го предмета в сессии\n";
				ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionNumber].Subjects[i].Name, 1);
				cout << "Введите оценку за " << i + 1 << "-й предмет в сессии\n";
				ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionNumber].Subjects[i].Mark);
			}
			break;
		case 2:
			//TODO: draw sessions table
			cout << "Введите номер сессии, данные которой нужно изменить\n";
			ConsoleInteraction::GetValue(sessionEditNumber);
			cout << "1 - Добавить предмет\n2 - Изменить данные об имеющемся предмете\n";
			do { 
				ConsoleInteraction::GetValue(subjectEditNumber);
				if (subjectEditNumber != 1 && subjectEditNumber != 2) cout << "Нужно ввести либо 1, либо 2\n";
			} while (subjectEditNumber != 1 && subjectEditNumber != 2);

			prevSubjectsCount = studentsList[studentId].StudentSession[sessionEditNumber - 1].SubjectsCount;

			switch (subjectEditNumber)
			{
			case 1:
				if (prevSubjectsCount == 10) {
					cout << "Уже имеется максимальное количество предметов в сессии (10)\n";
					break;
				}
				cout << "Введите название предмена\n";
				ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[prevSubjectsCount].Name, 1);
				cout << "Введите оценку за предмет\n";
				ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[prevSubjectsCount].Mark);
				studentsList[studentId].StudentSession[sessionEditNumber - 1].SubjectsCount++;
				break;
			case 2:
				//TODO: draw subjects table
				cout << "Введите номер предмета, данные о котором нужно изменить\n";
				ConsoleInteraction::GetValue(subjectEditNumber);
				cout << "1 - Изменить название\n2 - Изменить оценку\n";
				ConsoleInteraction::GetValue(subjectEditParam);
				switch (subjectEditParam)
				{
				case 1:
					cout << "Введите название предмета под номером " << subjectEditNumber << endl;
					ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[subjectEditNumber - 1].Name, 1);
					break;
				case 2:
					cout << "Введите оценку за предмет " << studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[subjectEditNumber - 1].Name;
					ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[subjectEditNumber - 1].Mark);
					break;
				}
				break;
			}
			break;
		}
		break;
	}

	FileInteraction::EditStudent(studentsList);
}

