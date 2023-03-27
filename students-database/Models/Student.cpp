#include <iostream>
#include <algorithm>
#include <windows.h>
#include "../Models/Student.h"
#include "../Tools/List.cpp"
using namespace std;

void Student::sortStudentsByAlphabet(List<Student>& students) {
	sort(students.begin(), students.end(), [](Student const s1, Student const s2) -> bool
		{

			for (int i = 0; i < min(strlen(s1.Surname), strlen(s2.Surname)); i++) {
				if(s1.Surname[i] == s2.Surname[i]) continue;
				return s1.Surname[i] < s2.Surname[i];
			}
			return strlen(s1.Surname) < strlen(s2.Surname);
		});

	
}

void Student::SortByGenderAndMarks(bool gender, const List<Student>& students, List<Student>& perfectStudents, List<Student>& goodStudents) {
	bool goodStudent;
	for (auto& student : students) {
		if (student.Gender != gender) continue;
		goodStudent = false;
		for (int i = 0; i < student.SessionCount; i++) {
			if (goodStudent) break;
			for (int j = 0; j < student.StudentSession[i].SubjectsCount; j++) {
				if (student.StudentSession[i].Subjects[j].Mark == 3) {
					goodStudents.add(student);
					goodStudent = true;
					break;
				}
			}
		}

		if(!goodStudent) perfectStudents.add(student);
	}

	Student::sortStudentsByAlphabet(perfectStudents);
	Student::sortStudentsByAlphabet(goodStudents);
}

