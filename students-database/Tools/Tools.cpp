#include "Tools.h"
#include "../Models/Student.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Models/Date.h"
#include <string>
#include <iostream>

#define string List<char>

using namespace std;

int Tools::FindStudentByRecordBook(char recordBook[]) {
    List<Student> students = FileInteraction::ReadData();

	for (int i = 0; i < students.size(); i++) {
		if (!strcmp(students[i].RecordBook, recordBook)) { return i + 1; };
	}
	return 0;
}


string Tools::DateToString(Date date) {
    char day[10 + sizeof(char)];
    char month[10 + sizeof(char)];
    char year[10 + sizeof(char)];

    sprintf(day, "%hu", date.Day);
    sprintf(month, "%hu", date.Month);
    sprintf(year, "%hu", date.Year);

    strcat_s(day, ".");
    strcat_s(month, ".");

    string finalDate;

    finalDate += day;
    finalDate += month;
    finalDate += year;

	return finalDate;
}

List<List<string>> Tools::StructToString(List<Student> students) {
    List<List<string>> formattedStudents;

	for (auto& student : students) {
		formattedStudents.add({
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

List<List<string>> Tools::StructToString(Student& student) {
    List<List<string>> subjects = *new List<List<string>>;
	for (int i = 0; i < student.SessionCount; i++) {
		for (int j = 0; j < student.StudentSession[i].SubjectsCount; j++ ) {
			subjects.add({ to_string(student.StudentSession[i].Semester),
				student.StudentSession[i].Subjects[j].Name,
				to_string(student.StudentSession[i].Subjects[j].Mark) });
		}
	}
    return subjects;
}

