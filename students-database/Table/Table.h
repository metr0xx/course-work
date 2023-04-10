#include <vector>
#include "../Tools/List.cpp"

#define string List<char>

#pragma once

using namespace std;

class Table {
    static void drawBorder(int tableWidth);

    static void formatColumn(string str, int maxLen, int tableWidth, bool header = false);

    static void drawLine(List<string > columns, List<int> params, int tableWidth);

    static int getMaxLen(List<string > names);

public:
    static void DrawTable(List<List<string>> lines, List<string > columns, string title);
};
