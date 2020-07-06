#pragma once

class producto {
private:
	int ID;
	char nombreProducto[50];
	float precio;
public:
	bool nuevoProducto();
	void mostrarProducto();
	bool guardarProducto ();
	bool guardarModificacion(int pos);
	bool leerProducto(int pos);
	// setters
	
	void setPrecio (float sPrecio) {precio = sPrecio;}

	// getters

	int getID() {return ID;}
	float getPrecio () { return precio;}
};

bool altaProducto ();
int buscarProducto(int id);
bool modificarProducto (int id);
void listarProductos ();