#include <iostream>
#include "Table.h"
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void Table::drawBorder(int tableWidth) {
    cout << endl;
    cout.width(tableWidth);
    cout.fill('-');
    cout << '-' << endl;
}

void Table::formatColumn(string str, int maxLen, int tableWidth, bool header) {
    cout << "| " << str;
    header ? cout.width(tableWidth - str.length() - 2) : cout.width(maxLen - str.length() - 2);
    cout.fill(' ');
    cout << " |";
}

void Table::drawLine(vector<string> columns, vector<int> params, int tableWidth) {
    for (int i = 0; i < columns.size(); i++) {
        formatColumn(columns[i], params[i], tableWidth);
    }
}

int Table:: getMaxLen(vector<string> names) {
    int max = 0;
    for (string str : names)
    {
        int len = str.length();
        max = len > max ? len : max;
    }
    return max + 4;
}

void Table::drawTable(vector<vector<string>> lines, vector<string> columns, string title, bool shouldDrawBottom) {

    vector<int> params;
    for (int i = 0; i < columns.size(); i++) {
        vector<string> columnValues = { columns[i] };
        for (int j = 0; j < lines.size(); j++) {
            columnValues.push_back(lines[j][i]);
        }
        params.push_back(getMaxLen(columnValues));
    }

    int tableWidth = accumulate(params.begin(), params.end(), 0);
    drawBorder(tableWidth);
    if (title.length()) {
        formatColumn(title, title.length(), tableWidth, true);
        drawBorder(tableWidth);
    }

    for (int i = 0; i < lines.size() + 1; i++) {
        if (!i) {
            drawLine(columns, params, tableWidth);
            drawBorder(tableWidth);
            continue;
        }

        drawLine(lines[i - 1], params, tableWidth);
        drawBorder(tableWidth);
    }
}