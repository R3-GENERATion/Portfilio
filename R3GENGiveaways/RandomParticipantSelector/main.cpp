/**
 * Program: Random Participant Selector
 * Author:	R3GENSoft
 * Purpose: To select from a pool of participants in the most randomly generated sequence imaginable by R3GEN.
 *			That being said, R3GEN lacks creativity. He would love to hear your input!
 */

#define _CRTDBG_MAP_ALLOC
#include <stdexcept>
#include "PoolBoy.h"
#include "GUI.h"

int main(int argc, char** argv)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::fstream contestList;
	string fileName = "Name";
	//Switch case
	switch (argc) {
	case(1):
		//Too few arguments, no file path provided
		GUI::TopList("No arguments provided, check your input and try again.");
		GUI::BottomList();
		return 1;
	case(2):
		//File path provided
		fileName = argv[1];
		//Check to see if the file path ends in .txt (a text doc)
		if (fileName.substr(fileName.length() - 4) != ".txt") {
			//Not a text doc
			GUI::TopList("Path provided was not a text document.");
			GUI::BottomList();
			return 1;
		}
		//Otherwise it'll open the file path.
		else {
			try {
				contestList.open(fileName);
			}
			catch (exception ex) {
				GUI::TopList(fileName + " does not exist. Check your input and try again.");
			}
		}
		break;
	default:
		//Only one file path expected.
		GUI::TopList("Too many arguments provided, check your input and try again. " + to_string(argc));
		GUI::BottomList();
		return 1;
	}
	//Exits the program if the file is just not opened.
	if (!contestList.is_open()) {
		GUI::TopList("File did not open, exiting program");
		GUI::BottomList();
		return 1;
	}
	//Creates a random number generator
	RNGenerator randGen = RNGenerator::get_instance();
	//Passes the PoolBoy class the list of contests and contestents for the
	//Poolboy to contruct the list and randomize the entries.
	PoolBoy poolmanager(contestList, randGen);
	//Close the file *potentially can corrupt data*
	contestList.close();
	//Selects the winners
	poolmanager.get_winners();
	GUI::TopList("Winners");

	EntryPool* pool = poolmanager.get_pool();
	while (pool != nullptr) {
		//Loops through each pool and displays the winner
		GUI::OutData<EntryPool>(*pool);
		pool = pool->get_next();
	}
	GUI::BottomList();
	return 0;
}