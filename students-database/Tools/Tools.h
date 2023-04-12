#include <vector>
#include "../Models/Date/Date.h"
#include "../Models/Student/Student.h"
#include "../Models/Session.h"
#include "../Tools/List.cpp"

#define string List<char>

using namespace std;

struct Tools {
	static int FindStudentByRecordBook(char recordBook[]);
	static string DateToString(Date date);
	static List<List<string>> StructToString(List<Student> students);
	static List<List<string>> StructToString(Student& student);
};