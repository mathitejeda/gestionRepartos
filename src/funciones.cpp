#include "funciones.h"
#include <iostream>
#include "rlutil.h"
using namespace std;
using namespace rlutil;

void error (const char*mensaje){
    setColor(RED);
    cout <<endl<< ">"<<mensaje;
    setColor(WHITE);
}
void exito (const char*mensaje){
    setColor(GREEN);
    cout <<endl<< ">"<<mensaje;
    setColor(WHITE);
}