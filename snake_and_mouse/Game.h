#if !defined(GameH)
#define GameH

#include <string>
#include <iostream>
#include <sstream>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Player.h"

#include "Nut.h"
#include "Tail.h"
#include "FixedGridItem.h"
#include "GridItem.h"
#include "constants.h"

class Game
{
public:
	Game(Player* player);
	void set_up(UserInterface* pui);
	void run();
	bool playingType;
private:
	Underground* ug;
	FixedGridItem fixedgriditem;
	Player* _player;
	string prepare_grid();
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
	UserInterface face;
   	Nut nut_;
	string prepare_end_message();
	int key_;
	bool cheatMode;
	bool cheatModeActive;
	void Cheat_switch();
	void apply_rules();
	void apply_rules_G2();
	bool is_arrow_key_code(int keycode);
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);
	bool tail_position(int const row, int const col);
	bool Nut_Reached_Hole();
	bool nut_in_hole = false;
	
};

#endif 