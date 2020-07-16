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

bool venta::cargarVenta(int IDReparto,int IDCliente, int DiaReparto)
{
    fecha();
    cliente reg;
    if (buscarReparto(IDReparto) < 0)
    {
        error("No existe el reparto");
        return false;
    }
    
    if (buscarCliente(IDCliente) < 0)
    {
        error("No existe el cliente");
        return false;
    }
    int cPos = buscarCliente(IDCliente);
    reg.leerCliente(cPos);
    reg.mostrarCliente();
    if (!nuevoDetalle(ID)) {
        error ("No se pudo crear el detalle");
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

bool nuevaVenta(int IDReparto,int IDCliente, int DiaReparto)
{
    venta reg;
    cliente aux;
    int cPos = buscarCliente (IDCliente);
    if (DiaReparto==0){
        aux.leerCliente(cPos);
        DiaReparto=aux.getDiaReparto();
    }
    if(IDReparto == 0){
        aux.leerCliente(cPos);
        IDReparto = aux.getNroReparto();
    }
    if (reg.cargarVenta(IDReparto,IDCliente,DiaReparto))
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
            if(!nuevaVenta(IDReparto,lCliente.getID(),IDDiaReparto)){
                error ("No se pudo cargar la venta");
                return false;
            }
        }
        i++;
    }
}