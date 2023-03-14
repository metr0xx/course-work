#include <vector>
#include <string>

using namespace std;

class Table {
	private:
		void drawBorder(int tableWidth);
		void formatColumn(string str, int maxLen, int tableWidth, bool header = false);
		void drawLine(vector<string> columns, vector<int> params, int tableWidth);
		int getMaxLen(vector<string> names);
	public:
		void drawTable(vector<vector<string>> lines, vector<string> columns, string title, bool shouldDrawBottom = false);
};