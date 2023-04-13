#include "Date.h"
#include <iostream>

using namespace std;

bool Date::CheckDate() {
    bool bigYear = !(this->_year % 4);
    bool wrongDate = false;
    switch (this->_month) {
        case 2:
            if (this->_day > 29) wrongDate = true;
            if (this->_day == 29 && !bigYear) wrongDate = true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (this->_day == 31) wrongDate = true;
    }
    if (wrongDate) cout << "Такой даты не существует\n";

    return !wrongDate;
}

bool Date::SetDay(int day) {
    if (day < 1 || day > 31) {
        cout << "Неверное значение числа месяца\n";
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
        cout << "Неверное значение месяца\n";
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
        cout << "Неверное значение года\n";
        return false;
    };

    this->_year = year;
    return true;
}

int Date::GetYear() {
    return this->_year;
}
