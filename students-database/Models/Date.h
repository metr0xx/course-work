#pragma once

struct Date {
	unsigned short int Day;
	unsigned short int Month;
	unsigned short int Year;

    unsigned short int GetDay() {
        return this->Day;
    }

    void SetDay(unsigned short int day) {
        this->Day = day;
    }

    unsigned short int GetMonth() {
        return this->Month;
    }

    void SetMonth(unsigned short int month) {
        this->Month = month;
    }

    unsigned short int GetYear() {
        return this->Year;
    }

    void SetYear(unsigned short int year) {
        this->Year = year;
    }
};