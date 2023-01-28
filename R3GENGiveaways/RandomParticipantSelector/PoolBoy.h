#pragma once
#include "EntryPool.h"
#include "RNGenerator.h"
#include <fstream>

class PoolBoy {
	typedef DLinkedList<Entry>::Node		Node;
	typedef DLinkedList<Entry>::Iterator	Iterator;

	EntryPool* contests_;
	RNGenerator randGen_;
	unsigned numOfContests_;

public:
	/**
	 * Constructor
	 * Parameters:	fstream reference and random number generator reference
	 * Purpose		Gives the PoolBoy class the tools it needs to randomize entries and select
	 *				a random entry from that randomized list.
	 */
	PoolBoy(std::fstream&, RNGenerator&);
	/**
	 * Function:	get_pool()
	 * Returns:		EntryPool* the first entry pool the PoolBoy class manages
	 */
	EntryPool* get_pool();
	/**
	 * Function:	get_winners()
	 * Returns:		Entry* the first winner in the first entry pool
	 */
	Entry* get_winners();

	~PoolBoy();
};
