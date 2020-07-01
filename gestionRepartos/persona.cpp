#include "persona.h"
using namespace std;
void persona::cargar(){
    cout << "Nombres: ";
    cin.getline(nombres,50);
    cout << "Apellidos: ";
    cin.getline(apellidos,50);
    cout << "DNI: ";
    cin.getline(DNI,12);
    cout << "Domicilio: ";
    cin.getline(domicilio,50);
    cout << "Telefono: ";
    cin >> telefono;
    
    activo = true;
}

void persona::mostrar()
{
    cout << "Nombres: " << nombres << endl;
    cout << "Apellidos: " << apellidos << endl;
    cout << "DNI: " << DNI << endl;
    cout << "Domicilio: " << domicilio << endl;
    cout << "Teléfono: " << telefono << endl;
}

