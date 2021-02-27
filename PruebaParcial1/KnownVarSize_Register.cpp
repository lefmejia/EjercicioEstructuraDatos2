#include "KnownVarSize_Register.h"
#include <stdlib.h>
#include <string.h>
 KnownVarSize_Register::KnownVarSize_Register()
{
	file = new DataFile();
}

void  KnownVarSize_Register::open_file(char* nombre)
{
	file->abrir(nombre, 0);
}

void  KnownVarSize_Register::close_file()
{
	file->cerrar();
}

char*  KnownVarSize_Register::toChar()
{
	char* datos;
	cout << "Codigo: ";
	cin >> code;
	cout << "Cantidad de caracteres en el nombre:\n";
	cin >> sizeName;
	name = new char[sizeName];
	cout << "Nombre: ";
	cin >> name;
	cout << "Salario: ";
	cin >> salary;
	cout << "Cantidad de caracteres en job:\n";
	cin >> sizeJob;
	job = new char[sizeJob];
	cout << "Job: ";
	cin >> job;

	datos = new char[sizeof(int) + sizeof(int) + sizeName + sizeof(double) + sizeof(int) + sizeJob];
	memcpy(datos, &code, sizeof(int));
	memcpy(datos+ sizeof(int), &sizeName, sizeof(int));
	memcpy(datos+ sizeof(int) + sizeof(int), name, sizeName);
	memcpy(datos + sizeof(int) + sizeof(int) + sizeName, &salary, sizeof(double));
	memcpy(datos + sizeof(int) + sizeof(int) + sizeName + sizeof(double), &sizeJob, sizeof(int));
	memcpy(datos + sizeof(int) + sizeof(int) + sizeName + sizeof(double) + sizeof(int), job, sizeJob);
	free(name);
	free(job);
	cout << sizeof(*datos) << endl;
	return datos;
}

void  KnownVarSize_Register::write_into_file()
{
	char nombre[20];
	const int size1 = sizeName;
	const int size2 = sizeJob;
	cout << "Nombre del archivo: ";
	cin >> nombre;
	char* datos = toChar();//new char[sizeof(int) + sizeof(int) + size1 + sizeof(double) + sizeof(int) + size2];
	//memcpy(datos, toChar(), sizeof(int) + sizeof(int) + size1 + sizeof(double) + sizeof(int) + size2);
	open_file(nombre);
	file->escribir(datos, sizeof(int) + sizeof(int) + sizeName + sizeof(double) + sizeof(int) + sizeJob);
	close_file();
}

void  KnownVarSize_Register::read_from_file(int pos)
{
	char nombre[20];
	long readPointer = 0, readSize=0;
	int tamano = 0;
	cout << "Nombre del archivo: ";
	cin >> nombre;
	open_file(nombre);
	//memcpy(datos, (char*)file->leer(pos * sizeof(Estructura), sizeof(Estructura)), sizeof(Estructura));
	for (int i = 0; i < pos; i++)
	{
		readPointer += sizeof(int);
		int* cod = (int*)(file->leer(readPointer, sizeof(int)));
		tamano = cod[0];
		readPointer += sizeof(int) + tamano + sizeof(double);
		cod = (int*)(file->leer(readPointer, sizeof(int)));
		tamano = cod[0];
		readPointer += sizeof(int) + tamano;
	}
	readSize += sizeof(int);
	int* cod = (int*)(file->leer(readSize, sizeof(int)));
	tamano = cod[0];
	readSize += sizeof(int) + tamano + sizeof(double);
	cod = (int*)(file->leer(readSize, sizeof(int)));
	tamano = cod[0];
	readSize += sizeof(int) + tamano;
	fromChar(file->leer(readPointer, readSize));
	/*int* cod= (int*)(file->leer(pos * sizeof(Estructura), sizeof(int)));
	code = cod[0];
	char* jo= (char*)file->leer(pos * sizeof(Estructura) + sizeof(int), JOBSIZE);
	strcpy_s(job, JOBSIZE, jo);
	double* sal = (double*)file->leer(pos * sizeof(Estructura) + sizeof(int) + JOBSIZE, sizeof(double));
	salary = sal[0];
	char* nam = (char*)file->leer(pos * sizeof(Estructura) + sizeof(int) + JOBSIZE + sizeof(double), NAMESIZE);
	strcpy_s(name, NAMESIZE, nam);*/
	close_file();
}

void  KnownVarSize_Register::fromChar(char* datos)
{
	
	memcpy((&code), datos, sizeof(int));
	memcpy(&sizeName, &datos[sizeof(int)], sizeof(int));
	name = new char[sizeName];
	memcpy(name, &datos[sizeof(int)+ sizeof(int)], sizeName);
	memcpy(&salary, &datos[sizeof(int)+ sizeof(int)+sizeName], sizeof(double));
	memcpy(&sizeJob, &datos[sizeof(int)+ sizeof(int)+sizeName+ sizeof(double)], sizeof(int));
	job = new char[sizeJob];
	memcpy(job, &datos[sizeof(int)+ sizeof(int)+sizeName+ sizeof(double)+ sizeof(int)], sizeJob);
}

void  KnownVarSize_Register::print_register()
{
	cout << "\nCode: " << code;
	cout << "\nName: " << name;
	cout << "\nSalary: " << salary;
	cout << "\nJob: " << job << endl;

}