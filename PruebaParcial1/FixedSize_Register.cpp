#include "FixedSize_Register.h"

FixedSize_Register::FixedSize_Register()
{
	file = new DataFile();
}

void FixedSize_Register::open_file(char* nombre)
{
	file->abrir(nombre, 0);
}

void FixedSize_Register::close_file()
{
	file->cerrar();
}

char* FixedSize_Register::toChar()
{
	char datos[sizeof(Estructura)];
	Estructura estructura;
	cout << "Codigo: ";
	cin >> estructura.code;
	cout << "Nombre: ";
	cin >> estructura.name;
	cout << "Salario: ";
	cin >> estructura.salary;
	cout << "Job: ";
	cin >> estructura.job;
	cout << sizeof(estructura)<<endl;
	memcpy(datos, &estructura, sizeof(Estructura));
	cout << sizeof(datos);
	return datos;
}

void FixedSize_Register::write_into_file()
{
	char nombre[20];
	cout << "Nombre del archivo: ";
	cin >> nombre;
	char datos[sizeof(Estructura)];
	memcpy(datos, toChar(), sizeof(Estructura));
	open_file(nombre);
	file->escribir(datos, sizeof(Estructura));
	close_file();
}

void FixedSize_Register::read_from_file(int pos)
{
	char nombre[20];
	Estructura estructura;
	char datos[sizeof(Estructura)];
	name = new char[NAMESIZE];
	job = new char[JOBSIZE];
	cout << "Nombre del archivo: ";
	cin >> nombre;
	open_file(nombre);
	//memcpy(datos, (char*)file->leer(pos * sizeof(Estructura), sizeof(Estructura)), sizeof(Estructura));
	fromChar(file->leer(pos * sizeof(Estructura), sizeof(Estructura)));
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

void FixedSize_Register::fromChar(char* datos)
{
	Estructura estru;
	memcpy((&estru), datos, sizeof(Estructura));
	strcpy_s(name, NAMESIZE, estru.name);
	code = estru.code;
	salary = estru.salary;
	strcpy_s(job, JOBSIZE, estru.job);
}

void FixedSize_Register::print_register()
{
	cout << "\nCode: " << code;
	cout << "\nName: " << name;
	cout << "\nSalary: " << salary;
	cout << "\nJob: " << job << endl;

}