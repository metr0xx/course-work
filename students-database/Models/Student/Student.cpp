#include <iostream>
#include <algorithm>
#include <Windows.h>
#include "Student.h"

#define string List<char>

using namespace std;

bool Student::correctName(char value[]) {
    string badChars = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

    for (int i = 0; i < strlen(value); i++) {
        if (!badChars.contains(value[i])) return false;
    }
    return true;
}

bool Student::SetSurname(char surname[]) {
    if (correctName(surname)) {
        strcpy_s(this->_surname, surname);
        return true;
    }
    cout << "Недопустимые символы в фамилии\n";
    return false;
}

char *Student::GetSurname() {
    return this->_surname;
}

bool Student::SetName(char name[]) {
    if (correctName(name)) {
        strcpy_s(this->_name, name);
        return true;
    }
    cout << "Недопустимые символы в имени\n";
    return false;
}

char *Student::GetName() {
    return this->_name;
}

bool Student::SetPatronymic(char patronymic[]) {
    if (correctName(patronymic)) {
        strcpy_s(this->_patronymic, patronymic);
        return true;
    }
    cout << "Недопустимые символы в отчестве\n";
    return false;
}

char *Student::GetPatronymic() {
    return this->_patronymic;
}

bool Student::SetAdmissionYear(int admissionYear) {
    if (admissionYear < 1970 || admissionYear > 2023) {
        cout << "Неверное значение года\n";
        return false;
    };
    this->_admissionYear = admissionYear;
    return true;
}

int Student::GetAdmissionYear() const {
    return this->_admissionYear;
}

bool Student::findStudentByRecordBook(char *recordBook, List<Student> students) {

    for (int i = 0; i < students.size(); i++) {
        if (!strcmp(students[i].GetRecordBook(), recordBook)) { return i + 1; };
    }
    return false;
}

bool Student::SetRecordBook(char *recordBook, List<Student> students) {
    if(findStudentByRecordBook(recordBook, students)) {
        cout << "Студент с таким номером зачетной книжки уже существует\n";
        return false;
    }
    strcpy_s(this->_recordBook, recordBook);
    return true;
}

char *Student::GetRecordBook() {
    return this->_recordBook;
}

void Student::sortStudentsByAlphabet(List<Student> &students) {
    sort(students.begin(), students.end(), [](Student const s1, Student const s2) -> bool {

        for (int i = 0; i < min(strlen(s1._surname), strlen(s2._surname)); i++) {
            if (s1._surname[i] == s2._surname[i]) continue;
            return s1._surname[i] < s2._surname[i];
        }
        return strlen(s1._surname) < strlen(s2._surname);
    });


}

void Student::SortByGenderAndMarks(bool gender, const List<Student> &students, List<Student> &perfectStudents,
                                   List<Student> &goodStudents) {
    bool goodStudent;
    for (auto &student: students) {
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

        if (!goodStudent) perfectStudents.add(student);
    }

    Student::sortStudentsByAlphabet(perfectStudents);
    Student::sortStudentsByAlphabet(goodStudents);
}

