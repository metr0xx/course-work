#include "../Models/Student.h"
#include "../Tools/List.cpp"
#include <string>
using namespace std;

struct FileInteraction {
	static List<Student> ReadData();
	static void AddStudent(List <Student> students);
	static void EditStudent(List <Student> students);
	static void DeleteStudent(int studentId);
};