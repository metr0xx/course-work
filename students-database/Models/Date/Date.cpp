#include "Date.h"
#include <iostream>

using namespace std;

string Date::getMonthName() {
    switch (this->_month) {
        case 1:
            return "€нваре";
        case 2:
            return "феврале";
        case 3:
            return "марте";
        case 4:
            return "апреле";
        case 5:
            return "мае";
        case 6:
            return"июне";
        case 7:
            return"июле";
        case 8:
            return "августе";
        case 9:
            return "сент€бре";
        case 10:
            return"окт€бре";
        case 11:
            return "но€бре";
        case 12:
            return "декабре";
    }
    return "";
}

bool Date::CheckDate() {
    bool bigYear = !(this->_year % 4);
    bool feb = false;
    bool wrongDate = false;
    switch (this->_month) {
        case 2:
            if (this->_day > 29) {
                wrongDate = true;
                feb = true;
            }
            if (this->_day == 29 && !bigYear) wrongDate = true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (this->_day == 31) wrongDate = true;
    }
    if (wrongDate) {
        cout << "“акой даты не существует (";
        feb ? bigYear ? cout << "в феврале високосного года всего 29 дней" : cout
                << "в феврале невисокосного года всего 28 дней" : cout << "в " << getMonthName() << " всего 30 дней";
        cout << ")\n";
    }

    return !wrongDate;
}

bool Date::SetDay(int day) {
    if (day < 1 || day > 31) {
        cout << "Ќеверное значение числа мес€ца (требуемый диапазон: от 1 до 31)\n";
        return false;
    };

    this->_day = day;

    return true;
}

int Date::GetDay() {
    return this->_day;
}

bool Date::SetMonth(int month) {
    if (month < 1 || month > 12) {
        cout << "Ќеверное значение мес€ца (требуемый диапазон: от 1 до 12)\n";
        return false;
    };

    this->_month = month;

    return true;
}

int Date::GetMonth() {
    return this->_month;
}

bool Date::SetYear(int year) {
    if (year < 1970 || year > 2023) {
        cout << "Ќеверное значение года (требуемый диапазон: от 1970 до 2023)\n";
        return false;
    };

    this->_year = year;
    return true;
}

int Date::GetYear() {
    return this->_year;
}
