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
	for (auto &student : students) {
		file.write((char*)&student, sizeof(student));
	}
	file.close();
}

void FileInteraction::EditStudent(int studentId, string value, int valueId) {
	
 }

void FileInteraction::DeleteStudent(int studentId) {
	vector<Student> students = FileInteraction::ReadData();
	students.erase(students.begin() + studentId);
	remove(PATH);
	FileInteraction::AddStudent(students);
}
