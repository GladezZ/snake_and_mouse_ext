// Nut.h: UserInterface for the Nut class
//////////////////////////////////////////////////////////////////////
#if !defined(NutH)
#define NutH

#include "MoveableGridItem.h"
#include "constants.h"
#include "RandomNumberGenerator.h"

class Nut :
	public MoveableGridItem
{
public:
	//constructor
	Nut(char symbol);
	//assessors
	bool collected() const;
	//mutators
	void disappears();
	void reappears();
	void Position();
	bool _collected;
	bool escaped();
private:
	static RandomNumberGenerator rng_;
};
#endif	// !defined(NutH)
