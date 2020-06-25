#pragma once

class producto {
private:
	int ID;
	char nombreProducto[50];
	float precio;
public:
	void nuevoProducto();
	void mostrarProductos();
	void modificarproducto();
};