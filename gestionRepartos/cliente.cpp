#include "cliente.h"
#include "funciones.h"
#include "rlutil.h"
#include <iostream>
using namespace std;
const char* PATH_CLIENTE = "datos/cliente.dat";
bool cliente::cargarCliente()
{
	bool exito;
	ID = contarClientes() +1;
	persona::cargar();
	cout << "Numero de reparto: ";
	cin >> numeroReparto;
	cout << "Dia de reparto: ";
	cin >> diaReparto;
	return exito = true;
}

void cliente::mostrarCliente()
{
	persona::mostrar();
	cout << "Reparto nro: " << numeroReparto << endl;
	cout << "Dias: " << diaReparto << endl;
}

bool cliente::guardar()
{
	bool exito;
	FILE* p;
	p = fopen(PATH_CLIENTE, "ab");
	if (p == NULL) { return false; }
	exito = fwrite(this, sizeof(cliente), 1, p);
	fclose(p);
	return exito;
}

bool cliente::guardarModificacion(int pos){
	bool exito;
	FILE* p;
	p = fopen(PATH_CLIENTE,"rb+");
	if (p==NULL) {return false;}
	if (pos>=0){
	fseek (p,pos*sizeof (cliente),SEEK_SET);
	exito = fwrite(this,sizeof(cliente),1,p);
	}	
	else exito = false;
	fclose (p);
	return exito;
}

bool cliente::leerCliente (int pos){
	bool exito;
	FILE* p;
	p = fopen (PATH_CLIENTE,"rb");
	if (p == NULL){ return false; }

	if (pos >=0){
		fseek(p,pos*sizeof(cliente),SEEK_SET);
		exito = fread (this,sizeof(cliente),1,p);
	}
	else exito = false;
    fclose(p);
    return exito;
}

int cliente::contarClientes (){
	int cant,bytes;
	FILE* p;
	p = fopen (PATH_CLIENTE, "rb");

	if (p == NULL) return 0;
	fseek (p,0,SEEK_END);
	bytes = ftell(p);
	cant = bytes/sizeof(cliente);
	fclose(p);
	return cant;
}
//globales

int buscarCliente (int ID){
	cliente search;
	int i = 0;
	while (search.leerCliente(i)){
		if (search.getID() == ID && search.getEstado() == true){
			return i;
		}
		i++;
	}
	return -1;
}

bool altaCliente(){
	cliente reg;
	if(reg.cargarCliente()){
		if (reg.guardar()){
			return true;
		}
		else return false;
	}
	else return false;

}

bool modificacionCliente (int id){
	int repartidor , dia, telefono,opc;
	char domicilio [50];
	int pos;
	pos = buscarCliente (id);
	if (pos >= 0){
		rlutil::cls();
		cliente mod;
		mod.leerCliente(pos);
		mod.mostrarCliente();
		cout<<endl;
		cout<< "Que desea modificar? "<<endl;
		cout<< "1. Repartidor"<<endl;
		cout<< "2. Dia de reparto"<<endl;
		cout<< "3. Domicilio"<<endl;
		cout<< "4. Telefono"<<endl;
		cout <<"0. Cancelar";
		cin>> opc;
		cin.ignore();
		switch (opc)
		{
		case 1:
			cout<< "Ingrese el nuevo repartidor: ";
			cin >> repartidor;
			mod.setNroReparto(repartidor);
			break;

		case 2:
			cout<< "Ingrese el nuevo dia de reparto: ";
			cin>> dia;
			mod.setDiaReparto(dia);
			break;
		
		case 3:
			cout<< "Ingrese el nuevo domicilio: ";
			cin.getline(domicilio,50);
			mod.setDomicilio(domicilio);
			break;

		case 4:
			cout<< "Ingrese el nuevo telefono: ";
			cin >> telefono;
			mod.setTelefono(telefono);
			break;
		
		case 0:
			cout << "No se haran modificaciones";
			return false;
			break;
		default:

			error("opcion incorrecta");
			break;
		}

		if (mod.guardarModificacion(pos)){
			return true;
		}
		else {
			error ("No existe el cliente");
			return false;
			}
	}
	return false;
}

bool bajaCliente (int id){
	int pos;
	char sel;
	bool exito = false;

	pos = buscarCliente(id);

	if (pos >= 0){
		rlutil::cls();
		cliente baja;
		baja.leerCliente(pos);
		baja.mostrarCliente();
		cout<< endl;
		cout << "Por favor, confirme que desea eliminar al cliente [s/n]: ";
		cin >> sel;

		switch (sel)
		{
		case 's': case 'S':
			baja.setEstado(false);
			if (baja.guardarModificacion(pos)){
				exito = true;
			}
			break;
		case 'n': case 'N':
			error("No se eliminara el cliente");
		default:
			error("opcion invalida");
			break;
		}
	}
	else error ("No existe el cliente.");
	return exito;
}

void listarCliente (int id){
	int pos = buscarCliente(id);
	
	if (pos >= 0){
		cliente mostrar;
		mostrar.leerCliente(pos);
		mostrar.mostrarCliente();
	}
	else error ("No existe el cliente");
}