#include "Tools.h"
#include "../Models/Student.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Models/Date.h"
#include <vector>
#include <string>

using namespace std;

int Tools::FindStudentByRecordBook(char recordBook[]) {
	vector<Student> students = FileInteraction::ReadData();

	for (int i = 0; i < sizeof(students); i++) {
		if (strcmp(students[i].RecordBook, recordBook)) { return i + 1; };
	}

	return 0;
}


string Tools::DateToString(Date date) {
	return to_string(date.Day) + "." + to_string(date.Month) + "." + to_string(date.Year);
}

vector<vector<string>> Tools::StructToString(vector<Student> students) {
	vector<vector<string>> formattedStudents;

	for (auto student : students) {
		formattedStudents.push_back({
			student.Surname,
			student.Name,
			student.Patronymic,
			Tools::DateToString(student.BirthData),
			to_string(student.AdmissionYear),
			student.Institute,
			student.Department,
			student.Group,
			student.RecordBook,
			student.Gender ? "Ì" : "Æ"
			});
	}

	return formattedStudents;
}