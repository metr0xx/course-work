#include <string>
#include <vector>
#include "../Date.h"
#include "../Student.h"
#include "../Session.h"

using namespace std;

struct Tools {
	static int FindStudentByRecordBook(char recordBook[]);
	static string DateToString(Date date);
	static vector<vector<string>> StructToString(vector<Student> students);
	static vector<vector<string>> StructToString(vector<Session> session);
};