#include <conio.h>
#include "TablaHash.h"
#include <iostream>
int main()
{
	HashTable ht(10);

	ht.insertarLlave(21);
	ht.insertarLlave(14);
	ht.insertarLlave(83);
	ht.insertarLlave(22);
	ht.insertarLlave(93);
	ht.insertarLlave(56);
	ht.insertarLlave(2);
	ht.insertarLlave(12);
	ht.insertarLlave(9);
	ht.insertarLlave(15);

	ht.print();
	ht.eliminarLlave(2);
	ht.print();

	int posicion = ht.buscarLlave(56);
	if (posicion != -1)
	{
		cout << "la llave 56 se encuentra en la posicion " << posicion << endl;
	}
	else
		cout << "no se encontro la llave\n";

	_getch();
}