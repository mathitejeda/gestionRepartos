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
	//setters
	void setID(int id);
	void setNroReparto();
	void setDiaReparto();
	void setSaldo();

	//getters

	int getID();
	int getNroReparto();
	int getDiaReparto();
	float getSaldo();

};

