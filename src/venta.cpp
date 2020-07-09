#include <iostream>
#include "venta.h"
#include "funciones.h"´
#include "fecha.h"
#include "reparto.h"
#include "cliente.h"

const char *VENTAS_PATH = "../datos/ventas.dat";

bool venta::cargarVenta(int IDReparto)
{
    if (buscarReparto(IDReparto) < 0)
    {
        error("No existe el reparto");
        return false;
    }
    std::cout << "Ingrese el id del cliente: ";
    std::cin >> IDCliente;
    if (buscarCliente(IDCliente) < 0)
    {
        error("No existe el cliente");
        return false;
    }
    std::cout << "Ingrese el pago del cliente: ";
    std::cin >> pagoCliente;
    return true;
}

bool venta::guardarVenta()
{
    bool exito;
    FILE *p;
    p = fopen(VENTAS_PATH, "ab");
    if (p == NULL)
        return false;
    exito = fwrite(this, sizeof(venta), 1, p);
    fclose(p);
    return exito;
}

bool venta::leerVenta(int pos)
{
    bool exito;
    FILE *p;
    p = fopen(VENTAS_PATH, "rb");
    if (p == NULL)
        return false;
    fseek(p, pos * sizeof(venta), SEEK_SET);
    exito = fread(this, sizeof(venta), 1, p);
    fclose(p);
    return exito;
}

bool nuevaVenta(int IDReparto)
{
    venta reg;
    if (reg.cargarVenta(IDReparto))
    {
        if (reg.guardarVenta())
        {
            return true;
        }
        return false;
    }
    return false;
}