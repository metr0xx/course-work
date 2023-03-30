#pragma once

struct Date {
	int Day;
	int Month;
	int Year;

    int GetDay() {
        return this->Day;
    }

    void SetDay(unsigned short int day) {
        this->Day = day;
    }

    int GetMonth() {
        return this->Month;
    }

    void SetMonth(unsigned short int month) {
        this->Month = month;
    }

    int GetYear() {
        return this->Year;
    }

    void SetYear(unsigned short int year) {
        this->Year = year;
    }
};