#include "../Models/Student.h"
#include <vector>
#include <string>
using namespace std;

struct FileInteraction {
	static vector<Student> ReadData();
	static void AddStudent(vector <Student> students);
	static void EditStudent(vector <Student> students);
	static void DeleteStudent(int studentId);
};