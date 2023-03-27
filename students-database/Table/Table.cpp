#include <iostream>
#include "Table.h"
#include <string>
#include <windows.h>
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

void Table::drawLine(List<string> columns, List<int> params, int tableWidth) {
    for (int i = 0; i < columns.size(); i++) {
        formatColumn(columns[i], params[i], tableWidth);
    }
}

int Table:: getMaxLen(List<string> names) {
    int max = 0;
    for (string str : names)
    {
        int len = str.length();
        max = len > max ? len : max;
    }
    return max + 4;
}

void Table::DrawTable(List<List<string>> lines, List<string> columns, string title) {

    List<int> params;
    for (int i = 0; i < columns.size(); i++) {
        List<string> columnValues = { columns[i] };
        for (int j = 0; j < lines.size(); j++) {
            columnValues.add(lines[j][i]);
        }
        params.add(getMaxLen(columnValues));
    }

    //int tableWidth = accumulate(params.begin(), params.end(), 0);
    int tableWidth = params.sum();
    HWND hWindowConsole = GetConsoleWindow();
    RECT r;
    GetWindowRect(hWindowConsole, &r);
   
    if (r.right - r.left < tableWidth * 9) {
        MoveWindow(hWindowConsole, r.left, r.top, tableWidth * 9, 700, TRUE);
    }

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