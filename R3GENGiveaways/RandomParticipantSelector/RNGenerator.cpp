#include "RNGenerator.h"

using namespace std;

RNGenerator* RNGenerator::Instance = nullptr;

bool RNGenerator::occupied = true;

RNGenerator::RNGenerator() {
	occupied = true;

	chrono::system_clock::time_point MyNowTimePoint = chrono::system_clock::now();
	const long long CurrentSecondsSinceEpoch = chrono::duration_cast<chrono::seconds>(MyNowTimePoint.time_since_epoch()).count();
	const long long CurrentHoursSinceEpoch = chrono::duration_cast<chrono::hours>(MyNowTimePoint.time_since_epoch()).count();
	const long long CurrentMicrosSinceEpoch = chrono::duration_cast<chrono::microseconds>(MyNowTimePoint.time_since_epoch()).count();
	srand(unsigned(CurrentSecondsSinceEpoch * CurrentMicrosSinceEpoch % CurrentHoursSinceEpoch));
	Instance = this;
}

void RNGenerator::clean() {
	free(Instance);
	occupied = false;
}

RNGenerator RNGenerator::get_instance() {
	Instance = 
		Instance != nullptr
		? Instance
		: new RNGenerator();

	occupied = true;
	return *Instance;
}

float RNGenerator::get_float() { return float(rand()) / RAND_MAX; }

int RNGenerator::get_int() { return rand(); }

int RNGenerator::get_int(const int RANGE) { return rand() % RANGE + 1; }

RNGenerator::~RNGenerator() { 
	if(occupied)
		clean();
}