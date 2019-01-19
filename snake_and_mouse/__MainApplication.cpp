#include <iostream>		
#include <string>		
#include <sstream>		

using namespace std;

#include "Game.h"
#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"

UserInterface ui;

int main()
{
	string name;
	cout << "Enter your name: ";
	cin >> name;

	//ui.get_PlayingType();

	Player player(name);

	char carry_on;

	do
	{
		Game game(&player);
		game.set_up(&ui);
		game.run();

		cout << "Play again? (Y/N): ";
		cin >> carry_on;

	} while (tolower(carry_on) == 'y');

	ui.hold_window();
	return 0;
}