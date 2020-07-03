#include "reparto.h"
#include "rlutil.h"
#include "funciones.h"
#include <iostream>
#include <cstring>

using namespace std;

const char* PATH_REPARTO = "../datos/repartos.dat";

bool reparto::cargarReparto () {
    bool exito;
    cout<< "Ingrese el numero de reparto: ";
    cin >> numeroReparto;
    cout<< "Ingrese el dia del reparto: ";
    cin >> diaReparto;
    cout << "Ingrese el id del repartidor: ";
    cin >> IDRepartidor;
    cin.ignore();
    exito = true;

    return exito;
}

void reparto::mostrarReparto (){
    cout << "Numero de reparto: " << numeroReparto<<endl;
    cout << "Dia de reparto: " << diaReparto;
    cout << "Repartidor: " << IDRepartidor;
}

bool reparto::guardarReparto (){
    bool exito;
    FILE* p;
    p = fopen (PATH_REPARTO,"ab");

    if (p == NULL) return false;

    exito = fwrite (this,sizeof(reparto),1,p);
    fclose(p);
    return exito;
}

bool reparto::guardarModificacion(int pos){
	bool exito;
	FILE* p;
	p = fopen(PATH_REPARTO,"rb+");
	if (p==NULL) {return false;}
	if (pos>=0){
	fseek (p,pos*sizeof (reparto),SEEK_SET);
	exito = fwrite(this,sizeof(reparto),1,p);
	}	
	else exito = false;
	fclose (p);
	return exito;
}

bool reparto::leerReparto (int pos){
    bool exito;
    FILE* p;
    p = fopen(PATH_REPARTO,"rb");

    if (pos >= 0){
        fseek(p,pos*sizeof(reparto),SEEK_SET);
        exito = fread(this,sizeof(reparto),1,p);
    }
    else exito = false;
    fclose (p);
    return exito;
}

bool altaReparto(){
    reparto alta;
    if (alta.cargarReparto()){
        if(alta.guardarReparto()){
            return true;
        }
        return false;
    }
    return false;
}

int buscarReparto (int bNroReparto){
    reparto search;
    int i = 0;
    while (search.leerReparto(i)){
        if (search.getNroReparto() == bNroReparto){
            return i;
        }
        i++;
    }
    return -1;
}

bool modificarReparto (int id){
    int repartidor;
    int pos;
    pos = buscarReparto(id);

    if (pos >= 0){
        rlutil::cls();
        reparto mod;
        mod.leerReparto(pos);
        mod.mostrarReparto();
        cout<< endl;
        cout<< "Ingrese el nuevo repartidor: ";
        cin >> repartidor;
        cin.ignore();
        mod.setRepartidor(repartidor);

        if (mod.guardarModificacion(pos)) return true;
    }
    else{
    error("No existe el reparto");
    return false;
    }
    return false;

}

void listarRepartos (){
    reparto listar;
    int i = 0;
    cout << "  Reparto numero   |   Repartidor a cargo";
    cout<<endl;
    while (listar.leerReparto(i)){
        cout <<"\t"<< listar.getNroReparto()<<"          |\t\t"<<listar.getRepartidor();
        cout<<endl;
        i++;
    }
}