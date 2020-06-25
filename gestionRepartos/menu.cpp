#include "menu.h"
#include <iostream>
#include "rlutil.h"
#include "cliente.h"
using namespace rlutil;
using namespace std;
cliente client;
bool salir = false;
int opcion;
void menu()
{
	
	while (!salir) {
		cls();
		menuPrincipal();
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		cin.ignore();
		switch (opcion)
		{
		case 1: //clientes
			while (opcion!=0)
			{
				cls();
				submenuClientes();
				cout << "ingrese una opcion: ";
				cin >> opcion;
				cin.ignore();
				switch (opcion)
				{
				case 1:
					client.cargar();
					break;
				case 0:
					cls();
					cout << "volviendo al menu principal";
					msleep(1000);
					break;
				default:
					cls();
					cout << "Opcion invalida";
					anykey();
					break;
				}
			}

			break;
		case 0:
			cls();
			cout << "Programa finalizado.";
			salir = true;
			anykey();
			break;
		default:
			cls();
			cout << "Opcion invalida";
			anykey();
			break;
		}
	}

}

void menuPrincipal()
{
	cout<< "MEN� PRINCIPAL" <<endl;
	cout<< "...................." <<endl;
	cout<< "1)CLIENTES" <<endl;
	cout<< "2)REPARTOS" <<endl;
	cout<< "3)PRODUCTOS" <<endl;
	cout<< "4)VENTAS" <<endl;
	cout<< "5)INFORMES" <<endl;
	cout<< "6)CONFIGURACI�N" <<endl;
	cout<< "...................." <<endl;
	cout<< "0)SALIR DEL PROGRAMA" <<endl;
}

void submenuClientes() {
	cout << "CLIENTES" <<endl;
	cout << "..........................." <<endl;
	cout << "1)ALTA DE CLIENTE" <<endl;
	cout << "2)MODIFICACION" <<endl;
	cout << "3)BAJA DE CLIENTE" <<endl;
	cout << "4)BUSCAR CLIENTE" <<endl; //TODO en la funcion agregar un metodo que permita la busqueda por id o por apellido
	cout << "..........................." <<endl;
	cout << "0) VOLVER AL MEN� PRINCIPAL" <<endl;
	cout << "" <<endl;
}

void submenuRepartos()
{
	cout << "REPARTOS" << endl;
	cout << "..............................." << endl;
	cout << "1)VIZUALIZAR TODOS LOS REPARTOS" << endl;
	cout << "2)ALTA DE REPARTO" << endl;
	cout << "3)MODIFICAR REPARTO" << endl;
	cout << "..............................." << endl;
	cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
	cout << "" << endl;
}

void submenuProductos()
{
	cout << "PRODUCTOS" << endl;
	cout << "..........................." << endl;
	cout << "1)VISUALIZAR PRODUCTOS" << endl;
	cout << "2)MODIFICAR PRODUCTO" << endl;
	cout << "3)AGREGAR PRODUCTO" << endl;
	cout << "..........................." << endl;
	cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
	cout << "" << endl;
}

void informes() {
	cout << "INFORMES" << endl;
	cout << "..........................." << endl;
	cout << "1)RECAUDACION ANUAL" << endl;
	cout << "2)RECAUDACION POR REPARTO" << endl;
	cout << "3)COMPRAS POR CLIENTE" << endl;
	cout << "4)VENTAS DE PRODUCTOS" << endl;
	cout << "..........................." << endl;
	cout << "0) VOLVER AL MEN� PRINCIPAL" << endl;
	cout << "" << endl;
}
