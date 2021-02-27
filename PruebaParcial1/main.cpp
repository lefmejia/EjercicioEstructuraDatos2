#include <iostream>
#include <conio.h>
#include "FixedSize_Register.h"
#include "KnownVarSize_Register.h"

void knownSize()
{
	int opcion = 0;
	KnownVarSize_Register ksr;
	do
	{
		cout << "1. Escribir\n2. Leer\n3. Imprimir\n4. Salir\n";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			ksr.write_into_file();
			break;
		case 2:
			int pos;
			cout << "Que posicion de registro?\n";
			cin >> pos;
			ksr.read_from_file(pos);
			break;
		case 3:
			ksr.print_register();
		default:
			break;
		}
	} while (opcion != 4);
}

void fixedSize()
{
	int opcion = 0;
	FixedSize_Register fsr;
	do
	{
		cout << "1. Escribir\n2. Leer\n3. Imprimir\n4. Salir\n";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			fsr.write_into_file();
			break;
		case 2:
			int pos;
			cout << "Que posicion de registro?\n";
			cin >> pos;
			fsr.read_from_file(pos);
			break;
		case 3:
			fsr.print_register();
		default:
			break;
		}
	} while (opcion != 4);
}

int main()
{
	int opcion = 0;

	do 
	{
		cout << "1. Fixed Size register\n2.Known Size register\n3. salir\n";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			fixedSize();
			break;
		case 2:
			knownSize();
			break;
		default:
			break;
		}
	} while (opcion != 3);
}