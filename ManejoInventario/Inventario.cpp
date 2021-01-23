#include "Inventario.h"
#include <fstream>
#include <iostream>

using namespace std;

void Inventario::agregarProducto()
{
    fstream archivoProductos("productos.bin", ios::out | ios::binary | ios::app);

    if (!archivoProductos)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }

    cout << "*** I N G R E S O  D E  P R O D U C T O S ***" << endl;
    cout << "Ingrese cantidad de Producto a agregar: ";
    int cant;
    cin >> cant;

    producto nuevo;

    for (int i = 0; i < cant; i++)
    {
        cout << "Ingrese codigo de producto: ";
        cin >> nuevo.codigo;

        cout << "Ingrese nombre de producto: ";
        cin >> nuevo.nombre;

        nuevo.existencias = 0;
        nuevo.precioPromedio = 0;

        archivoProductos.write(reinterpret_cast<const char*>(&nuevo), sizeof(producto));
        cout << "Producto agregado correctamente" << endl;
    }

    archivoProductos.close();
}

void Inventario::consultarProducto()
{
    fstream archivoProductos("productos.bin", ios::in | ios::binary);

    if (!archivoProductos)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }
    cout << "*** C O N S U L T A  D E  P R O D U C T O S ***" << endl;
    //posicionarnos al inicio del archivo
    archivoProductos.seekg(0, ios::beg);

    producto actual;
    archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));

    while (!archivoProductos.eof())
    {
        cout << "Producto { codigo: " << actual.codigo << ", nombre: " << actual.nombre <<
            ", existencias: " << actual.existencias << ", precio promedio: " << actual.precioPromedio <<
            " }" << endl;
        archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));
    }

    archivoProductos.close();
}

void Inventario::agregarCompra()
{
    fstream archivoCompras("compras.bin", ios::out | ios::binary);

    if (!archivoCompras)
    {
        std::cout << "Error al intentar abrir el archivo .bin";
        return;
    }

    cout << "*** INGRESO DE COMPRAS ***\n";
    cout << "Ingrese cuantas compras desea agregar: ";
    int cant;
    cin >> cant;

    compra nuevo;

    for (int i = 0; i < cant; i++)
    {
        cout << "Ingrese nombre del proveedor: ";
        cin >> nuevo.nombreProveedor;

        do
        {
            cout << "Ingrese el codigo de producto: ";
            cin >> nuevo.codigoProducto;
        } while (!existeProducto(nuevo.codigoProducto));

        cout << "Ingrese precio de compra del producto: ";
        cin >> nuevo.precioCompra;


        cout << "Ingrese cantidad de producto: ";
        cin >> nuevo.cantidad;

        archivoCompras.write(reinterpret_cast<const char*>(&nuevo), sizeof(compra));
        cout << "Compra agregada correctamente\n";

        agregarMovimiento(nuevo.codigoProducto, tipoMovimiento::Entrada, nuevo.cantidad, nuevo.precioCompra);

        actualizarProducto(tipoMovimiento::Entrada, nuevo.codigoProducto, nuevo.cantidad, nuevo.precioCompra);
    }

    archivoCompras.close();
}

bool Inventario::existeProducto(int codigo)
{
    fstream archivoProductos("productos.bin", ios::in | ios::binary);

    if (!archivoProductos)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }
    cout << "*** C O N S U L T A  D E  P R O D U C T O S ***" << endl;
    //posicionarnos al inicio del archivo
    archivoProductos.seekg(0, ios::beg);

    producto actual;
    archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));

    while (!archivoProductos.eof())
    {
        if (actual.codigo == codigo)
        {
            archivoProductos.close();
            return true;
        }

        archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));
    }

    archivoProductos.close();
    return false;
}

void Inventario::agregarMovimiento(int codigo, tipoMovimiento tipoM, int cantidad, float precio)
{
    std::fstream archivoMovimientos("inventario.bin", std::ios::out | std::ios::binary);

    if (!archivoMovimientos)
    {
        std::cout << "Error al abrir el archivo .bin\n";
        return;
    }

    movimiento nuevo;
    nuevo.codigoProducto = codigo;
    nuevo.tipoMov = tipoM;
    nuevo.cantidadProducto = cantidad;
    nuevo.precio = precio;

    archivoMovimientos.write(reinterpret_cast<const char*>(&nuevo), sizeof(movimiento));

    archivoMovimientos.close();
}

void Inventario::actualizarProducto(tipoMovimiento tipoM, int codigo, int existenciaNueva, float precio)
{
    fstream archivoProductos("productos.bin", ios::out | ios::in | ios::binary);

    if (!archivoProductos)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }
    cout << "*** C O N S U L T A  D E  P R O D U C T O S ***" << endl;
    //posicionarnos al inicio del archivo
    archivoProductos.seekg(0, ios::beg);

    producto actual;
    long posActual = 0;

    archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));

    while (!archivoProductos.eof())
    {
        if (actual.codigo == codigo)
        {
            if (tipoM == tipoMovimiento::Entrada)
            {
                float precioPromedio = ((actual.existencias * actual.precioPromedio) +
                    (existenciaNueva * precio)) / (actual.existencias + existenciaNueva);

                actual.existencias += existenciaNueva;
                actual.precioPromedio = precioPromedio;
            }
            else
            {
                actual.existencias -= existenciaNueva;
            }

            archivoProductos.seekp(posActual, ios::beg);
            archivoProductos.write(reinterpret_cast<const char*>(&actual), sizeof(producto));
            archivoProductos.close();

            std::cout << "Producto actualizado existosamente!\n";
            return;
        }
        posActual = archivoProductos.tellg();
        archivoProductos.read(reinterpret_cast<char*>(&actual), sizeof(producto));
    }

    archivoProductos.close();
}

void Inventario::agregarVenta()
{
    fstream archivoVentas("ventas.bin", ios::out | ios::in | ios::binary);

    if (!archivoVentas)
    {
        cout << "Error al intentar abrir el archivo .bin";
        return;
    }

    cout << "*** INGRESO DE VENTAS ***\n";
    cout << "Ingrese cuantas ventas desea realizar: ";
    int cant;
    cin >> cant;

    ventas nuevo;

    for (int i = 0; i < cant; i++)
    {
        cout << "Ingrese nombre del cliente: ";
        cin >> nuevo.nombreCliente;

        do
        {
            cout << "Ingrese el codigo de producto: ";
            cin >> nuevo.codigoProducto;
        } while (!existeProducto(nuevo.codigoProducto));

        cout << "Ingrese precio de venta del producto: ";
        cin >> nuevo.precioVenta;

        cout << "Ingrese la cantidad de productos: ";
        cin >> nuevo.cantidad;

        archivoVentas.write(reinterpret_cast<const char*>(&nuevo), sizeof(ventas));
        cout << "Venta realizada correctamente!\n";

        agregarMovimiento(nuevo.codigoProducto, tipoMovimiento::Salida, nuevo.cantidad, nuevo.precioVenta);

        actualizarProducto(tipoMovimiento::Salida, nuevo.codigoProducto, nuevo.cantidad, nuevo.precioVenta);
    }

    archivoVentas.close();
}