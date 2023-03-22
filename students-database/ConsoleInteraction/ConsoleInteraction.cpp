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
      
        vector<vector<string>> examRecords;

        Student newStudent = {};

        switch (command) {
        case 1:
            Handlers::DrawStudentsHandler();
            break;
        case 2:
            Handlers::AddStudentHandler();
            break;
        case 3:   
            Handlers::EditStudentHandler();

            break;
        case 4:
            cout << "Выберете номер студента, которого нужно удалить\n";
            for (int i = 0; i < students.size(); i++) {
                cout << i + 1 << " - " << students[i].RecordBook << endl;
            }
            do { 
                ConsoleInteraction::GetValue(param); 
                if (studentId < 0 || studentId > students.size()) cout << "Нужно выбрать число от 1 до " << students.size() << endl;
            } while (param < 0 || param > students.size());
            FileInteraction::DeleteStudent(param - 1);
            break;
        }
	}
}