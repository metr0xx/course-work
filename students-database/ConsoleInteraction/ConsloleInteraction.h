#include <string>

using namespace std;

class ConsoleInteraction {
	public:
		static void Start();
		template<typename T>
		static void GetValue(T& value);
		static void GetValue(char value[], bool afterInt = false);

	private:
		static string editStudentHandler(int studentId, string value, int param);
};