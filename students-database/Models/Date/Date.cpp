#include "Date.h"
#include <iostream>

using namespace std;

string Date::getMonthName() {
    switch (this->_month) {
        case 1:
            return "������";
        case 2:
            return "�������";
        case 3:
            return "�����";
        case 4:
            return "������";
        case 5:
            return "���";
        case 6:
            return"����";
        case 7:
            return"����";
        case 8:
            return "�������";
        case 9:
            return "��������";
        case 10:
            return"�������";
        case 11:
            return "������";
        case 12:
            return "�������";
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
        cout << "����� ���� �� ���������� (";
        feb ? bigYear ? cout << "� ������� ����������� ���� ����� 29 ����" : cout
                << "� ������� ������������� ���� ����� 28 ����" : cout << "� " << getMonthName() << " ����� 30 ����";
        cout << ")\n";
    }

    return !wrongDate;
}

bool Date::SetDay(int day) {
    if (day < 1 || day > 31) {
        cout << "�������� �������� ����� ������ (��������� ��������: �� 1 �� 31)\n";
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
        cout << "�������� �������� ������ (��������� ��������: �� 1 �� 12)\n";
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
        cout << "�������� �������� ���� (��������� ��������: �� 1970 �� 2023)\n";
        return false;
    };

    this->_year = year;
    return true;
}

int Date::GetYear() {
    return this->_year;
}
