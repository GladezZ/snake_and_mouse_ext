// Underground.cpp: implementation of the Underground class 
//////////////////////////////////////////////////////////////////////

#include "Underground.h"

//////////////////////////////////////////////////////////////////////

Underground::Underground() : holes_({ Hole(4, 3), Hole(15, 10), Hole(7, 15) })
{
}

Hole Underground::get_hole_no(int no) const {
	assert (is_valid_hole_number(no));	//precondition: valid hole number
	return holes_.at(no);
}

bool Underground::is_valid_hole_number(int no) const {
	return (no >= 0) && (no < holes_.size()); 
}
