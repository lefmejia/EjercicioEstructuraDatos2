#pragma once
#ifndef GENRERADOR_H
#define GENERADOR_H

struct Registro
{
	int codigo;
	char nombre[20];
	double salario;
	bool estado;
};

class Generador
{
public:
	void generarLista();
	void busquedaSecuencial(int);
	void busquedaBinaria(int);
	void leer();
};

#endif // !GENRERADOR_H
