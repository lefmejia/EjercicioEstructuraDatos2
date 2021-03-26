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


class ArchivoIndice
{
private:
	string llave;
	long referencia;

public:
	void crearIndice(string, long);
	long getReferencia(string);
};


#endif // !ARCHIVOINDICE_H
