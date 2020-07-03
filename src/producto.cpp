#include "producto.h"
#include <iostream>

const char* PATH_PRODUCTO = "../datos/producto.dat";

using namespace std;
bool producto::nuevoProducto()
{
	cout << "Ingrese el nombre del producto: ";
	cin.getline(nombreProducto, 50);
	cout << "Ingrese el precio: ";
	cin >> precio;
}

void producto::mostrarProductos()
{
	cout << "ID: " << ID;
	cout << "Nombre: " << nombreProducto;
	cout << "Precio: " << precio;
}

// bool producto::modificarproducto()
// {
// 	cout << "Ingrese el nuevo precio: ";
// 	cin >> precio;
// }

bool altaProducto ();
bool buscarProducto();
bool modificarProducto (int id);
bool eliminarProducto (int id);
bool listarProducto (int id);