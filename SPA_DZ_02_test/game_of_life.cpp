#include "game_of_life.h"
#include <ctime>

using namespace std;

bool game_of_life::slucajna_vrijednost()
{
	return rand() % 4 == 0;
}

bool game_of_life::celija_zauzeta(int i, int j) const
{
	return _generacija[i][j];
}

game_of_life::game_of_life()
{
	srand(time(nullptr));

	for (size_t i = 0; i < REDAKA; i++)
	{
		for (size_t j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

bool game_of_life::gore(int i, int j) const
{
	if (i > 0)
		return _generacija[i - 1][j];

	return false;
}

bool game_of_life::gore_desno(int i, int j) const
{
	if (i > 0 && j < STUPACA-1)
		return _generacija[i - 1][j + 1];

	return false;
}

bool game_of_life::gore_lijevo(int i, int j) const
{
	if (i > 0 && j > 0)
		return _generacija[i - 1][j - 1];

	return false;
}

bool game_of_life::dolje(int i, int j) const
{
	if (i < REDAKA-1)
		return _generacija[i+1][j];

	return false;
}

bool game_of_life::dolje_desno(int i, int j) const
{
	if (i < 19 && j < STUPACA-1)
		return _generacija[i + 1][j + 1];

	return false;
}

bool game_of_life::dolje_lijevo(int i, int j) const
{
	if (i < REDAKA-1 && j > 0)
		return _generacija[i + 1][j - 1];

	return false;
}

bool game_of_life::lijevo(int i, int j) const
{
	if (j > 0)
		return _generacija[i][j - 1];

	return false;
}

bool game_of_life::desno(int i, int j) const
{
	if (j < STUPACA-1)
		return _generacija[i][j + 1];

	return false;
}

int game_of_life::broj_susjeda(int i, int j)
{
	int count = 0;

	if (gore(i, j))
		count++;
	
	if (gore_desno(i, j))
		count++;

	if (gore_lijevo(i, j))
		count++;

	if (dolje(i, j))
		count++;

	if (dolje_desno(i, j))
		count++;

	if (dolje_lijevo(i, j))
		count++;

	if (lijevo(i, j))
		count++;

	if (desno(i, j))
		count++;

	return count;
}


void game_of_life::sljedeca_generacija()
{
	for (size_t i = 0; i < REDAKA; i++)
	{
		for (size_t j = 0; j < STUPACA; j++)
		{
			if (broj_susjeda(i,j) < 2 || broj_susjeda(i, j) > 3)
				_sljedeca_generacija[i][j] = false;

			if (broj_susjeda(i, j) == 3)
				_sljedeca_generacija[i][j] = true;

			if (broj_susjeda(i, j) == 2)
				_sljedeca_generacija[i][j] = _generacija[i][j];
		}
	}

	for (size_t i = 0; i < REDAKA; i++)
	{
		for (size_t j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	cout << endl;
	for (size_t i = 0; i < REDAKA; i++)
	{
		for (size_t j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}

		cout << endl;
	}
}
