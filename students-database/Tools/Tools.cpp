#include "Tools.h"
#include "../Models/Student/Student.h"
#include "../FileInteraction/FileInteraction.h"
#include "../Models/Date/Date.h"
#include <string>
#include <iostream>

#define string List<char>

using namespace std;

string Tools::DateToString(Date date) {
    char day[10 + sizeof(char)];
    char month[10 + sizeof(char)];
    char year[10 + sizeof(char)];
    char editedValue[10 + sizeof(char)] = "0";

    string finalDate;

    sprintf(day, "%d", date.GetDay());
    sprintf(month, "%d", date.GetMonth());
    sprintf(year, "%d", date.GetYear());

    strcat_s(day, ".");
    strcat_s(month, ".");

    strcat_s(editedValue, day);
    finalDate += strlen(day) == 2 ? editedValue : day;
    strcpy_s(editedValue, "0");

    strcat_s(editedValue, month);
    finalDate += strlen(month) == 2 ? editedValue : month;
    strcpy_s(editedValue, "0");

    finalDate += year;

	return finalDate;
}

List<List<string>> Tools::StructToString(List<Student> students) {
    List<List<string>> formattedStudents;

	for (auto& student : students) {
		formattedStudents.add({
			student.GetSurname(),
			student.GetName(),
			student.GetPatronymic(),
			Tools::DateToString(student.BirthData),
			to_string(student.GetAdmissionYear()),
			student.Institute,
			student.Department,
			student.Group,
			student.GetRecordBook(),
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

