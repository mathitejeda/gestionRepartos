#include "cliente.h"
#include <iostream>
using namespace std;
const char* PATH_CLIENTE = "datos/cliente.dat";
bool cliente::cargarCliente()
{
	bool exito;
	persona::cargar();
	cout << "Numero de reparto: " << endl;
	cin >> numeroReparto;
	cout << "Dia de reparto: " << endl;
	cin >> diaReparto;
	return exito = true;
}

void cliente::mostrarCliente()
{
	persona::mostrar();
	cout << "Reparto nro: " << numeroReparto << endl;;
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

void altaCliente(){
	cliente reg;
	if(reg.cargarCliente()){
		if (reg.guardar()){
			
		}
	}
}