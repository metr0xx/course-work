#include "Subject.h"
#include <vector>

#pragma once

struct Session {
	int Semester;
	Subject Subjects[10];
	int SubjectsCount;

    int GetSemester() {
        return this->Semester;
    }

    void SetSemester(int semester) {
        this->Semester = semester;
    }

    int GetSubjectsCount() {
        return this->SubjectsCount;
    }

    void SetSubjectsCount(int subjectsCount) {
        this->SubjectsCount = subjectsCount;
    }
};