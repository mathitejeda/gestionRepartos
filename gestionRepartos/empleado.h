#pragma once
#include "persona.h"
class empleado:public persona
{
private:
	int id, idReparto;
	float comision;
public:
	void altaEmpleado();
	void mostrarEmpleado();
	void bajaEmpleado();
};

