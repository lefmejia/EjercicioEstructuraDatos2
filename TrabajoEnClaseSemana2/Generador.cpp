#include "Generador.h"
#include <list>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#define randomSize 1000000

using std::ios;
void Generador::generarLista()
{
	srand(time(NULL));
	std::list<Registro> registros;
	//int* numeros = new int[randomSize];
	std::vector<int> numeros;
	std::fstream registro("registros.bin", ios::out | ios::binary);

	if (!registro)
	{
		std::cout << "Error al intentar abrir el arhivo\n";
		return;
	}

	for (int i = 0; i < randomSize; i++)
	{
		numeros.push_back(i + 1);
	}

	for (int i = 999999; i > 0; --i)
	{
		int j = rand() % i;
		int temp = numeros[i];
		numeros[i] = numeros[j];
		numeros[j] = temp;
	}

	for (int i = 0; i < 10000; i++)
	{
		Registro nuevoRegistro;
		nuevoRegistro.codigo = numeros[i];
		std::string str = "empleado_" + std::to_string(numeros[i]);
		strcpy_s(nuevoRegistro.nombre, sizeof(nuevoRegistro.nombre), str.c_str());
		nuevoRegistro.salario = ((double)(rand() % 2100) + 100);
		nuevoRegistro.estado = true;
		registros.push_back(nuevoRegistro);
	}

	registros.sort([](const Registro& a, const Registro& b) { return a.codigo < b.codigo; });

	for (Registro &n: registros)
	{
		registro.write(reinterpret_cast<const char*>(&n), sizeof(Registro));
	}
	std::cout << "Archivo Generado\n";

	registro.close();
}

void Generador::leer()
{
	std::fstream registro("registros.bin", ios::in | ios::binary);
	if (!registro)
	{
		std::cout << "Error al intentar abrir el arhivo\n";
		return;
	}
	Registro nuevo;
	registro.read(reinterpret_cast<char*>(&nuevo), sizeof(Registro));
	int conteo = 0;

	while (!registro.eof())
	{
		std::cout << "Codigo: " << nuevo.codigo << "\n";
		std::cout << "Nombre: " << nuevo.nombre << "\n";
		std::cout << "Salario: " << nuevo.salario << "\n";
		std::cout << "---------------------------" << std::endl;
		conteo++;
		registro.read(reinterpret_cast<char*>(&nuevo), sizeof(Registro));
	}
	std::cout << conteo;

	registro.close();
}

void Generador::busquedaSecuencial(int codigo)
{
	std::fstream registro("registros.bin", ios::in | ios::binary);
	if (!registro)
	{
		std::cout << "Error al intentar abrir el arhivo\n";
		return;
	}
	Registro nuevo;
	registro.read(reinterpret_cast<char*>(&nuevo), sizeof(Registro));

	while (!registro.eof())
	{
		if (nuevo.codigo == codigo)
		{
			std::cout << "Codigo: " << nuevo.codigo << "\n";
			std::cout << "Nombre: " << nuevo.nombre << "\n";
			std::cout << "Salario: " << nuevo.salario << "\n\n";
			registro.close();
			return;
		}
		registro.read(reinterpret_cast<char*>(&nuevo), sizeof(Registro));
	}
	std::cout << "No se encontro registro";
	registro.close();
}	

void Generador::busquedaBinaria(int codigo)
{
	std::fstream registro("registros.bin", ios::in | ios::binary);
	if (!registro)
	{
		std::cout << "Error al intentar abrir el arhivo\n";
		return;
	}
	Registro nuevo;
	int izq = 0;
	int der = 9999;
	while (izq <= der)
	{
		int m = (izq + (der)) / 2;
		registro.seekp((std::streampos)(m) * sizeof(Registro));
		registro.read(reinterpret_cast<char*>(&nuevo), sizeof(Registro));
		if (nuevo.codigo == codigo)
		{
			std::cout << "Codigo: " << nuevo.codigo << "\n";
			std::cout << "Nombre: " << nuevo.nombre << "\n";
			std::cout << "Salario: " << nuevo.salario << "\n\n";
			registro.close();
			return;
		}
		if (nuevo.codigo < codigo)
		{
			izq = m + 1;
		}
		else
		{
			der = m - 1;
		}
	}
	std::cout << "No se encontro registro";
	registro.close();
}