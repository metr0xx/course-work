#include <iostream>
#include "ConsloleInteraction.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include <string>
#include "../Handlers/Handlers.h"

using namespace std;

void ConsoleInteraction::GetValue(char value[], bool afterInt) {
	char inputValue[100];
	if (afterInt) { 
		getchar();
		strcpy_s(inputValue, "q");
	}
	
	while (!gets_s(inputValue)) {
		cout << "Неверное строковое значение\n";
	}

	strcpy(value, inputValue);
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
        vector<string> studentColumnNames = { "Фамилия", "Имя", "Отчество", "Дата рождения", "Год поступления",
          "Факультет", "Кафедра", "Группа", "Номер зачетной книжки", "Пол" };
        vector<string> examColumnNames = { "Номер семестра", "Название предмета", "Оценка" };
        vector<vector<string>> studentLines = Tools::StructToString(students);
        vector<vector<string>> subjects;
        vector<vector<string>> examRecords;

        Student newStudent = {};

        switch (command) {
        case 1:
            for (int i = 0; i < studentLines.size(); i++) {
                Table::DrawTable({ studentLines[i] }, studentColumnNames, "Студент " + to_string(i + 1));
                Tools::StructToString(students[i].StudentSession, subjects);
                Table::DrawTable(subjects, examColumnNames, "Сессии");
                subjects = {};
            }
            break;
        case 2:
            Handlers::AddStudentHandler();
            break;
        case 3:
            if (!students.size()) {
                cout << "В базе данных нет студентов\n";
                break;
            }
            cout << "Введите номер зачетной книжки студента\n";
            do {
                //ConsoleInteraction::GetValue(recordBook, 1);
                cin >> recordBook;
                studentId = Tools::FindStudentByRecordBook(recordBook);
                if (!studentId) cout << "Студента с таким номером зачетной книжки не найдено\n";
            } while (!studentId);
            cout << studentId - 1;
            cout << "Введите номер изменяемого параметра\n" <<
                "1 - Фамилия\n2 - Имя\n3 - Отчество\n4 - Число рождения\n5 - Месяц роэждения\n6 - Год рождения\n" <<
                "7 - Год поступления в институт\n8 - Факультет (институт)\n9 - Кафедра\n10 - Группа\n11 - Номер зачетной книжки\n12 - Пол\n13 - Данные о сессиях\n";
            do { ConsoleInteraction::GetValue(param); } while (param < 0 || param > 13);
            Handlers::EditStudentHandler(studentId - 1, students, param);
            studentId = -1;

            break;
        case 4:
            cout << "Выберете номер студента, которого нужно удалить\n";
            for (int i = 0; i < students.size(); i++) {
                cout << i + 1 << " - " << students[i].RecordBook << endl;
            }

            do { ConsoleInteraction::GetValue(param); } while (param < 0 || param > students.size());
            FileInteraction::DeleteStudent(param - 1);
            break;
        }
	}
}