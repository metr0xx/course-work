#include <vector>
#include <string>

using namespace std;

class Table {
	private:
		static void drawBorder(int tableWidth);
		static void formatColumn(string str, int maxLen, int tableWidth, bool header = false);
		static void drawLine(vector<string> columns, vector<int> params, int tableWidth);
		static int getMaxLen(vector<string> names);
	public:
		static void DrawTable(vector<vector<string>> lines, vector<string> columns, string title);
};