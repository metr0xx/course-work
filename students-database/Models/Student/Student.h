#include "../Date/Date.h"
#include "../Session.h"
#include "../../Tools/List.cpp"
#include <string>
#include <Windows.h>
#include "../../Tools/List.cpp"
#include "../Person.h"

#pragma once

using namespace std;

class Student : public Person {
    int _admissionYear;
    char _recordBook[30];

    static bool findStudentByRecordBook(char recordBook[], List<Student> students);

    static bool correctName(char value[]);

    static void sortStudentsByAlphabet(List<Student> &students);

public:
    char Institute[100];
    char Department[20];
    char Group[30];
    Session StudentSession[9];
    int SessionCount;

    bool SetSurname(char surname[]);

    char *GetSurname();

    bool SetName(char name[]);

    char *GetName();

    bool SetPatronymic(char patronymic[]);

    char *GetPatronymic();

    bool SetAdmissionYear(int admissionYear);

    int GetAdmissionYear() const;

    bool SetRecordBook(char recordBook[], List<Student> students);

    char *GetRecordBook();


    static void SortByGenderAndMarks(bool gender, const List<Student> &students, List<Student> &perfectStudents,
                                     List<Student> &goodStudents);

};