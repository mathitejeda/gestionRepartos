#include "menu.h"
#include "funciones.h"
#include <iostream>
#include "rlutil.h"
#include "cliente.h"
using namespace rlutil;
using namespace std;

void menuPrincipal()
{
	int opcion;
	while (true) {
		cls();
		cout << "MENÚ PRINCIPAL" << endl;
		cout << "...................." << endl;
		cout << "1)CLIENTES" << endl;
		cout << "2)REPARTOS" << endl;
		cout << "3)PRODUCTOS" << endl;
		cout << "4)VENTAS" << endl;
		cout << "5)INFORMES" << endl;
		cout << "6)CONFIGURACIÓN" << endl;
		cout << "...................." << endl;
		cout << "0)SALIR DEL PROGRAMA" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		cin.ignore();
		switch (opcion)
		{
		case 1:
			cls();
			submenuClientes();
			break;
		case 0:
			cls();
			cout << "Programa finalizado.";
			msleep(1000);
			return;
			break;
		default:
			cls();
			cout << "Opcion invalida";
			anykey();
			break;
		}
	}

}


void submenuClientes() {
	int opcion,id;
	while (true)
	{
		cls();
		cout << "CLIENTES" << endl;
		cout << "..........................." << endl;
		cout << "1)ALTA DE CLIENTE" << endl;
		cout << "2)MODIFICACION" << endl;
		cout << "3)BAJA DE CLIENTE" << endl;
		cout << "4)BUSCAR CLIENTE" << endl; //TODO en la funcion agregar un metodo que permita la busqueda por id o por apellido
		cout << "..........................." << endl;
		cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		cin.ignore();
		switch (opcion)
		{
		case 1:
			cls();
			if (altaCliente()){
				exito ("Cliente guardado correctamente");
			}
			else {
				error ("No se pudo guardar el cliente");
			}
			anykey();
			break;

		case 2:
			cls();
			cout << "Ingrese el id del cliente a modificar: ";
			cin >> id;
			if (modificacionCliente(id)){
				exito ("Cliente modificado con exito!");
			}
			else error("No se pudo modificar el cliente");
			anykey();
			break;

		case 3:
			cls();
			cout << "Ingrese el id del cliente a eliminar: ";
			cin >> id;
			if (bajaCliente(id)){
				exito("Cliente eliminado");
			}
			else error("No se eliminó el cliente.");
			anykey();
			break;

		case 4:
			cls();
			cout << "Ingrese el id del cliente que desea visualizar: ";
			cin >> id;
			listarCliente(id);
			anykey();
			break;
		case 0:
			cls();
			cout << "volviendo al menu principal";
			msleep(1000);
			return;
			break;
		default:
			cls();
			cout << "Opcion invalida"; //agregar una funcion de opcion invalida
			anykey();
			break;
		}
	}

}

void submenuRepartos()
{
	int opcion;
	while (true)
	{
		cls();
		cout << "REPARTOS" << endl;
		cout << "..............................." << endl;
		cout << "1)VIZUALIZAR TODOS LOS REPARTOS" << endl;
		cout << "2)ALTA DE REPARTO" << endl;
		cout << "3)MODIFICAR REPARTO" << endl;
		cout << "..............................." << endl;
		cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		cin.ignore();
		switch (opcion)
		{
		default:
			break;
		}

	}

}

void submenuProductos()
{

	int opcion;
	while (true)
	{
		cls();
		cout << "PRODUCTOS" << endl;
		cout << "..........................." << endl;
		cout << "1)VISUALIZAR PRODUCTOS" << endl;
		cout << "2)MODIFICAR PRODUCTO" << endl;
		cout << "3)AGREGAR PRODUCTO" << endl;
		cout << "..........................." << endl;
		cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
		cout << "" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		cin.ignore();
		switch (opcion)
		{
		default:
			break;
		}

	}
}

void informes() {

	int opcion;
	while (true)
	{
		cls();
		cout << "INFORMES" << endl;
		cout << "..........................." << endl;
		cout << "1)RECAUDACION ANUAL" << endl;
		cout << "2)RECAUDACION POR REPARTO" << endl;
		cout << "3)COMPRAS POR CLIENTE" << endl;
		cout << "4)VENTAS DE PRODUCTOS" << endl;
		cout << "..........................." << endl;
		cout << "0) VOLVER AL MENÚ PRINCIPAL" << endl;
		cout << "" << endl;
		cin >> opcion;
		cin.ignore();
		switch (opcion)
		{
		case 1:
			break;
		default:
			break;
		}

	}
}
