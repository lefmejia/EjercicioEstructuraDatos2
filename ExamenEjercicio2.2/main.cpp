#include <conio.h>
#include "ArchivoIndice.h"
#include <iostream>
int main()
{
	ArchivoIndice AI;
	AI.leerArchivo();
	char* apellido = new char[30];

	std::cout << "Apellido: \n";
	std::cin >> apellido;

	AI.buscarRegistro(apellido);
	cout << "\n";
	_getch();
}