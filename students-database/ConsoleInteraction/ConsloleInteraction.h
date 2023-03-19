#include <string>

using namespace std;

class ConsoleInteraction {
	public:
		static void Start();
		static void GetValue(int& value);
		static void GetValue();

	private:
		static string editStudentHandler(int studentId, string value, int param);
};