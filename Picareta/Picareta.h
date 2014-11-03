#ifndef PICARETA_H
#define PICARETA_H

#include <iostream>
#include "Bloco.h"
#include "Ferramenta.h"

using namespace std;

class Picareta : public Ferramenta
{
	friend ostream &operator<< (ostream &, const Picareta &);
	
public:
	Picareta(string = "madeira", int = 0, int = 60, int = 60, Bloco * = new Bloco(), Data * = new Data(1,1,2000));
	Picareta(const Picareta &);
	Picareta(int, Data &);
	
	void setTipoN(int);
	void setTipoS(string);
	void setMatMine(Bloco &);
	
	static int menuPicareta();
	
	virtual void jogarNoChao();
	virtual void checarEstado() const;
	virtual void infoItem() const;
	virtual inline void destruir()
	{
		numPicaretasQuebradas++;
		cout << "Sua Picareta de " << this->tipoS << " quebrou." << endl;
		cout << "Construa uma picareta Nova" << endl;
	}
	virtual bool quebrarBloco(Bloco &);	
	
	virtual int getTipoN() const;
	
	virtual string getTipoS() const;
	
	static void mostrarPicaretasQuebradas();
	
	Picareta operator =(Picareta);
	
	virtual ~Picareta();
	
private:
	const int tipoN = 0;
	const string tipoS = "";
	Bloco * matMine;
	static int numPicaretasQuebradas;
};

#endif // PICARETA_H
