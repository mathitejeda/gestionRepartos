#pragma once
#include "fecha.h"
class venta : public fecha
{
private:
	int ID, IDCliente, IDReparto, IDProducto, IDDiaReparto;
	float pagoCliente;

public:
	void mostrarVenta();
	bool cargarVenta(int IDReparto,int IDCliente, int DiaReparto);
	bool guardarVenta();
	bool leerVenta(int pos);
};

bool nuevaVenta(int IDReparto,int IDCliente, int DiaReparto);

bool cargaVentas (int IDReparto, int IDDiaReparto);