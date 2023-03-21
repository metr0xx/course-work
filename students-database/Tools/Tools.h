#include <string>
#include <vector>
#include "../Models/Date.h"
#include "../Models/Student.h"
#include "../Models/Session.h"

using namespace std;

struct Tools {
	static int FindStudentByRecordBook(char recordBook[]);
	static string DateToString(Date date);
	static vector<vector<string>> StructToString(vector<Student> students);
	static void StructToString(Student& student, vector<vector<string>>& subjects);
};