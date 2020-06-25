#pragma once
#include "persona.h"
class cliente :public persona
{
private:
	int ID;
	int numeroReparto;
	int diaReparto;
	float saldo;
public:
	void cargarCliente();
	void mostrarCliente();
	bool guardar();
	//setters
	void setID(int id);
	void setNroReparto(int num);
	void setDiaReparto(int dia);
	void setSaldo(float saldo);

	//getters

	int getID() { return ID; };
	int getNroReparto() { return numeroReparto; };
	int getDiaReparto() { return diaReparto; };
	float getSaldo() { return saldo; };
};

