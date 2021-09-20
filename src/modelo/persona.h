#pragma once
#include <iostream>
#include <string>

using namespace std;

class Persona {
    private:
        string nombres;
        string apellidos;
        string DNI;
        string domicilio;
        int telefono;
        bool activo;
    public:
        void setNombre(string nombres);
        string getNombre() {return nombres;}

        void setApellido(string apellido);
        string getApellido() {return apellidos;}

        void setDni(string DNI);
        string getDNI(){return DNI;}

        void setDomicilio(string domicilio);
        string getDomicilio() {return domicilio;}

        void setTelefono(int telefono);
        int getTelefono(){return telefono;}

        void setActivo(bool act);
        bool getActivo(){return activo;}
};
