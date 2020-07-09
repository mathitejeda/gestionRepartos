#include "producto.h"
#include "funciones.h"
#include "rlutil.h"
#include <iostream>

using namespace std;
bool producto::nuevoProducto()
{
	ID = contarProductos() + 1;
	cout << "Ingrese el nombre del producto: ";
	cin.getline(nombreProducto, 50);
	cout << "Ingrese el precio: ";
	cin >> precio;
	if (precio < 0)
	{
		error("Ingrese un precio valido");
		return false;
	}
}

void producto::mostrarProducto()
{
	cout << "ID: " << ID;
	cout << "Nombre: " << nombreProducto;
	cout << "Precio: " << precio;
}

bool producto::guardarProducto()
{
	FILE *p;
	bool exito;
	p = fopen(PATH_PRODUCTO, "ab");
	if (p = NULL)
		return false;
	exito = fwrite(this, sizeof(producto), 1, p);
	fclose(p);
	return exito;
}

bool producto::leerProducto(int pos)
{
	bool exito;
	FILE *p;
	p = fopen(PATH_PRODUCTO, "rb");
	if (p == NULL)
		return false;
	if (pos >= 0)
	{
		fseek(p, pos * sizeof(producto), SEEK_SET);
		exito = fread(this, sizeof(producto), 1, p);
	}
	else
		exito = false;
	fclose(p);
	return exito;
}

bool producto::guardarModificacion(int pos)
{
	bool exito;
	FILE *p;
	p = fopen(PATH_PRODUCTO, "rb+");
	if (p == NULL)
		return false;
	if (pos >= 0)
	{
		fseek(p, pos * sizeof(producto), SEEK_SET);
		exito = fwrite(this, sizeof(producto), 1, p);
	}
	else
		exito = false;

	fclose(p);
	return exito;
}

bool altaProducto()
{
	bool exito;
	producto reg;
	if (reg.nuevoProducto())
	{
		if (reg.guardarProducto())
		{
			return true;
		}
		return false;
	}
	return false;
}

int buscarProducto(int id)
{
	producto search;

	int i = 0;

	while (search.leerProducto(i))
	{
		if (id == search.getID())
		{
			return i;
		}
		i++;
	}
	return -1;
}

bool modificarProducto(int id)
{
	float precio;
	int pos = buscarProducto(id);
	if (pos >= 0)
	{
		rlutil::cls();
		producto mod;
		mod.leerProducto(pos);
		mod.mostrarProducto();
		cout << "Ingrese el nuevo precio: ";
		cin >> precio;
		cin.ignore();
		mod.setPrecio(precio);

		if (mod.guardarModificacion(pos))
			return true;
		else
			return false;
	}
	return false;
}

void listarProductos()
{
	producto listar;
	int i = 0;
	while (listar.leerProducto(i))
	{
		listar.mostrarProducto();
		cout << "................................." << endl;
		i++;
	}
}

int producto::contarProductos()
{
	int i = 0;
	producto count;
	while (count.leerProducto(i))
	{
		i++;
	}
	return i;
}