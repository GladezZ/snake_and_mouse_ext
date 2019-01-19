#include "Game.h"

Game::Game(Player* player):nut_(NUT),snake_(SNAKEHEAD),mouse_(MOUSE), _player(player), cheatMode(false) 
{
	 
}

void Game::set_up(UserInterface* pui) {
	snake_.spot_mouse(&mouse_);
	p_ui = pui;
}

void Game::run() {
	assert(p_ui != nullptr);
	
	while(mouse_.is_at_position(snake_.get_x(), snake_.get_y()) == true)
	{
		mouse_.position_at_random();
	}

	while ((nut_.is_at_position(snake_.get_x(), snake_.get_y()) == true) || (nut_.is_at_position(mouse_.get_x(), mouse_.get_y())))
	{
		nut_.Position();
	}


	p_ui->draw_grid_on_screen(prepare_grid());
	cout << "Player: " << _player->get_name() << endl;
	cout << "Score: " << to_string(_player->get_score_amount()) << endl;

	key_ = p_ui->get_keypress_from_user();

	while (!has_ended(key_))
	{
		if (key_ == 'C')
		{
			cheatModeActive = true;
			Cheat_switch();
		}
		if (is_arrow_key_code(key_))
		{
			mouse_.scamper(key_);
			if (!cheatMode)
			{
				snake_.chase_mouse();
			}
			p_ui->draw_grid_on_screen(prepare_grid());
			if (cheatMode)
			{
				cout << "CHEAT MODE ACTIVATED!!!" << endl;
			}
			cout << "Player: " << _player->get_name() << endl;
			cout << "Score: " << to_string(_player->get_score_amount()) << endl;

			apply_rules();
		}
		key_ = p_ui->get_keypress_from_user();
	}

	p_ui->show_results_on_screen(prepare_end_message());
}

string Game::prepare_grid() {
	//prepare a string that holds the grid information
	ostringstream os;
	for (int row(1); row <= SIZE; ++row)		//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if ((row == snake_.get_y()) && (col == snake_.get_x())) {
				os << snake_.get_symbol();			//show snake
			}					
			else {
				if (tail_position(row, col)){
					os << snake_.tail_.at(0).get_symbol();
				}
					else {
						if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
						{
							os << mouse_.get_symbol();
						}
						else
						{
							if ((row == nut_.get_y() && col == nut_.get_x()) && !nut_.collected()) {
								if (nut_.get_y() <= 19 && nut_.get_x() <= 19) {
									os << nut_.get_symbol();
								}
							}	
							else
							{
								const int hole_no(find_hole_number_at_position(col, row));
								if (hole_no != -1)
									os << underground_.get_hole_no(hole_no).get_symbol();	//show hole
								else
									os << FREECELL;	//show free grid cell
							}
						}
					}
				}
				
			
		} //end of col-loop
		os << endl;
	} //end of row-loop
	return os.str();
} //end prepare_grid

bool Game::is_arrow_key_code(int keycode) {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}

int Game::find_hole_number_at_position(int x, int y) {
	for (int h_no(0); h_no < 3; ++h_no)
		if (underground_.get_hole_no(h_no).is_at_position(x, y))
			return h_no;		//number of the hole
	return -1;				//not a hole
}

