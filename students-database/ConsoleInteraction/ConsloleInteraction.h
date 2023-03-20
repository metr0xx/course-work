#include <string>

using namespace std;

class ConsoleInteraction {
	public:
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

		static void GetValue(char value[], bool afterInt = false);
};