#pragma once
#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <vector>
#include <list>

using namespace std;

class HashTable
{
public:
	HashTable(int);
	void insertarLlave(int);
	int buscarLlave(int);
	bool eliminarLlave(int);

	void print();
private:
	int tamanio;
	vector<list<int>> tabla;

	//dada la llave genera un valor de direccion para almacenar en la tabla
	int dispersion(int);
};
#endif // !TABLAHASH_H
