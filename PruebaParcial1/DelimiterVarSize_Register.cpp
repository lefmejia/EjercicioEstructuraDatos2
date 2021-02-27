//#include "DelimiterVarSize_Register.h"
//
//DelimiterVarSize_Register::DelimiterVarSize_Register()
//{
//	file = new DataFile();
//	name = new char[NAMESIZE];
//	job = new char[JOBSIZE];
//}
//
//void DelimiterVarSize_Register::open_file(char* nombre)
//{
//	file->abrir(nombre, 0);
//}
//
//void DelimiterVarSize_Register::close_file()
//{
//	file->cerrar();
//}
//
//char* DelimiterVarSize_Register::toChar()
//{
//	char* datos;
//	cout << "Codigo: ";
//	cin >> code;
//	cout << "Nombre: ";
//	cin >> name;
//	cout << "Salario: ";
//	cin >> salary;
//	cout << "Job: ";
//	cin >> job;
//	datos = new char[sizeof(int) + NAMESIZE + sizeof(double) + JOBSIZE + 4];
//	memcpy(datos, &code, sizeof(int));
//	memcpy(datos + sizeof(int), ";", 1);
//	memcpy(datos + sizeof(int) + 1, name, NAMESIZE);
//	memcpy(datos + sizeof(int) + 1 + NAMESIZE, ";", 1);
//	memcpy(datos + sizeof(int) + NAMESIZE + 2, &salary, sizeof(double));
//	memcpy(datos + sizeof(int) + NAMESIZE + 2 + sizeof(double), ";", 1);
//	memcpy(datos + sizeof(int) + NAMESIZE + sizeof(double) + 3, job, JOBSIZE);
//	memcpy(datos + sizeof(int) + NAMESIZE + sizeof(double) + 3 + JOBSIZE, ";", 1);
//	return datos;
//}
//
//void DelimiterVarSize_Register::write_into_file()
//{
//	char nombre[20];
//	cout << "Nombre del archivo: ";
//	cin >> nombre;
//	char* datos = toChar();
//	open_file(nombre);
//	file->escribir(datos, sizeof(int) + NAMESIZE + sizeof(double) + JOBSIZE + 4);
//	close_file();
//}
//
//void DelimiterVarSize_Register::read_from_file(int pos)
//{
//	char nombre[20];
//	char* datos;
//	char* caracter = new char[1];
//	strcpy_s(caracter, 1, " ");
//	long readPointer = -1, readSize = 0, readStart=0;
//	int tamano = 0;
//	cout << "Nombre del archivo: ";
//	cin >> nombre;
//	open_file(nombre);
//	//memcpy(datos, (char*)file->leer(pos * sizeof(Estructura), sizeof(Estructura)), sizeof(Estructura));
//	for (int i = 0; i < pos; i++)
//	{
//		while (strcmp(caracter, ";") != 0)
//		{
//			readPointer++;
//			caracter = (char*)file->leer(readPointer, 1);
//		}
//		readSize = readPointer - 1;
//		readPointer += sizeof(int);
//		int* cod = (int*)(file->leer(readPointer, sizeof(int)));
//		tamano = cod[0];
//		readPointer += sizeof(int) + tamano + sizeof(double);
//		cod = (int*)(file->leer(readPointer, sizeof(int)));
//		tamano = cod[0];
//		readPointer += sizeof(int) + tamano;
//	}
//	readSize += sizeof(int);
//	int* cod = (int*)(file->leer(readSize, sizeof(int)));
//	tamano = cod[0];
//	readSize += sizeof(int) + tamano + sizeof(double);
//	cod = (int*)(file->leer(readSize, sizeof(int)));
//	tamano = cod[0];
//	readSize += sizeof(int) + tamano;
//	fromChar(file->leer(readPointer, readSize));
//	/*int* cod= (int*)(file->leer(pos * sizeof(Estructura), sizeof(int)));
//	code = cod[0];
//	char* jo= (char*)file->leer(pos * sizeof(Estructura) + sizeof(int), JOBSIZE);
//	strcpy_s(job, JOBSIZE, jo);
//	double* sal = (double*)file->leer(pos * sizeof(Estructura) + sizeof(int) + JOBSIZE, sizeof(double));
//	salary = sal[0];
//	char* nam = (char*)file->leer(pos * sizeof(Estructura) + sizeof(int) + JOBSIZE + sizeof(double), NAMESIZE);
//	strcpy_s(name, NAMESIZE, nam);*/
//	close_file();
//}
//
//void DelimiterVarSize_Register::fromChar(char* datos)
//{
//	Estructura estru;
//	memcpy((&estru), datos, sizeof(Estructura));
//	strcpy_s(name, NAMESIZE, estru.name);
//	code = estru.code;
//	salary = estru.salary;
//	strcpy_s(job, JOBSIZE, estru.job);
//}
//
//void DelimiterVarSize_Register::print_register()
//{
//	cout << "\nCode: " << code;
//	cout << "\nName: " << name;
//	cout << "\nSalary: " << salary;
//	cout << "\nJob: " << job << endl;
//
//}