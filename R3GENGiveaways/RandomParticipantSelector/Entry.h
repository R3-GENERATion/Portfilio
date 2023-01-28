/**
 * Class:	Entry.h
 * Author:	R3GENSoft
 * Purpose: To hold the information required for an Entry in goal based givaways.
 *			Stay tuned for more R3GENERATion NATion giveaways!
 */

#pragma once
#include <string>
#include <iostream>

class Entry {
	friend class EntryPool;
	Entry* ptr_;

protected:
	std::string name_;
	float seed_;

public:
	/**
	 * Constructor
	 * Parameters:	string representing the Entry's name float seed value for the entry
	 *				to be reorganized by
	 */
	Entry(std::string, float);
	/**
	 * Function:	get_name()
	 * Returns:		string representing the name of the Entry
	 */
	std::string get_name();
	/**
	 * Function:	set_name()
	 * Purpose:		changes the name of the Entry
	 */
	void set_name(std::string);
	/**
	 * Function:	get_next()
	 * Returns:		Entry* returns the Entry this Entry is pointing to
	 */
	Entry* get_next();
	/**
	 * Function:	set_ptr()
	 * Purpose:		Sets the Entry this Entry is pointing to
	 */
	void set_ptr(Entry*);
	/**
	 * Function:	get_seed()
	 * Returns:		float representing the Entry seed
	 */
	float get_seed() { return seed_; }
	/**
	 * Comparison Operators
	 * Returns:		bool comparing each entry by their seed value
	 */
	bool operator<(Entry&);
	bool operator>(Entry&);

	~Entry() {
		if(ptr_ != nullptr) {}
		else { free(ptr_); }
	}
};

std::ostream& operator<< (std::ostream&, Entry&);