#include "Tools.h"
#include "../Models/Student.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Models/Date.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int Tools::FindStudentByRecordBook(char recordBook[]) {
	vector<Student> students = FileInteraction::ReadData();

	for (int i = 0; i < students.size(); i++) {
		if (!strcmp(students[i].RecordBook, recordBook)) { return i + 1; };
	}
	return 0;
}


string Tools::DateToString(Date date) {
	return to_string(date.Day) + "." + to_string(date.Month) + "." + to_string(date.Year);
}

vector<vector<string>> Tools::StructToString(vector<Student> students) {
	vector<vector<string>> formattedStudents;

	for (auto& student : students) {
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

void Tools::StructToString(Student& student, vector<vector<string>>& subjects) {
	for (int i = 0; i < student.SessionCount; i++) {
		for (int j = 0; j < student.StudentSession[i].SubjectsCount; j++ ) {
			subjects.push_back({ to_string(student.StudentSession[i].Semester), 
				student.StudentSession[i].Subjects[j].Name, 
				to_string(student.StudentSession[i].Subjects[j].Mark) });
		}
	}
}

