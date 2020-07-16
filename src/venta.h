#pragma once
#include "fecha.h"
class venta : public fecha
{
private:
	int ID, IDCliente, IDReparto, IDProducto, IDDiaReparto;
	float pagoCliente;

public:
	void mostrarVenta();
	bool cargarVenta(int IDCliente);
	bool guardarVenta();
	bool leerVenta(int pos);
	int contarVentas();
};

bool nuevaVenta(int IDCliente);

bool cargaVentas (int IDReparto, int IDDiaReparto);