#include <string>
#include <iostream>

using namespace std;

struct ConsoleInteraction {

	static void Start();

	template<typename K>
	static K GetValue(K& value) {
		while (!(cin >> value) || (cin.peek() != '\n'))
		{
			cin.clear();
			while (cin.get() != '\n');
;			cout << "Неверное значение перематра\n";
		}
        return value;
	}

    static void GetValue(char value[], bool afterInt = false) {
        char inputValue[100];

        if (afterInt) {
            getchar();
        }

        while (!gets_s(inputValue, 100)) {
            cout << "Неверное строковое значение\n";
        }

        strcpy(value, inputValue);
    }

};