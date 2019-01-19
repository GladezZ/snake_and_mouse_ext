#include "UserInterface.h" 
#include <conio.h>		


int UserInterface::get_keypress_from_user() const {
//get key or command selected by user
	//read in the selected arrow key or command letter
	int key_pressed(_getch());
	//ignore symbol following cursor key
	while (key_pressed == 224) 
		key_pressed = _getch();
	//return the key in uppercase
	return(toupper(key_pressed));
}

void UserInterface::draw_grid_on_screen(const string& grid_data) const  {
	system("cls"); 
	cout << grid_data;
}

void UserInterface::show_results_on_screen(string message) const {
	cout << message;
}

void UserInterface::hold_window() const{
	cout << "\n\n";
	system("pause");
}

string UserInterface::Get_Name() {
	string name;
	cout << "Enter your name: ";
	cin >> name;
	return name;
}

bool UserInterface::get_PlayingType() {
	int option = 0;
	cout << "1 - Grab the nut and escape" << endl;
	cout << "2 - Pushable nut game" << endl;
	cout << "Which game mode would you like to play: " << endl;
	cin >> option;
	switch (option) {
	case 1: {
		return playing_Type = true;
	}
	case 2: {
		return playing_Type = false;
	}
	}
}