#include <iostream>
#include "fecha.h"
#include "venta.h"
#include "funciones.h"
#include "reparto.h"
#include "cliente.h"
#include "producto.h"
using namespace std;

const char *VENTAS_PATH = "../datos/ventas.dat";

bool venta::cargarVenta(int IDReparto)
{
    fecha();
    if (buscarReparto(IDReparto) < 0)
    {
        error("No existe el reparto");
        return false;
    }
    cout << "Ingrese el id del cliente: ";
    cin >> IDCliente;
    if (buscarCliente(IDCliente) < 0)
    {
        error("No existe el cliente");
        return false;
    }
    cout << "Ingrese el pago del cliente: ";
    cin >> pagoCliente;
    return true;
}

void venta::mostrarVenta()
{
    cout<< "ID venta: "<<ID;
    cout << "fecha de venta: ";
    mostrarFecha();
    cout<<endl;
    cout << "ID cliente: " <<IDCliente;
    cout << "ID reparto: "<<IDReparto;
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