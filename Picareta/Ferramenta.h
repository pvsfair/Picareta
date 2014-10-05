#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include <iostream>
#include "Bloco.h"

using namespace std;

class Ferramenta
{
public:
	Ferramenta();
	~Ferramenta();
	void jogarNoChao();
	void checarEstado() const;
	void exibirMensagem() const;
	void destruir();
	bool quebrarBloco(Bloco &);
};

#endif // FERRAMENTA_H
