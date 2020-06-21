#pragma once
#include <iostream>
class persona
{
protected:
	char nombres[50], apellidos[50], DNI[12], domicilio[50];
	int telefono;
	bool activo;
public:
	void cargar ();
	void mostrar ();
};
