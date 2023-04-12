#include <iostream>
#include "ConsloleInteraction.h"
#include "../FileInteraction/FileInteraction.h"
#include "../CryptManager/CryptManager.cpp"
#include "../Tools/Tools.h"
#include "../Handlers/Handlers.h"

using namespace std;

void ConsoleInteraction::Start() {

    int command;

    CryptManager cryptManager;
    cryptManager.Crypt();

    while (true) {
        cout << "��������� �������:\n1 - �������� ������ ���������\n2 - �������� ������ ��������\n" <<
             "3 - ������������� ��������\n4 - ������� ��������\n5 - �������������� ������� (������� 53)\n6 - �����\n";

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
            case 6:
                cryptManager.Decrypt();
                return;
        }
    }
}