#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <list>
#include "Bloco.h"
#include "Ferramenta.h"

using namespace std;

class Inventario
{
public:
	Inventario();
	static void AdicionarItem(Bloco);
	static void AdicionarItem(Ferramenta);
	~Inventario();
private:
	static list<Ferramenta> itensF;
	static list<Bloco> itensB;
	const static int maxInventario = 60;
};

#endif // INVENTARIO_H
