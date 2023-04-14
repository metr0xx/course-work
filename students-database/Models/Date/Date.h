#pragma once

#include <string>

class Date {
	int _day;
	int _month;
	int _year;

    std::string getMonthName();

public:
    bool CheckDate();

    bool SetDay(int day);

    int GetDay();

    bool SetMonth(int month);

    int GetMonth();

    bool SetYear(int year);

    int GetYear();

};