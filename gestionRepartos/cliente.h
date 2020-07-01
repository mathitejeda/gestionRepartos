#pragma once
#include "persona.h"
enum diaReparto{domingo,lunes,martes,miercoles,jueves,viernes,sabado};
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
	int contarClientes ();
	//setters
	void setID(int id);
	void setNroReparto(int num){numeroReparto=num;};
	void setDiaReparto(int dia){diaReparto=dia;};
	void setSaldo(float sald){saldo= sald;};

	//getters

	int getID() { return ID; };
	int getNroReparto() { return numeroReparto; };
	int getDiaReparto() { return diaReparto; };
	float getSaldo() { return saldo; };
};

bool altaCliente ();
bool buscarCliente ();
bool modificacionCliente(int id);
bool bajaCliente (int id);
void listarCliente (int id);