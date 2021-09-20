#include "persona.h"

class Empleado:public Persona{
private:
    long int id;
    int idReparto;
public:
    long int getID(){return id;}
    long int setID(long id);

    int getReparto(){return reparto;}
    int setReparto(int idReparto);

};
