#include "cliente.h"
#include <iostream>
using namespace std;
void cliente::cargar()
{
	persona::cargar();
	cout << "Numero de reparto: " << endl;
	cin >> numeroReparto;
	cout << "Dia de reparto: " << endl;
	cin >> diaReparto;
}

void cliente::mostrar()
{
	persona::mostrar();
	cout << "Reparto nro: " << numeroReparto << endl;;
	cout << "Dias: " << diaReparto << endl;
}
