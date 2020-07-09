#pragma once

class venta
{
private:
	int ID, IDCliente, IDReparto ;
	fecha fechaVenta;
	float pagoCliente;
public:
	void MostrarVenta();
	bool cargarVenta(int IDReparto);
	bool guardarVenta();
	bool leerVenta(int pos);

};

bool nuevaVenta(int IDReparto);