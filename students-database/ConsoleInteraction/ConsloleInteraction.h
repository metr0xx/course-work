#include <string>

using namespace std;

class ConsoleInteraction {
	public:
		static void Start();
		static int GetValue();
	private:
		static string editStudentHandler(int studentId, string value, int param);
};