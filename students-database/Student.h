#include "Date.h"
#include "Session.h"
#include <vector>
#include <string>

using namespace std;

struct Student {
	string Surname;
	string Name;
	string Patronymic;
	Date BirthData;
	unsigned short int AdmissionYear;
	string Institute;
	string Department;
	string Group;
	string RecordBook;
	bool Gender;
	Session StudentSession;
};