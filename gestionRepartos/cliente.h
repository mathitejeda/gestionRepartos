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
	void mostrarCliente();
	bool cargarCliente();
	bool leerCliente(int pos);
	bool guardar();
	bool guardarModificacion(int pos);
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

void altaCliente ();