#include "Date.h"
#include <iostream>

using namespace std;

bool Date::CheckDate() {
    bool bigYear = !(this->Year % 4);
    bool wrongDate = false;
    switch (this->Month) {
        case 2:
            if (this->Day > 29) wrongDate = true;
            if (this->Day == 29 && !bigYear) wrongDate = true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (this->Day == 31) wrongDate = true;
    }
    if (wrongDate) cout << "Такой даты не существует\n";

    return !wrongDate;
}

bool Date::SetDay(int day) {
    if (day < 1 || day > 31) {
        cout << "Неверное значение числа месяца\n";
        return false;
    };

    this->Day = day;

    return true;
}

int Date::GetDay() {
    return this->Day;
}

bool Date::SetMonth(int month) {
    if (month < 1 || month > 12) {
        cout << "Неверное значение месяца\n";
        return false;
    };

    this->Month = month;

    return true;
}

int Date::GetMonth() {
    return this->Month;
}

bool Date::SetYear(int year) {
    if (year < 1970 || year > 2023) {
        cout << "Неверное значение года\n";
        return false;
    };

    this->Year = year;
    return true;
}

int Date::GetYear() {
    return this->Year;
}
