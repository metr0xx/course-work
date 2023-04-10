#include <iostream>
#include "ConsloleInteraction.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Table/Table.h"
#include "../Tools/Tools.h"
#include "../Handlers/Handlers.h"

using namespace std;

[[noreturn]] void ConsoleInteraction::Start() {

    int command;

    while (true) {
        cout << "��������� �������:\n1 - �������� ������ ���������\n2 - �������� ������ ��������\n" <<
             "3 - ������������� ��������\n4 - ������� ��������\n5 - �������������� ������� (������� 53)\n";

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
            case 5:
                Handlers::SortStudentsHandler();
                break;

        }
    }
}