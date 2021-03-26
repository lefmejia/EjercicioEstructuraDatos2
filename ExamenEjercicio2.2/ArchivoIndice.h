#pragma once
#ifndef ARCHIVOINDICE_H
#define ARCHIVOINDICE_H

#include <stdio.h>
#include <string>
using namespace std;


struct record
{
	int id;
	char name[30];
	char lastname[30];
	char creditcard[30];
	char date[12];
	short int day;
	short int month;
	short int year;
	char payment_type[10];
	double total;
	char businesstype[20];
	char businessname[50];
};

struct reference
{
	long id;
	char lastname[30];
};


class ArchivoIndice
{
private:
	char llave[30];
	long ref;

public:
	void crearIndice(const char*, long);
	long getReferencia(const char*);
	void leerArchivo();
	void buscarRegistro(const char*);
	void print(record&);
};


#endif // !ARCHIVOINDICE_H
