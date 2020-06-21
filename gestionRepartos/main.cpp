// include librerias principales
#include <iostream>
#include <locale>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
// include librerias de clase
#include "persona.h"
#include "menu.h"
int main() {
	setlocale(LC_ALL, "es_ES.UTF-8");
	menu();

	return 0; 
}