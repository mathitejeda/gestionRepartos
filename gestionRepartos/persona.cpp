#include "persona.h"

void persona::cargar(){
    std::cout << "Nombres: "<<std::endl;
    std::cin.getline(nombres,50);
    std::cout << "Apellidos: "<<std::endl;
    std::cin.getline(apellidos,50);
    std::cout << "DNI: "<<std::endl;
    std::cin.getline(DNI,12);
    std::cout << "Domicilio: "<<std::endl;
    std::cin.getline(domicilio,50);
    std::cout << "Telefono: "<<std::endl;
    std::cin >> telefono;
    
    activo = true;
}
