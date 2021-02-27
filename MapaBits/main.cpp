#include <conio.h>
#include <iostream>
#define DB_AMOUNT 100

using namespace std;

void initBitMap(char*);
void printBitMap(char*);
void setOn(char*, int);
void setOn2(char*, int);
void setOff(char*, int);

int main()
{
	char* bitMap;
	//Reserva de memoria para el mapa de bits
	bitMap = new char[DB_AMOUNT / 8];

	initBitMap(bitMap);
	printBitMap(bitMap);
	int numeroBloque;
	cout << "\nNumero de byte a encender: ";
	cin >> numeroBloque;

	setOn2(bitMap, numeroBloque);
	printBitMap(bitMap);
	cout << "\nNumero de bloque a encender: ";
	cin >> numeroBloque;
	setOn(bitMap, numeroBloque);
	printBitMap(bitMap);

	cout << "\nNumero de bloque a apagar: ";
	cin >> numeroBloque;
	setOff(bitMap, numeroBloque);
	printBitMap(bitMap);
	
	_getch();
}

void initBitMap(char* bitMap)
{
	for (int i = 0; i < DB_AMOUNT / 8; i++)
	{
		bitMap[i] = 0;
	}
}

void printBitMap(char* bitMap)
{
	const int SHIFT = 8 * sizeof(char) - 1;
	const char MASK = 1 << SHIFT;

	for (int i = 0; i < DB_AMOUNT / 8; i++)
	{
		char tempByte;
		tempByte = bitMap[i];

		for (int j = 1; j <= SHIFT + 1; j++)
		{
			cout << (tempByte & MASK ? '1' : '0');

			//shift a la izquierda
			tempByte <<=  1;
			if (j % 8 == 0)
			{
				cout << ' ';
			}
		}
	}
	cout << endl;
}

void setOn(char* bitMap, int nBlock)
{
	int posicionByte = nBlock / 8;
	int posicionInicial = (nBlock / 8) * 8;

	for (int i = posicionInicial, x=7; i < (posicionByte * 8) + 8; i++, x--)
	{
		if (i == nBlock)
		{
			bitMap[posicionByte] = bitMap[posicionByte] | (1 << x);
			break;
		}
	}
}

void setOn2(char* bitMap, int nBlock)
{
	int posicionByte = nBlock ;
	int posicionInicial = (nBlock / 8) * 8;

	for (int i = 0; i < (posicionByte * 8) + 8; i++)
	{
		if (i == nBlock)
		{
			for (int j = 0, x = 7; j < 8; j++, x--)
			{
				bitMap[posicionByte] = bitMap[posicionByte] | (1 << x);
			}
			break;
		}
	}
}

void setOff(char* bitMap, int nBlock)
{
	int posicionByte = nBlock / 8;
	int posicionInicial = (nBlock / 8) * 8;

	for (int i = posicionInicial, x = 7; i < (posicionByte * 8) + 8; i++, x--)
	{
		if (i == nBlock)
		{
			bitMap[posicionByte] = bitMap[posicionByte] & ~(1 << x);
			break;
		}
	}
}