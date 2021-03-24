#include "TablaHash.h"
#include <iostream>


HashTable::HashTable(int _tamanio): tamanio(_tamanio)
{
	for (int i = 0; i < _tamanio; i++)
	{
		tabla.push_back(list<int>());
	}
}


//generacion de direccion a partir de la llave
int HashTable::dispersion(int _llave)
{
	return _llave % tamanio;
}

void HashTable::insertarLlave(int _llave)
{
	int direccion = dispersion(_llave);

	if(tabla[direccion].size() >= 6)
	{
		cout << "Error: Lista de Colisiones se ha agotado";
		return;
	}

	tabla[direccion].push_back(_llave);

	cout << "Llave insertada!\n";
}

int HashTable::buscarLlave(int key)
{
	int direccion = dispersion(key);

	for (list<int>::iterator i = tabla[direccion].begin(); i != tabla[direccion].end(); i++)
	{
		if (key == *i)
			return direccion;
	}

	return -1;
}

bool HashTable::eliminarLlave(int key)
{
	int direccion = dispersion(key);

	for (list<int>::iterator i = tabla[direccion].begin(); i != tabla[direccion].end(); i++)
	{
		if (key == *i)
		{
			tabla[direccion].erase(i);
			return true;
		}
	}

	return false;
}

void HashTable::print()
{
	for (int i = 0; i < tamanio; i++)
	{
		cout << "[ " << i << " ] -> ";
		for (list<int>::iterator j = tabla[i].begin(); j != tabla[i].end(); j++)
		{
			cout << *j << " ";
		}
		cout << endl;
	}
}