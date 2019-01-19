#if !defined(HoleH)
#define HoleH

#include <cassert>
#include <vector>

#include "constants.h"
#include "FixedGridItem.h"

using namespace std;

class Hole 
	: public FixedGridItem 
{
public:
	Hole();
	Hole(int x, int y);
};
#endif 
