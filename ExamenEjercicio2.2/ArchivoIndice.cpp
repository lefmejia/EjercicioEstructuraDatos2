#include "ArchivoIndice.h"
#include <fstream>
#include <iostream>

void ArchivoIndice::crearIndice(string lastname, long referencia)
{
    fstream indice("indice.bin", ios::out | ios::binary | ios::app);

    if (!indice)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }



}

long ArchivoIndice::getReferencia(string lastname)
{
    fstream indice("indice.bin", ios::out | ios::binary | ios::app);

    if (!indice)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }
}