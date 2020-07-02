#include "empleado.h"
#include<iostream>

using namespace std;
void empleado::altaEmpleado()
{
	persona::cargar();
	cout << "ID reparto: " << endl;
	cin >> idReparto;
}

void empleado::mostrarEmpleado()
{
	persona::mostrar();
	cout << "Reparto nro: " << idReparto;
}
