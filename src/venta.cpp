#include <iostream>
#include "fecha.h"
#include "venta.h"
#include "detalleVenta.h"
#include "funciones.h"
#include "reparto.h"
#include "cliente.h"
#include "producto.h"
using namespace std;

const char *VENTAS_PATH = "../datos/ventas.dat";

bool venta::cargarVenta(int IDCliente)
{
    int cPos = buscarCliente(IDCliente);
    ID = contarVentas()+1;
    if (cPos < 0)
    {
        error("No existe el cliente");
        return false;
    }
    fecha();
    cliente reg;
    reg.leerCliente(cPos);
    IDReparto = reg.getNroReparto();
    IDDiaReparto = reg.getDiaReparto();
    reg.mostrarCliente();
    cout<< endl << "............................." <<endl;
    if (!nuevoDetalle(ID))
    {
        error("No se pudo crear el detalle");
        return false;
    }
    cout << "Su pago: ";
    cin >> pagoCliente;
    reg.setSaldo(pagoCliente);
    return true;
}

void venta::mostrarVenta()
{
    cout << "ID venta: " << ID;
    cout << "fecha de venta: ";
    mostrarFecha();
    cout << endl;
    cout << "ID cliente: " << IDCliente;
    cout << "ID reparto: " << IDReparto;
    cout << "Pago del cliente: $"<<pagoCliente;    
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

int venta::contarVentas()
{
    FILE *p;
    int cant, bytes;
    p = fopen(VENTAS_PATH, "rb");
    if (p == NULL)
        return 0;
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cant = bytes / sizeof(venta);
    fclose(p);
    return cant;
}

bool nuevaVenta(int IDCliente)
{
    venta reg;
    if (reg.cargarVenta(IDCliente))
    {
        if (reg.guardarVenta())
        {
            return true;
        }
        return false;
    }
    return false;
}

bool cargaVentas(int IDReparto, int IDDiaReparto)
{
    venta reg;
    cliente lCliente;
    reparto lReparto;
    int i = 0;
    while (lCliente.leerCliente(i))
    {
        if (lCliente.getDiaReparto() == IDDiaReparto && lCliente.getNroReparto() == IDReparto)
        {
            if (!nuevaVenta(lCliente.getID()))
            {
                error("No se pudo cargar la venta");
                return false;
            }
        }
        i++;
    }
}