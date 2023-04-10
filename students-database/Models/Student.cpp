#include <iostream>
#include <algorithm>
#include <windows.h>
#include "../Models/Student.h"
#include "../Tools/List.cpp"

#define string List<char>

using namespace std;

bool Student::correctName(char value[]) {
    string badChars = "0123456789,./|№;:?!@#$%^&*()_+==*-<>`~{}[]";
    for (int i = 0; i < strlen(value); i++) {

        if (badChars.contains(value[i])) return false;
    }
    return true;
}

bool Student::SetSurname(char surname[]) {
    if (correctName(surname)) {
        strcpy_s(this->Surname, surname);
        return true;
    }
    cout << "Недопустимые символы в фамилии\n";
    return false;
}

char *Student::GetSurname() {
    return this->Surname;
}

bool Student::SetName(char name[]) {
    if (correctName(name)) {
        strcpy_s(this->Name, name);
        return true;
    }
    cout << "Недопустимые символы в имени\n";
    return false;
}

char *Student::GetName() {
    return this->Name;
}

bool Student::SetPatronymic(char patronymic[]) {
    if (correctName(patronymic)) {
        strcpy_s(this->Patronymic, patronymic);
        return true;
    }
    cout << "Недопустимые символы в отчестве\n";
    return false;
}

char *Student::GetPatronymic() {
    return this->Patronymic;
}

void Student::sortStudentsByAlphabet(List<Student> &students) {
    sort(students.begin(), students.end(), [](Student const s1, Student const s2) -> bool {

        for (int i = 0; i < min(strlen(s1.Surname), strlen(s2.Surname)); i++) {
            if (s1.Surname[i] == s2.Surname[i]) continue;
            return s1.Surname[i] < s2.Surname[i];
        }
        return strlen(s1.Surname) < strlen(s2.Surname);
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

