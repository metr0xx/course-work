#include "../Student.h"
#include <vector>
#include <string>
using namespace std;

struct FileInteraction {
	static vector<Student> ReadData();
	static void AddStudent(vector <Student> students);
	static void EditStudent(int studentId, string value, int valueId);
	static void DeleteStudent(int studentId);
};