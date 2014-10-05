#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Bloco.h"
#include "Ferramenta.h"
#include "Picareta.h"
#include "Inventario.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "Hello World!" << endl;
	float minerioFerroRes[5] = {15.0f, 1.15f, 0.75f, 0.6f, 15.0f};
	bool minerioFerroColh[5] = {false, true, true, true, false};
	Bloco b((string)"Minerio de Ferro",  minerioFerroRes, minerioFerroColh);
	Picareta p(1);
	p.quebrarBloco(b);
	system("pause");
	return 0;
}
