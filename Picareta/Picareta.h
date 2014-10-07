#ifndef PICARETA_H
#define PICARETA_H

#include <iostream>
#include "Bloco.h"
#include "Ferramenta.h"

using namespace std;

class Picareta : Ferramenta
{
public:
	Picareta(string = "madeira", int = 0, int = 60, int = 60, Bloco = Bloco());
	Picareta(const Picareta &);
	Picareta(int);
	
	void setTipoN(int);
	void setTipoS(string);
	void setMatMine(Bloco);
	
	virtual void jogarNoChao();
	virtual void checarEstado() const;
	virtual void destruir();
	virtual bool quebrarBloco(Bloco &);	
	virtual int getTipoN() const;
	static void mostrarPicaretasQuebradas();
	~Picareta();
	
private:
	int tipoN;
	string tipoS;
	Bloco matMine;
	static int numPicaretasQuebradas;
};

#endif // PICARETA_H
