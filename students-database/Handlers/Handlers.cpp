#include <iostream>
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include "../Tools/List.cpp"
#include "Handlers.h"
#include <string>
#include "../ConsoleInteraction/ConsloleInteraction.h"

void Handlers::DrawStudentsHandler(List<Student> students) {
	List<string> studentColumnNames = { "Фамилия", "Имя", "Отчество", "Дата рождения", "Год поступления",
	  "Факультет", "Кафедра", "Группа", "Номер зачетной книжки", "Пол" };
    List<string> examColumnNames = { "Номер семестра", "Название предмета", "Оценка" };
    List<List<string>> studentLines = Tools::StructToString(students);
    List<List<string>> subjects;

	for (int i = 0; i < studentLines.size(); i++) {
		Table::DrawTable({ studentLines[i] }, studentColumnNames, "Студент " + to_string(i + 1));
		subjects = Tools::StructToString(students[i]);
		Table::DrawTable(subjects, examColumnNames, "Сессии");
		subjects = {};
	}
}

void Handlers::AddStudentHandler() {
	Student newStudent = {};
	int gender;
	cout << "Введите фамилию студента\n";
	ConsoleInteraction::GetValue(newStudent.Surname, true);

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
	ConsoleInteraction::GetValue(newStudent.Institute, true);

	cout << "Введите кафедру студента\n";
	ConsoleInteraction::GetValue(newStudent.Department);

	cout << "Введите группу студента\n";
	ConsoleInteraction::GetValue(newStudent.Group);

	cout << "Введите номер зачетной книжки студента\n";
	ConsoleInteraction::GetValue(newStudent.RecordBook);

	do {
		cout << "Введите пол студента\n0 - женщина\n1 - мужчина\n2 - небинарная личность\n";

		ConsoleInteraction::GetValue(gender);
		switch (gender) {

		case 0: case 1:
			newStudent.Gender = gender;
			break;
		case 2:
			cout << "Гендера всего 2 :)\n";
			break;
		}
	} while (gender > 1 || gender < 0);

	cout << "Введите количество сданных сессий (максимум 9)\n";
	ConsoleInteraction::GetValue(newStudent.SessionCount);

	for (int i = 0; i < newStudent.SessionCount; i++) {
		newStudent.StudentSession[i].Semester = i + 1;
		cout << "Введите количество предметов в сессии " << i + 1 << " (максимум 10)\n";
		ConsoleInteraction::GetValue(newStudent.StudentSession[i].SubjectsCount);
		for (int j = 0; j < newStudent.StudentSession[i].SubjectsCount; j++) {
			cout << "Введите название " << j + 1 << "-го предмета в " << i + 1 << "-й сессии\n";
			ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Name, true);
			cout << "Введите оценку за " << j + 1 << "-й предмет в " << i + 1 << "-й сессии\n";
			ConsoleInteraction::GetValue(newStudent.StudentSession[i].Subjects[j].Mark);
		}
	}
	FileInteraction::AddStudent({ newStudent });
}

