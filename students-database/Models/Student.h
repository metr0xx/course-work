#include "Date.h"
#include "Session.h"
#include "../Tools/List.cpp"
#include <string>
#include <windows.h>

#pragma once

using namespace std;

class Student {
public:
	char Surname[100];
	char Name[100];
	char Patronymic[100];
	Date BirthData;
	unsigned short int AdmissionYear;
	char Institute[100];
	char Department[10];
	char Group[15];
	char RecordBook[10];
	bool Gender;
	Session StudentSession[9];
	int SessionCount;

    char* GetSurname() {
        return this->Surname;
    }

    void SetSurname(char* surname) {
        strcpy_s(this->Surname, surname);
    }

    char* GetName() {
        return this->Name;
    }

    void SetName(char* name) {
        strcpy_s(this->Name, name);
    }

    char* GetPatronymic() {
        return this->Patronymic;
    }

    void SetPatronymic(char* patronymic) {
        strcpy_s(this->Patronymic, patronymic);
    }

    unsigned short int GetAdmissionYear() {
        return this->AdmissionYear;
    }

    void SetAdmissionYear(int admissionYear) {
        this->AdmissionYear = admissionYear;
    }

    char* GetInstitute() {
        return this->Institute;
    }

    void SetInstitute(char* institute) {
        strcpy_s(this->Institute, institute);
    }

    char* GetDepartment() {
        return this->Department;
    }

    void SetDepartment(char* department) {
        strcpy_s(this->Department, department);
    }

    char* GetGroup() {
        return this->Group;
    }

    void SetGroup(char* group) {
        strcpy_s(this->Group, group);
    }

    char* GetRecordBook() {
        return this->RecordBook;
    }

    void SetRecordBook(char* recordBook) {
        strcpy_s(this->RecordBook, recordBook);
    }

    bool GetGender() {
        return this->Gender;
    }

    void SetGender(bool gender) {
        this->Gender = gender;
    }

    int GetSessionCount() {
        return this->SessionCount;
    }

    void SetSessionCount(int sessionCount) {
        this->SessionCount = sessionCount;
    }

	static void SortByGenderAndMarks(bool gender, const List<Student>& students, List<Student>& perfectStudents, List<Student>& goodStudents);

private:
	static void sortStudentsByAlphabet(List<Student>& students);
};