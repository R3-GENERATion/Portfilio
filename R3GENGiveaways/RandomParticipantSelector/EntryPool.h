/**
 * Class:	EntryPool.h
 * Author:	R3GENSoft
 * Purpose: To manage and manipulate the Entries within the R3GENERATion giveaways!
 *			Stay tuned for more R3GENERATion NATion giveaways!
 */

#pragma once
#include "Entry.h"
#include "List.h"

class EntryPool {
	typedef DLinkedList<Entry>::Node		Node;
	typedef DLinkedList<Entry>::Iterator	Iterator;

	std::string contestName_;
	DLinkedList<Entry>* entries_;
	EntryPool* nextPool_;
	Entry* winner_;
	
public:
	/**
	 * Default Constructor:
	 * Creates a pool with no entries
	 */
	EntryPool();
	/**
	 * Constructor:
	 * Constructs an EntryPool with a contest name and a list of entries.
	 */
	EntryPool(std::string, DLinkedList<Entry>*);
	/**
	 * Function:	get_name()
	 * Returns:		string value representing the entrypool name
	 */
	std::string get_name();
	/**
	 * Function:	get_entries()
	 * Returns:		DLinkedList<Entry>* a list of entries in the pool
	 */
	DLinkedList<Entry>* get_entries();
	/**
	 * Function:	pick_winner()
	 * Parameters:	Int the position of the selection
	 * Purpose:		Selects the winner given a integer value
	 * Returns:		Entry* an entry that may point to another entry winner if more
	 *				than one entry pool is provided in the main.
	 */
	Entry* pick_winner(int pos);
	/**
	 * Function:	get_next()
	 * Returns:		EntryPool* the next entry pool this pool may be pointing to.
	 */
	EntryPool* get_next();
	/**
	 * Function:	assign_next()
	 * Purpose:		Assigns the next pool in the contest list to the next pool variable
	 */
	void assign_next(EntryPool*);
	/**
	 * Function:	get_winner()
	 * Returns:		Entry* the next entry pool this pool may be pointing to.
	 */
	Entry* get_winner();

	~EntryPool() { delete entries_; };
};

std::ostream& operator<<(std::ostream&, EntryPool&);