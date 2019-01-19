#if !defined(UndergroundH)
#define UndergroundH

#include <cassert>
#include <vector>
#include "Hole.h"
using namespace std;

#include "constants.h"

class Underground {

public:
	Underground();
	Hole get_hole_no(int no) const;
	bool is_valid_hole_number(int n) const;
	vector<Hole> holes_;

};

#endif // !defined(UndergroundH) 
