#include "cliente.h"
#include <iostream>
using namespace std;
const char* PATH_CLIENTE = "datos/cliente.dat";
void cliente::cargarCliente()
{
	persona::cargar();
	cout << "Numero de reparto: " << endl;
	cin >> numeroReparto;
	cout << "Dia de reparto: " << endl;
	cin >> diaReparto;
}

void cliente::mostrarCliente()
{
	persona::mostrar();
	cout << "Reparto nro: " << numeroReparto << endl;;
	cout << "Dias: " << diaReparto << endl;
}

bool cliente::guardar()
{
	bool exito;
	FILE* p;
	p = fopen(PATH_CLIENTE, "ab");
	if (p == NULL) { return false; }
	exito = fwrite(this, sizeof(cliente), 1, p);
	fclose(p);
	return exito;
}
