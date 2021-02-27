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
	void busquedaSecuencial2(int);
	void busquedaBinaria2(int);
	void leer();
private:
	int* arreglo = new int[10000];
};

#endif // !GENRERADOR_H
