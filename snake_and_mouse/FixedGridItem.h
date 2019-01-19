#if !defined(FixedGridItemH)
#define FixedGridItemH

#include "GridItem.h"
#include "constants.h"

class FixedGridItem :
	public GridItem
{
public:
	//constructors
	FixedGridItem();
	// x and y need to be const
	FixedGridItem(const int  x, const int  y, char symbol);
	~FixedGridItem();
	//assessors
	int get_x();
	int get_y();
	bool is_at_position(const int, const int);
	//mutators

private:
	//data members
	int const _x ;
	int const _y ;
	//supporting functions
};
#endif // !defined(FixedGridItemH)

