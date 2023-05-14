#include <iostream>
#include <Windows.h>
#include "game_of_life.h"

using namespace std;

int main() 
{
	game_of_life the_game;

	while(true)
	{
		the_game.iscrtaj();
		the_game.sljedeca_generacija();

		Sleep(1);
		system("cls");	
	}
	
	return 0;
}