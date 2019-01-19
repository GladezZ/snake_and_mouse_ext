#if !defined(MoveableGridItemH)
#define MoveableGridItemH

#include "GridItem.h"
#include "FixedGridItem.h"
#include "constants.h"

class MoveableGridItem :
	public GridItem
{
public:
	//constructor
	MoveableGridItem(int, int, const char);
	~MoveableGridItem();
	//assessors
	int get_x();
	int get_y();
	bool is_at_position(int, int) const;
	//mutators
	void set_xy(int, int);
	void set_x(int x);
	void set_y(int y);
	void update_position(int, int);

private:
	int _x;
	int _y;
	int _X;
	int _Y;
	//supporting functions
};

#endif // !defined(MoveableGridItemH)
