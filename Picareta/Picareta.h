#ifndef PICARETA_H
#define PICARETA_H

#include <iostream>
#include "Bloco.h"

using namespace std;

class Picareta
{
public:
	Picareta(string = "madeira", int = 0, int = 60, int = 60, Bloco = Bloco());
	Picareta(const Picareta &);
	Picareta(int);
	~Picareta();
	
private:
	int tipoN;
	string tipoS;
	int maxRes;
	int atualRes;
	Bloco matMine;
};

#endif // PICARETA_H
