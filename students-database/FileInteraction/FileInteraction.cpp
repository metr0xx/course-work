#include "FileInteraction.h"
#include "../Models/Student.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const char* PATH = "C:/StudentsDB/DB.bin";

vector<Student> FileInteraction::ReadData() {
	ifstream file(PATH, ios::binary);
	vector<Student> students;
	Student student;
	for (int i = 0; 
		file.read((char*)&student, sizeof(student)); i++) {
		students.push_back(student);
	}
	file.close();
	return students;
}

void FileInteraction::AddStudent(vector <Student> students) {
	ofstream file(PATH, ios::binary | ios::app);
	for (auto student : students) {
		file.write((char*)&student, sizeof(student));
	}
	file.close();
}

void FileInteraction::EditStudent(int studentId, string value, int valueId) {
	/*vector<vector<string>> students = FileInteraction::ReadData();
	students[studentId][valueId] = value;
	FileInteraction::AddStudent(students);
	cout << "Aboba";*/
 }

void FileInteraction::DeleteStudent(int studentId) {

}

// bool проверка, можно ли добавить еще сессию или студента
