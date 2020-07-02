// include librerias principales
#include <iostream>
#include <wchar.h>
#include <clocale>
#include <stdio.h>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
// include librerias de clase
#include "menu.h"

int main() {
	setlocale(LC_ALL, "Spanish");
	menuPrincipal();
	return 0; 
} 