#include <iostream>
#include "Generador.h"
#include <chrono>

using sys_clock = std::chrono::system_clock;
using sys_time = std::chrono::time_point<sys_clock>;

int main()
{
	Generador gen;
	int opcion = 0;
	int numero;
	sys_time start_time;
	sys_time end_time;
	std::chrono::microseconds dur;
	do
	{
		std::cout << "1. Generar Archivo\n2. Busqueda Secuencial \n3. Busqueda Binaria \n4. Salir\n";
		std::cin >> opcion;

		switch (opcion)
		{
		case 1:
			gen.generarLista();
			break;
		case 2:
			std::cout << "Buscar Codigo: ";
			std::cin >> numero;
			start_time = sys_clock::now();
			gen.busquedaSecuencial(numero);
			end_time = sys_clock::now();
			dur = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
			std::cout << "Tiempo tomado: " << static_cast<double>(dur.count()) << "us\n" << std::endl;
			break;
		case 3:
			std::cout << "Bsucar Codigo: ";
			std::cin >> numero;
			start_time = sys_clock::now();
			gen.busquedaBinaria(numero);
			end_time = sys_clock::now();
			dur = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
			std::cout << "Tiempo tomado: " << static_cast<double>(dur.count()) << "us\n" << std::endl;
			break;
		case 4:
			break;
		default: std::cout << "Opcion no existe\n";
		}

	} while (opcion!=4);

	//gen.generarLista();
	//293077
}