void Game::apply_rules() {
	//GAME ONE (COLLECT NUT GAME)
	if (snake_.has_caught_mouse()) {
		mouse_.die();
			if (!cheatModeActive)
			{
				_player->update_score_amount(-1);
			}
		}
	else{
		if (mouse_.is_at_position(nut_.get_x(), nut_.get_y())) {
			//LEFT
			if (mouse_.mouse_dx_ == -1 && mouse_.mouse_dy_ == 0) {
				nut_.set_x(mouse_.get_x() - 1);
			}
			//RIGHT
			if (mouse_.mouse_dx_ == +1 && mouse_.mouse_dy_ == 0) {
				nut_.set_x(mouse_.get_x() + 1);
			}
			//DOWN
			if (mouse_.mouse_dx_ == 0 && mouse_.mouse_dy_ == -1) {
				nut_.set_y(mouse_.get_y() - 1);
			}
			//UP
			if (mouse_.mouse_dx_ == 0 && mouse_.mouse_dy_ == +1) {
				nut_.set_y(mouse_.get_y() + 1);
			}
		}
		if (nut_.get_x() == 4 && nut_.get_y() == 3) {
			Nut_Reached_Hole();
			
		}
		if (nut_.get_x() == 15 && nut_.get_y() == 10) {
			Nut_Reached_Hole();
			
		}
		if (nut_.get_x() == 7 && nut_.get_y() == 15) {
			Nut_Reached_Hole();
		}
		if (nut_in_hole == true){
			if (mouse_.is_at_position(4, 3) || mouse_.is_at_position(15, 10) || mouse_.is_at_position(7, 15)) {
				prepare_end_message();
				mouse_.escape_into_hole();
			}
		}
		if(nut_in_hole == false) {
			//TUNNELS
			if (mouse_.get_x() == 4 && mouse_.get_y() == 3) {
				mouse_.set_xy(7, 15);
			}
			if (mouse_.get_x() == 15 && mouse_.get_y() == 10) {
				mouse_.set_xy(4, 3);
			}
			if (mouse_.get_x() == 7 && mouse_.get_y() == 15) {
				mouse_.set_xy(15, 10);
			}
		}
	 }
}

void Game::apply_rules_G2() {
	if (snake_.has_caught_mouse()) {
		mouse_.die();
		if (!cheatModeActive)
		{
			_player->update_score_amount(-1);
		}
	}
	else {
		if (mouse_.has_reached_a_hole(underground_) && Nut_Reached_Hole())
		{
			mouse_.escape_into_hole();
			if (!cheatModeActive)
			{
				_player->update_score_amount(1);
			}
		}
		else {
			//TUNNELS
			if (mouse_.get_x() == 4 && mouse_.get_y() == 3) {
				mouse_.set_xy(7, 15);
			}
			if (mouse_.get_x() == 15 && mouse_.get_y() == 10) {
				mouse_.set_xy(4, 3);
			}
			if (mouse_.get_x() == 7 && mouse_.get_y() == 15) {
				mouse_.set_xy(15, 10);
			}
		}
	}
}

bool Game::has_ended(char key) {
	return ((key == 'Q') || (!mouse_.is_alive()) || nut_in_hole == true && mouse_.escaped_ == true);
}

string Game::prepare_end_message() {
	ostringstream os;
	if (nut_in_hole == true && mouse_.escaped_ == true)
		os << "\n\nEND OF GAME: MOUSE HAS PUSHED THE NUT TO SAFETY AND ESCAPED!";
	else
		if (!mouse_.is_alive())
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	return os.str();
}

bool Game::tail_position(int const row, int const col)
{
	bool tail_at_pos = false;
	for (int x(0); x < snake_.tail_.size(); x++)
	{
		if ((row == snake_.tail_.at(x).get_y) && (col == snake_.tail_.at(x).get_x))
		{
			tail_at_pos = true;
		}
	}
	return tail_at_pos;
}

void Game::Cheat_switch()
{
	cheatMode = !cheatMode;
}

bool Game::Nut_Reached_Hole() {
	if (nut_.is_at_position(7, 15)) {
		nut_.disappears();
		cout << "\n\nNUT HAS REACHED SAFTEY!" << endl;
		return nut_in_hole = true;
	}
	if (nut_.is_at_position(4, 3)) {
		nut_.disappears();
		cout << "\n\nNUT HAS REACHED SAFTEY!" << endl;
		return nut_in_hole = true;
	}
	if (nut_.is_at_position(15, 10)) {
		nut_.disappears();
		cout << "\n\nNUT HAS REACHED SAFTEY!" << endl;
		return nut_in_hole = true;
	}
else {
		return nut_in_hole = false;
	 }
}