template<typename T>
void Handlers::EditStudentHandler() {
    T value;

    List<Student> studentsList = FileInteraction::ReadData();

	int studentId = -1;
	int param;
	int sessionParam;
	int sessionNumber;
	int prevSubjectsCount;
	int newSubjectsCount;
	int newSessionsCount;
	int sessionEditNumber = 1;
	int subjectEditNumber = 1;
	int subjectEditParam;
	int gender;
	int prevSessionsCount;

	if (!studentsList.size()) {
		cout << "В базе данных нет студентов\n";
		return;
	}
	cout << "Введите номер студента, данные которого нужно изменить\n";
	for (int i = 0; i < studentsList.size(); i++) {
		cout << i + 1 << " - " << studentsList[i].RecordBook << endl;
	}
	cout << "\n0 - В главное меню\n";

	do {
		ConsoleInteraction::GetValue(studentId);
		if (!studentId) return;
		if (studentId < 0 || studentId > studentsList.size()) cout << "Нужно выбрать число от 1 до " << studentsList.size() << endl;
	} while (studentId < 0 || studentId > studentsList.size());

	studentId -= 1;

	cout << "Введите номер изменяемого параметра\n" <<
		"1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Число рождения\n5 - Месяц роэждения\n6 - Год рождения\n" <<
		"7 - Год поступления в институт\n8 - Факультет (институт)\n9 - Кафедра\n10 - Группа\n" << 
		"11 - Номер зачетной книжки\n12 - Пол\n13 - Данные о сессиях\n\n0 - В главное меню\n";
	do {
		ConsoleInteraction::GetValue(param);
		if (param < 0 || param > 13) cout << "Нужно ввести значение от 0 до 13\n";
	} while (param < 0 || param > 13);

	switch (param) {
	case 0:
		break;
	case 1:
		cout << "Введите новую фамилию студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Surname, 1);
		break;
	case 2:
		cout << "Введите новое имя студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Name, 1);
		break;
	case 3:
		cout << "Введите новое отчество студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Patronymic, 1);
		break;
	case 4:
		cout << "Введите число рождения студента\n";
        studentsList[studentId].BirthData.SetDay(ConsoleInteraction::GetValue(value));
        break;
	case 5:
		cout << "Введите месяц рождения студента\n";
        studentsList[studentId].BirthData.SetMonth(ConsoleInteraction::GetValue(value));
        break;
	case 6:
		cout << "Введите год рождения студента\n";
        studentsList[studentId].BirthData.SetYear(ConsoleInteraction::GetValue(value));
		break;
	case 7:
		cout << "Введите год поступления в институт студента\n";
        studentsList[studentId].SetAdmissionYear(ConsoleInteraction::GetValue(value));
		break;
	case 8:
		cout << "Введите факультет студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Institute, 1);
		break;
	case 9:
		cout << "Введите кафедру студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Department, 1);
		break;
	case 10:
		cout << "Введите группу студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].Group, 1);
		break;
	case 11:
		cout << "Введите номер зачетной книжки студента\n";
		ConsoleInteraction::GetValue(studentsList[studentId].RecordBook, 1);
		break;
	case 12:
		do {
			cout << "Введите пол студента\n0 - женщина\n1 - мужчина\n2 - небинарная личность\n";

			ConsoleInteraction::GetValue(gender);
			cout << gender << endl;
			switch (gender) {
				cout << gender << endl;
			case 0: case 1:
				studentsList[studentId].SetGender(gender);
				cout << studentsList[studentId].Gender << endl << gender << endl;
				break;
			case 2:
				cout << "Гендера всего 2 :)\n";
				break;
			} 
		} while (gender > 1 || gender < 0);


		break;
	case 13:
		cout << "Укажите, что нужно изменить в сессиях\n";
		cout << "1 - Добавить сессию\n2 - Изменить сессию\n\n0 - В главное меню\n";
		do {
			ConsoleInteraction::GetValue(sessionParam);
			if (sessionParam != 1 && sessionParam != 2) cout << "Нужно ввести число от 0 до 2\n";
		} while (sessionParam != 1 && sessionParam != 2);

		prevSessionsCount = studentsList[studentId].SessionCount;

		switch (sessionParam)
		{
		case 0:
			break;
		case 1:
			do {
				cout << "Введите количество новых сессий (максимум: " << 9 - prevSessionsCount << ")\n";
				ConsoleInteraction::GetValue(newSessionsCount);
			} while (prevSessionsCount + newSessionsCount > 9);

			for (int i = 0; i < newSessionsCount; i++) {

				sessionNumber = studentsList[studentId].GetSessionCount() + 1;
                studentsList[studentId].SetSessionCount(sessionNumber);
				studentsList[studentId].StudentSession[sessionNumber].SetSemester(sessionNumber + 1);

				do {
					cout << "Введите количество предметов в сессии (максимум 10)\n\n0 - В главное меню\n";
                    studentsList[studentId].StudentSession[sessionNumber].SetSubjectsCount(ConsoleInteraction::GetValue(value));
				} while (studentsList[studentId].StudentSession[sessionNumber].SubjectsCount > 10 ||
					studentsList[studentId].StudentSession[sessionNumber].SubjectsCount < 0);

				for (int i = 0; i < studentsList[studentId].StudentSession[sessionNumber].SubjectsCount; i++) {
					cout << "Введите название " << i + 1 << "-го предмета в сессии\n";
					ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionNumber].Subjects[i].Name, 1);

					cout << "Введите оценку за " << i + 1 << "-й предмет в сессии\n";
                    studentsList[studentId].StudentSession[sessionNumber].Subjects[i].SetMark(ConsoleInteraction::GetValue(value));
				}
			}
			break;
		case 2:
			if (prevSessionsCount > 1) {
				do {
					cout << "Введите номер сессии, данные которой нужно изменить (от 1 до " << prevSessionsCount << ")\n";
					ConsoleInteraction::GetValue(sessionEditNumber);
			} while (sessionEditNumber > prevSessionsCount || sessionEditNumber <= 0);
			}
			cout << "1 - Добавить предмет(ы)\n2 - Изменить данные об имеющемся предмете\n\n0 - В главное меню\n";
			do { 
				ConsoleInteraction::GetValue(subjectEditParam);
				if (subjectEditParam != 1 && subjectEditParam != 2) cout << "Нужно ввести либо 1, либо 2\n";
			} while (subjectEditParam != 1 && subjectEditParam != 2);

			prevSubjectsCount = studentsList[studentId].StudentSession[sessionEditNumber - 1].SubjectsCount;

			switch (subjectEditParam)
			{
			case 0:
				break;
			case 1:
				do {
					cout << "Введите количество новых предметов (максимум: " << 10 - prevSubjectsCount << ")\n";
					ConsoleInteraction::GetValue(newSubjectsCount);
				} while (prevSubjectsCount + newSubjectsCount > 10);

				for (int i = 0; i < newSubjectsCount; i++) {
					cout << "Введите название предмена\n";
					ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[prevSubjectsCount + i].Name, 1);
					cout << "Введите оценку за предмет\n";
                    studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[prevSubjectsCount + i].SetMark(ConsoleInteraction::GetValue(value));
					studentsList[studentId].StudentSession[sessionEditNumber - 1].SetSubjectsCount(studentsList[studentId].StudentSession[sessionEditNumber - 1].GetSubjectsCount() + 1);
				}
				
				break;
			case 2:
				//TODO: draw subjects table
				if (prevSubjectsCount > 1) {
					do {
						cout << "Введите номер предмета, данные которого нужно изменить\n";
						ConsoleInteraction::GetValue(subjectEditNumber);
					} while (subjectEditNumber > prevSubjectsCount || subjectEditNumber < 0);
				}
				
				cout << "1 - Изменить название\n2 - Изменить оценку\n\n0 - В главное меню\n";
				ConsoleInteraction::GetValue(subjectEditParam);
				switch (subjectEditParam)
				{
				case 0:
					break;
				case 1:
					cout << "Введите название предмета под номером " << subjectEditNumber << endl;
					ConsoleInteraction::GetValue(studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[subjectEditNumber - 1].Name, 1);
					break;
				case 2:
					cout << "Введите оценку за предмет " << studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[subjectEditNumber - 1].Name << endl;
                        studentsList[studentId].StudentSession[sessionEditNumber - 1].Subjects[subjectEditNumber - 1].SetMark(ConsoleInteraction::GetValue(value));
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

void Handlers::DeleteStudentHandler() {

    List<Student> students = FileInteraction::ReadData();

	int studentId;

	cout << "Выберете номер студента, которого нужно удалить\n";
	for (int i = 0; i < students.size(); i++) {
		cout << i + 1 << " - " << students[i].RecordBook << endl;
	}
	cout << "\n0 - В главное меню\n";
	do {
		ConsoleInteraction::GetValue(studentId);
		if (!studentId) return;
		if (studentId < 0 || studentId > students.size()) cout << "Нужно выбрать число от 1 до " << students.size() << endl;
	} while (studentId < 0 || studentId > students.size());
	FileInteraction::DeleteStudent(studentId - 1);
}

void Handlers::SortStudentsHandler() {
	bool gender;

    List<Student> students = FileInteraction::ReadData();
    List<Student> goodStudents;
    List<Student> perfectStudents;

	cout << "Введите пол студента\n0 - Женщина\n1 - Мужчина\n";
	do {
		ConsoleInteraction::GetValue(gender);
		if (gender < 0 || gender > 1) cout << "Нужно ввести либо 0, либо 1\n";
	} while (gender < 0 || gender > 1);
	
	Student::SortByGenderAndMarks(gender, students, perfectStudents, goodStudents);
	
	cout << "\nСтуденты с оценками 3, 4 и 5:\n";
	Handlers::DrawStudentsHandler(goodStudents);

	if (perfectStudents.size()) {
		cout << "\nСтуденты с оценками 4 и 5:\n";
		Handlers::DrawStudentsHandler(perfectStudents);
		return;
	}

	cout << "Студентов с оценками 4 и 5 нет\n";
}