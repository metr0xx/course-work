#include "Student.h"
#include <vector>
#include <string>
using namespace std;

class FileInteraction {
	public:
		static vector<vector<string>> ReadData();
		static void AddStudent(Student student);
		static void ChangeStudentData(Student student);
		static void DeleteStudent(string RecordBook);
};