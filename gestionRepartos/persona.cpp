#include "persona.h"
using namespace std;
void persona::cargar(){
    cout << "Nombres: "<<endl;
    cin.getline(nombres,50);
    cout << "Apellidos: "<<endl;
    cin.getline(apellidos,50);
    cout << "DNI: "<<endl;
    cin.getline(DNI,12);
    cout << "Domicilio: "<<endl;
    cin.getline(domicilio,50);
    cout << "Telefono: "<<endl;
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

