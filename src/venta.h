#pragma once
#include "fecha.h"
class venta : public fecha
{
private:
	int ID, IDCliente, IDReparto, IDProducto;
	float pagoCliente;

public:
	void mostrarVenta();
	bool cargarVenta(int IDReparto);
	bool guardarVenta();
	bool leerVenta(int pos);
};


bool nuevaVenta(int IDReparto);