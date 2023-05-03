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
    cryptManager.Decrypt();

    while (true) {
        cout << "Äîñòóïíûå êîìàíäû:\n1 - Ïîêàçàòü ñïèñîê ñòóäåíòîâ\n2 - Äîáàâèòü íîâîãî ñòóäåíòà\n" <<
             "3 - Ðåäàêòèðîâàòü ñòóäåíòà\n4 - Óäàëèòü ñòóäåíòà\n5 - Äîïîëíèòåëüíîå çàäàíèå (âàðèàíò 53)\n6 - Âûõîä\n";

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
                cryptManager.Crypt();
                return;
        }
    }
}

template<typename K>
K ConsoleInteraction::GetValue(K &value) {
    while (!(cin >> value) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Íåâåðíîå çíà÷åíèå ïåðåìàòðà\n";
    }
    return value;
}

void ConsoleInteraction::GetValue(char value[], bool afterInt) {
    char inputValue[100];

    if (afterInt) {
        getchar();
    }

    while (!gets_s(inputValue, 100)) {
        cout << "Íåâåðíîå ñòðîêîâîå çíà÷åíèå\n";
    }

    strcpy(value, inputValue);
}
