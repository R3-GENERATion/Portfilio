/**
 * Class:	RNGenerator.h; Random Number Generator
 * Author:	R3GENSoft
 * Purpose: To incapsulate the process of seeding and producing randomized number output
 */

#pragma once
#include <stdlib.h>
#include <chrono>

class RNGenerator {
private:
	/**
	 * Default Constructor:
	 * Provides a seed for the rand function
	 */
	RNGenerator();
	/**
	 * Function:	clean()
	 * Purpose:		Cleans and sets occupied flag to false
	 */
	static void clean();

	static bool occupied;					//Indicates whether or not the object is active in memory
public:										
	static RNGenerator* Instance;			//Instance of static reference, only one can exist at a time
	/**
	 * Function:	get_instance()
	 * Purpose:		Returns the instance in memory if one is available.
	 *				Creates an instance in memory if one is not available.
	 */
	static RNGenerator get_instance();		
	/**
	 * Function:	get_float()
	 * Purpose:		Returns a randomized float value between 0 and 1
	 */
	float get_float();
	/**
	 * Function:	get_int()
	 * Purpose:		Returns a randomized int value between 0 and RAND_MAX
	 */
	int get_int();
	/**
	 * Function:	get_int(int)
	 * Param:		int; the range of numbers to randomize 
	 * Purpose:		Returns a randomized integer value between 0 and RANGE.
	 */
	int get_int(const int RANGE);

	~RNGenerator(); 
};