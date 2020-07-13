#include <iostream>
#include "venta.h"
#include "detalleVenta.h"
#include "producto.h"

using namespace std;

bool detalleVenta::crearDetalle(int IDVenta)
{
    this->IDVenta = IDVenta;
    bool carga;
    cin >> IDProducto;
    while (carga)
    {
        int actual = IDProducto;
        while (actual = IDProducto)
        {
            cin >> cantidad;
            cin>>IDProducto;
        }
    }
}