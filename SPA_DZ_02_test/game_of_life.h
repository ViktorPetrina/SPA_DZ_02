#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class game_of_life 
{
private:
	static const unsigned int STUPACA = 50;
	static const unsigned int REDAKA = 25;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j) const;
	
	bool gore(int i, int j) const;
	bool gore_desno(int i, int j) const;
	bool gore_lijevo(int i, int j) const;
	bool dolje(int i, int j) const;
	bool dolje_desno(int i, int j) const;
	bool dolje_lijevo(int i, int j) const;
	bool lijevo(int i, int j) const;
	bool desno(int i, int j) const;
	int broj_susjeda(int i, int j);

public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
