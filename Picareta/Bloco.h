#ifndef BLOCO_H
#define BLOCO_H

#include <iostream>
#include "Ferramenta.h"

using namespace std;

class Bloco
{
public:
	Bloco();
	Bloco(const Bloco &);
	Bloco(string, float[4], bool[4]);
	bool quebrarBloco(const Ferramenta &);
	~Bloco();
	
private:
	string nome;
	float resMat[4];
	float colherMat[4];

};

#endif // BLOCO_H
