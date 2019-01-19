#include "RandomNumberGenerator.h" 


RandomNumberGenerator::RandomNumberGenerator() {
	seed();	//seed the random number generator
}

int RandomNumberGenerator::get_random_value(int max) const {
	return (rand() % max) + 1;
}

void RandomNumberGenerator::seed() {
//seed the random number generator from current system time
//so that the numbers will be different every time
	srand(static_cast<unsigned>(time(0)));
}