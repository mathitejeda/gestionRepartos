#include "informes.h"
#include "venta.h"
#include "cliente.h"
#include "producto.h"
#include "funciones.h"
#include <iostream>

void informes::cargarRecaudacion()
{
    venta search;
    int i = 0;
    while (search.leerVenta(i))
    {
        if (verReparto){
            if (search.getAnio()== anio && search.getReparto() == reparto){
                recaudacionAnual[search.getMes()-1] += search.getPago();
            }
        }
        else if (search.getAnio() == anio)
        {
            recaudacionAnual[search.getMes()-1] += search.getPago();
        }
        i++;
    }
}

void informes::mostrarRecaudacion (){
    if (verReparto){
        std::cout << "REPARTO: "<<reparto << std::endl;
    }
    std::cout << "RECAUDACIÓN DEL AÑO: "<<anio<<std::endl; 
    std::cout << "*ENERO: $"<<recaudacionAnual[0]<<std::endl;
    std::cout << "*FEBRERO: $"<<recaudacionAnual[1]<<std::endl;
    std::cout << "*MARZO: $"<<recaudacionAnual[2]<<std::endl;
    std::cout << "*ABRIL: $"<<recaudacionAnual[3]<<std::endl;
    std::cout << "*MAYO: $"<<recaudacionAnual[4]<<std::endl;
    std::cout << "*JUNIO: $"<<recaudacionAnual[5]<<std::endl;
    std::cout << "*JULIO: $"<<recaudacionAnual[6]<<std::endl;
    std::cout << "*AGOSTO: $"<<recaudacionAnual[7]<<std::endl;
    std::cout << "*SEPTIEMBRE: $"<<recaudacionAnual[8]<<std::endl;
    std::cout << "*OCTUBRE: $"<<recaudacionAnual[9]<<std::endl;
    std::cout << "*NOVIEMBRE: $"<<recaudacionAnual[10]<<std::endl;
    std::cout << "*DICIEMBRE: $"<<recaudacionAnual[11]<<std::endl;
    std::cout << "*TOTAL: $"<<sumarTotal(recaudacionAnual,11)<<std::endl;
}

float informes::sumarTotal(float* v,int tam){
    float total = 0;
    for (int i=0;i<tam;i++){
        total += v[i];
    }
    return total;
}

int informes::ventaPorProducto(){
    producto ventas;
    venta aux;
    int i=0;
    while(aux.leerVenta(i)){
        i++;
    }
}

void recaudacionAnual(int a,int r)
{
    informes recaudacion;
    if (r > 0){
        recaudacion.conReparto(true);
    }
    recaudacion.setAnio(a);
    recaudacion.setReparto(r);
    recaudacion.cargarRecaudacion();
    recaudacion.mostrarRecaudacion();
}

void comprasPorCliente (int id){
    cliente aux;
    venta vaux;
    int i=0;
    if (buscarCliente(id<0)){
        error("No existe el cliente");
        return;
    }
    while (vaux.leerVenta(i)){
        if (vaux.getCliente() == id){
            vaux.mostrarVenta();
        }
        i++;
    }
}