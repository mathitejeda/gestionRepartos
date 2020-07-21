#pragma once

class informes
{
private:
    float recaudacionAnual[11]{0};
    int anio, reparto,cliente,id;
    bool verReparto = false;

public:
    void cargarRecaudacion();
    void mostrarRecaudacion();
    float sumarTotal(float *v, int tam);
    int ventaPorProducto();
    //Setters
    void setAnio(int anio) { this->anio = anio; }
    void setReparto(int reparto) { this->reparto = reparto; }
    bool conReparto(bool r) { verReparto = r; }
};

void recaudacionAnual(int a, int r);
void comprasPorCliente (int id);