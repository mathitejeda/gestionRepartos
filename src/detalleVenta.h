#pragma once
#include "venta.h"
class detalleVenta : public venta
{
private:
    int IDVenta, IDProducto, cantidad;
    float precioUnitario;

public:
    bool crearDetalle(int IDVenta);
    bool guardarDetalle();
    bool leerDetalle();
};

bool nuevoDetalle(int idVenta);