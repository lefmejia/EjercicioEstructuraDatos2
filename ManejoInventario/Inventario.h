#ifndef INVENTARIO_H
#define INVENTARIO_h

#include <iostream>

struct producto
{
    int codigo;
    char nombre[20];
    int existencias;
    float precioPromedio;
};

struct compra
{
    char nombreProveedor[20];
    int codigoProducto;
    float precioCompra;
    int cantidad;
};

struct ventas
{
    char nombreCliente[20];
    int codigoProducto;
    int cantidad;
    float precioVenta;
};

enum class tipoMovimiento
{
    Entrada,
    Salida
};

struct movimiento
{
    int codigoProducto;
    int cantidadProducto;
    float precio;
    tipoMovimiento tipoMov;
};

class Inventario
{
public:
    static void agregarProducto();
    static void consultarProducto();
    static void agregarCompra();
    static void agregarVenta();
    static void agregarMovimiento(int, tipoMovimiento, int, float);

    static bool existeProducto(int);
    static void actualizarProducto(tipoMovimiento, int, int, float);
};

#endif