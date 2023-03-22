#include <string>

using namespace std;

struct ConsoleInteraction {

	static void Start();

	template<typename T>
	static void GetValue(T& value) {
		while (!(cin >> value))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Неверное значение перематра\n";
		}
	}

	static void ConsoleInteraction::GetValue(char value[], bool afterInt) {
		char inputValue[100];
		if (afterInt) {
			getchar();
		}

		while (!gets_s(inputValue)) {
			cout << "Неверное строковое значение\n";
		}

		strcpy(value, inputValue);
	}
};