#include <iostream>
#include "ConsloleInteraction.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include <string>
#include "../Handlers/Handlers.h"

using namespace std;

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
            Handlers::DeleteStudentHandler();
            break;
        }
	}
}