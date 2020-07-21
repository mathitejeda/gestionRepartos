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
bool detalleVenta:: leerDetalle(int pos){
    FILE* p;
    bool exito;
    p=fopen(PATH_DETALLE,"rb");
    if (p== NULL) {return false;}
    fseek(p,pos*sizeof(detalleVenta),SEEK_SET);
    exito = fread(this,sizeof(detalleVenta),1,p);
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

int buscarDetalle(int id){
    detalleVenta buscar;
    int i=0;
    while (buscar.leerDetalle(i));
    {
      if(buscar.getIDVenta() == id){
          return i;
      }
      i++;
    }
    return -1;
}