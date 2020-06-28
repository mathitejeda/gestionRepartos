#include "funciones.h"
#include <iostream>
#include "rlutil.h"
using namespace std;
using namespace rlutil;

void error (char*mensaje){
    setColor(RED);
    cout << ">"<<mensaje;
    setColor(WHITE);
}
void exito (char*mensaje){
    setColor(GREEN);
    cout << ">"<<mensaje;
    setColor(WHITE);
}