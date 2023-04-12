#pragma once

class Date {
	int Day;
	int Month;
	int Year;

public:
    bool CheckDate();

    bool SetDay(int day);

    int GetDay();

    bool SetMonth(int month);

    int GetMonth();

    bool SetYear(int year);

    int GetYear();

};