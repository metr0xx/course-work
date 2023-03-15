#include "Date.h"
#include "Session.h"
#include <vector>
#include <string>

#pragma once

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


	static void EditStudent(int param, string value) {
		switch (param) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12: // Session
			break;
		}
	}
};