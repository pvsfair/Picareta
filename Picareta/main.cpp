#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale>
#include "Ferramenta.h"
#include "Picareta.h"
#include "Bloco.h"
#include "Inventario.h"

using namespace std;

int main(int argc, char **argv)
{
	cout << "Hello World!" << endl;
	string a = "String de TesTe!";
	locale loc;
	string b;
	for(int i = 0; i < a.length(); i++)
	{
		b.push_back(std::tolower(a[i], loc));
	}
	cout << b << endl;
	
	system("pause");
	return 0;
}
