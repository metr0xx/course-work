#include "FileInteraction.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<vector<string>> FileInteraction::ReadData() {
	// каждая строка оттельно в двумерный вектор <string>
	vector<vector<string>> students = {};
	ifstream file;
	string line;
	file.open("C:/StudentsDB/DB.txt");
	int i = -1;
	while (getline(file, line)) {
		if (line == "") continue; 
		if (line == "###") {
			students.push_back({});
			i++;
			continue;
		}
		students[i].push_back(line);
	}
	return students;
}

void FileInteraction::AddStudent(Student student) {
	ofstream file;
	file.open("C:/StudentsDB/DB.txt", ios::app);
	file << "\n###\n" << student.Name << endl << student.Surname << endl << student.Patronymic << endl <<
		student.BirthData.Day << endl << student.BirthData.Month << endl << student.BirthData.Year << endl <<
		student.AdmissionYear << endl << student.Institute << endl << student.Department << endl <<
		student.Group << endl << student.RecordBook << endl << student.Gender << endl <<
		student.StudentSession.Semester << endl;
	for (auto subject : student.StudentSession.Subjects) {
		file << subject.Name << endl << subject.Mark << endl;
	}
	file << "###\n";
	file.close();
}

void FileInteraction::ChangeStudentData(Student student) {
	// ввести цифру студента, которого нужно поменять
	// ввести цифру параметра, который нужно поменять
	// studentVector[student][param]
}

void FileInteraction::DeleteStudent(string recordBook) {

}

// bool проверка, можно ли добавить еще сессию или студента
