#include "informes.h"
#include "venta.h"

float recaudacionAnual(int anio)
{
    venta search;
    int i = 0;
    float total;
    while (search.leerVenta(i))
    {
        if (search.getAnio() == anio)
        {
            total += search.getPago();
        }
        i++;
    }
    return total;
}