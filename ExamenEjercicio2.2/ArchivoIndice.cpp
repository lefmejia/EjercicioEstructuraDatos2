#include "ArchivoIndice.h"
#include <fstream>
#include <iostream>

void ArchivoIndice::crearIndice(const char* lastname, long referencia)
{
    fstream indice("indice.bin", ios::out | ios::binary | ios::app);

    if (!indice)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }

    reference refEstructura;

    refEstructura.id = referencia;
    strcpy_s(refEstructura.lastname, sizeof(refEstructura.lastname), lastname);
    indice.write(reinterpret_cast<const char*>(&refEstructura), sizeof(reference));
    indice.close();
}

long ArchivoIndice::getReferencia(const char* lastname)
{
    fstream indice("indice.bin", ios::in | ios::binary);

    if (!indice)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }

    reference refEstructura;
    long pos = 0;
    indice.read(reinterpret_cast<char*>(&refEstructura), sizeof(reference));

    while (!indice.eof())
    {
        if (strcmp(refEstructura.lastname, lastname) == 0)
        {
            return pos;
        }
        pos = indice.tellg();
        indice.read(reinterpret_cast<char*>(&refEstructura), sizeof(reference));
    }


    indice.close();
}

void ArchivoIndice::leerArchivo() 
{
    ifstream archivo("archivo.bin", ios::in | ios::binary);

    if (!archivo)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }

    record registro;
    long pos = 0;
    archivo.read(reinterpret_cast<char*>(&registro), sizeof(record));

    while (!archivo.eof())
    {
        crearIndice(registro.lastname, pos);
        pos = archivo.tellg();
        archivo.read(reinterpret_cast<char*>(&registro), sizeof(record));
    }

    archivo.close();
}

void ArchivoIndice::buscarRegistro(const char* lastname)
{
    ifstream archivo("archivo.bin", ios::in | ios::binary);

    if (!archivo)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }

    record registro;
    archivo.seekg(getReferencia(lastname));
    archivo.read(reinterpret_cast<char*>(&registro), sizeof(record));

    print(registro);
    archivo.close();
}

void ArchivoIndice::print(record& registro)
{
    cout<< "ID: "<< registro.id<<endl;
    cout<< "last name: "<< registro.lastname <<endl;
    cout<< "credit card: "<< registro.creditcard <<endl;
    cout<< "date: "<< registro.date <<endl;
    cout<< "day: "<< registro.day <<endl;
    cout<< "month: "<< registro.month <<endl;
    cout<< "year: "<< registro.year <<endl;
    cout<< "payment type: "<< registro.payment_type <<endl;
    cout<< "total: "<< registro.total <<endl;
    cout<< "business type: "<< registro.businesstype <<endl;
    cout<< "business name: "<< registro.businessname <<endl;
}