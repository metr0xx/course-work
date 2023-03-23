#include "Date.h"
#include "Session.h"
#include <vector>
#include <string>

#pragma once

using namespace std;

class Student {
public:
	char Surname[100];
	char Name[100];
	char Patronymic[100];
	Date BirthData;
	unsigned short int AdmissionYear;
	char Institute[100];
	char Department[10];
	char Group[15];
	char RecordBook[10];
	bool Gender;
	Session StudentSession[9];
	int SessionCount;

	static void SortByGenderAndMarks(bool gender, vector<Student> students, vector<Student>& perfectStudents, vector<Student>& goodStudents);

private:
	static void sortStudentsByAlphabet(vector<Student>& students);
};