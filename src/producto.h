#pragma once

class producto {
private:
	int ID;
	char nombreProducto[50];
	float precio;
public:
	bool nuevoProducto();
	void mostrarProductos();
	bool guardarProducto ();
	bool guardarModificacion();
	bool leerProducto();
	// setters
	
	void setPrecio (float sPrecio) {precio = sPrecio;}

	// getters

	int getID() {return ID;}
	float getPrecio () { return precio;}
};

bool altaProducto ();
bool buscarProducto();
bool modificarProducto (int id);
bool listarProducto (int id);