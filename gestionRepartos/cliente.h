#pragma once
#include "persona.h"
class cliente:public persona
{
private:
	int ID;
	int numeroReparto;
	int diaReparto;
	float saldo;
public:
	void cargar();
	void mostrar();
};

