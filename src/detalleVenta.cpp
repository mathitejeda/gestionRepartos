#include <iostream>
#include "venta.h"
#include "detalleVenta.h"
#include "producto.h"

using namespace std;

const char* PATH_DETALLE = "../datos/detalle.dat";

bool detalleVenta::crearDetalle(int IDVenta)
{
    this->IDVenta = IDVenta;
    bool carga;
    cout<<"ID de producto vendido: ";
    cin >> IDProducto;
    while (carga)
    {
        int actual = IDProducto;
        while (actual == IDProducto)
        {
            cout << "cantidad: ";
            cin >> cantidad;
            cout<<"ID de producto vendido: ";
            cin>>IDProducto;
        }
    }
}

bool detalleVenta::guardarDetalle (){
    bool exito;
    FILE *p;
    p=fopen(PATH_DETALLE,"ab");
    if (p == NULL) return false;
    exito = fwrite(this,sizeof(detalleVenta),1,p);
    fclose (p);
    return exito;
}

bool nuevoDetalle (int idVenta){
    detalleVenta reg;

    if(reg.crearDetalle(idVenta)){
        if(reg.guardarDetalle()){
            return true;
        }
        return false;
    }
    return false;
}