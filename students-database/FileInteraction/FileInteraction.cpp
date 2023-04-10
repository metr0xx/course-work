#include "FileInteraction.h"
#include <fstream>

using namespace std;

const char *PATH = "./DB.bin";

List<Student> FileInteraction::ReadData() {
    ifstream file(PATH, ios::binary);
    Student student;

    List<Student> students;

    for (int i = 0; file.read((char *) &student, sizeof(student)); i++) {
        students.add(student);
    }
    file.close();
    return students;
}

void FileInteraction::AddStudent(List<Student> students) {
    ofstream file(PATH, ios::binary | ios::app);
    for (auto &student: students) {
        file.write((char *) &student, sizeof(student));
    }
    file.close();
}

void FileInteraction::EditStudent(List<Student> students) {
    remove(PATH);
    FileInteraction::AddStudent(students);
}

void FileInteraction::DeleteStudent(int studentId) {
    List<Student> students = FileInteraction::ReadData();
    students.remove(studentId);
    remove(PATH);
    FileInteraction::AddStudent(students);
}
