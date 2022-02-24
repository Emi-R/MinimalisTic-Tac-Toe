/* Console Tic Tac Toe por Emiliano Ramirez
* 
* Desafio: hacer un ta te ti 
* usando solo matrices y funciones
* 
*
*/

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

bool validate(int v[][3]);

void drawTablero(int vJ1[][3], int vJ2[][3]);

int main()
{
	setlocale(LC_ALL, "Spanish");

	int tableroJ1[3][3];
	int tableroJ2[3][3];
	int tableroGeneral[3][3];

	bool gameover = false;
	bool ganadorJ1 = false;
	bool ganadorJ2 = false;

	int x = 0;
	int y = 0;

	int i = 0;

	while (gameover == false && i < 9)
	{
		bool used = false;

		cls();
		drawTablero(tableroJ1, tableroJ2);

		cout << endl << "--Jugador 1--" << endl;
		cout << "Ingrese x: ";
		cin >> x;
		cout << "Ingrese y: ";
		cin >> y;

		do
		{
			if (tableroGeneral[x - 1][y - 1] == 1)
			{
				cout << "Casillero ya usado. Ingrese de nuevo" << endl << endl;
				used = true;

				cout << "Ingrese x: ";
				cin >> x;
				cout << "Ingrese y: ";
				cin >> y;
			}
			else
			{
				used = false;
			}

		} while (used == true);

		tableroJ1[x - 1][y - 1] = 1;
		tableroGeneral[x - 1][y - 1] = 1;

		gameover = validate(tableroJ1);

		if (gameover == true)
		{
			ganadorJ1 = true;
		}
		else
		{
			i++;
		}

		used = false;

		if (gameover != true && i < 9)
		{
			cls();

			drawTablero(tableroJ1, tableroJ2);

			cout << endl << "--Jugador 2--" << endl;
			cout << "Ingrese x: ";
			cin >> x;
			cout << "Ingrese y: ";
			cin >> y;

			do
			{

				if (tableroGeneral[x - 1][y - 1] == 1)
				{
					cout << "Casillero ya usado. Ingrese de nuevo" << endl << endl;
					used = true;

					cout << "Ingrese x: ";
					cin >> x;
					cout << "Ingrese y: ";
					cin >> y;
				}
				else
				{
					used = false;
				}

			} while (used == true);

			tableroJ2[x - 1][y - 1] = 1;
			tableroGeneral[x - 1][y - 1] = 1;

			gameover = validate(tableroJ2);

			if (gameover == true)
			{
				ganadorJ2 = true;
			}
			else
			{
				i++;
			}

		}
	}

	cls();
	drawTablero(tableroJ1, tableroJ2);

	if (i == 9)
	{
		cout << endl << "Empate!" << endl;
	}
	else
		if (ganadorJ1 == true)
		{
			cout << endl << endl << "Gana el jugador 1!" << endl;
		}
		else
		{
			cout << endl << endl << "Gana el jugador 2!" << endl;
		}

	return 0;
}

bool validate(int v[][3])
{
	bool state = false;

	if (v[0][0] == 1 && v[0][1] == 1 && v[0][2] == 1)
	{
		state = true;
	}

	if (v[1][0] == 1 && v[1][1] == 1 && v[1][2] == 1)
	{
		state = true;
	}

	if (v[2][0] == 1 && v[2][1] == 1 && v[2][2] == 1)
	{
		state = true;
	}

	if (v[0][0] == 1 && v[1][0] == 1 && v[2][0] == 1)
	{
		state = true;
	}

	if (v[0][1] == 1 && v[1][1] == 1 && v[2][1] == 1)
	{
		state = true;
	}

	if (v[0][2] == 1 && v[1][2] == 1 && v[2][2] == 1)
	{
		state = true;
	}

	if (v[0][0] == 1 && v[1][1] == 1 && v[2][2] == 1)
	{
		state = true;
	}

	if (v[2][0] == 1 && v[1][1] == 1 && v[0][2] == 1)
	{
		state = true;
	}

	return state;
}

void drawTablero(int vJ1[][3], int vJ2[][3])
{
	cout << "    1   2   3" << endl;
	cout << " 1 [ ] [ ] [ ]" << endl;
	cout << " 2 [ ] [ ] [ ]" << endl;
	cout << " 3 [ ] [ ] [ ]" << endl;

	if (vJ1[0][0] == 1)
	{
		locate(5, 2);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[0][1] == 1)
	{
		locate(9, 2);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[0][2] == 1)
	{
		locate(13, 2);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[1][0] == 1)
	{
		locate(5, 3);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[1][1] == 1)
	{
		locate(9, 3);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[1][2] == 1)
	{
		locate(13, 3);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[2][0] == 1)
	{
		locate(5, 4);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[2][1] == 1)
	{
		locate(9, 4);
		cout << "X";
		locate(7, 5);
	}

	if (vJ1[2][2] == 1)
	{
		locate(13, 4);
		cout << "X";
		locate(7, 5);
	}

	if (vJ2[0][0] == 1)
	{
		locate(5, 2);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[0][1] == 1)
	{
		locate(9, 2);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[0][2] == 1)
	{
		locate(13, 2);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[1][0] == 1)
	{
		locate(5, 3);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[1][1] == 1)
	{
		locate(9, 3);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[1][2] == 1)
	{
		locate(13, 3);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[2][0] == 1)
	{
		locate(5, 4);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[2][1] == 1)
	{
		locate(9, 4);
		cout << "O";
		locate(7, 5);
	}

	if (vJ2[2][2] == 1)
	{
		locate(13, 4);
		cout << "O";
		locate(7, 5);
	}
}
