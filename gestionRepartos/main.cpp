// include librerias principales
#include <iostream>
#include <wchar.h>
#include <locale.h>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
// include librerias de clase
#include "menu.h"

int main() {
	setlocale(LC_ALL, "spanish");
	menuPrincipal();
	return 0; 
}