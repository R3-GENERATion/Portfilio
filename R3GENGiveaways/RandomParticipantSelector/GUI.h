#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>


using namespace std;

/**
 * Class:	GUI
 * Purpose:	Contains static functions to format the data output in a friendly manner.
 */
class GUI {

	static const int MAX = 100;
	static const char hLine = '|';
	static const char vLine = '-';
	static const char ltCorner = '+';
	static const char rtCorner = '+';
	static const char lbCorner = '+';
	static const char rbCorner = '+';

public:
	/**
	 * Function:	OutData()
	 * Purpose:		Output the data in the middle of the table the console will print with
	 *				the max length of MAX
	 */
	template<typename data_t>
	static void OutData(data_t& data) {
		ostringstream oss;
		oss << data;
		unsigned leftSpacing = MAX / 2 + oss.str().length() / 2;
		unsigned rightSpacing = MAX / 2 - oss.str().length() / 2;
		cout << hLine << setw(leftSpacing) << oss.str() << setw(rightSpacing) << hLine << endl;
	}
	/**
	 * Function:	TopList()
	 * Purpose:		Output the title of the data list
	 */
	static void TopList(string title) {
		unsigned leftSpacing = MAX / 2 + title.length() / 2;
		unsigned rightSpacing = MAX / 2 - title.length() / 2;
		cout << ltCorner << setw(MAX) << setfill(vLine) << rtCorner << endl;
		cout << hLine << setw(leftSpacing) << setfill(' ') << title << setw(rightSpacing) << hLine << endl;
	}
	/**
	 * Function:	BottomList()
	 * Purpose:		Output the bottom line of the table presenting the list
	 */
	static void BottomList() {
		cout << lbCorner << setw(MAX) << setfill(vLine) << rbCorner << endl;
	}
};