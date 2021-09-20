#        virtual ~persona();
pragma once
#include <iostream>
#include <cstring>
class persona
{
protected:
	char nombres[50], apellidos[50], DNI[12], domicilio[50];
	int telefono;
	bool activo;
public:
	void cargar ();
	void mostrar ();
	bool getEstado() { return activo; }
	void setEstado(bool act) {
		activo = act;
		}
	void setDomicilio (char sDomicilio[12]) {strcpy(domicilio,sDomicilio);}
	void setTelefono (int sTelefono){ telefono = sTelefono;}
	
};
