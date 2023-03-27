#include <cstdio>
#include <cstring>


#pragma once

using namespace std;

struct Subject {
	char Name[100];
	int Mark;

    char* GetName() {
        return this->Name;
    }

    void SetName(char name[]) {
        strcpy_s(this->Name, name);
    }

    int GetMark() {
        return this->Mark;
    }

    void SetMark(int mark) {
        this->Mark = mark;
    }
};
