#include <string>
#include <vector>
#include "../Models/Date.h"
#include "../Models/Student.h"
#include "../Models/Session.h"
#include "../Tools/List.cpp"

using namespace std;

struct Tools {
	static int FindStudentByRecordBook(char recordBook[]);
	static string DateToString(Date date);
	static List<List<string>> StructToString(List<Student> students);
	static List<List<string>> StructToString(Student& student);
};