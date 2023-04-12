#include "../Date/Date.h"
#include "../Session.h"
#include "../../Tools/List.cpp"
#include <string>
#include <Windows.h>
#include "../../Tools/List.cpp"

#pragma once

using namespace std;

class Student {
    char Surname[100];
    char Name[100];
    char Patronymic[100];
    int AdmissionYear;

    static bool correctName(char value[]);

    static void sortStudentsByAlphabet(List<Student> &students);

public:
    Date BirthData;
    char Institute[100];
    char Department[10];
    char Group[15];
    char RecordBook[10];
    bool Gender;
    Session StudentSession[9];
    int SessionCount;

    bool SetSurname(char surname[]);

    char *GetSurname();

    bool SetName(char name[]);

    char *GetName();

    bool SetPatronymic(char patronymic[]);

    char *GetPatronymic();

    bool SetAdmissionYear(int admissionYear);

    int GetAdmissionYear();

    static void SortByGenderAndMarks(bool gender, const List<Student> &students, List<Student> &perfectStudents,
                                     List<Student> &goodStudents);

};