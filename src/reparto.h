#pragma once 

class reparto
{
private:
    int numeroReparto;
    int diaReparto;
    int IDRepartidor;
public:
    void mostrarReparto ();
    bool leerReparto (int pos);
    bool cargarReparto ();
    bool guardarReparto ();
    bool guardarModificacion (int pos);
    //getters
    int getNroReparto () {return numeroReparto;}
    int getFrecuencia () {return diaReparto;}
    int getRepartidor () {return IDRepartidor;}
    //setters
    void serDiaReparto (int sDia) {diaReparto = sDia;}
    void setNroReparto (int sNro) {numeroReparto = sNro;}
    void setRepartidor (int sRepartidor) { IDRepartidor = sRepartidor; }
};

int buscarReparto (int bNroReparto);
bool altaReparto();
bool modificarReparto (int id);
void listarRepartos ();