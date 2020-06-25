#include "producto.h"
#include <iostream>

using namespace std;
void producto::nuevoProducto()
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

void producto::modificarproducto()
{
	cout << "Ingrese el nuevo precio: ";
	cin >> precio;
}
