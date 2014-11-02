#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include <iostream>
#include "Data.h"
class Bloco;

using namespace std;

class Ferramenta
{
	friend ostream &operator<< (ostream &, const Ferramenta &);
	
public:
	const static int TIPO_PICARETA = 0;
	
	const static int MADEIRA	= 0;
	const static int PEDRA		= 1;
	const static int FERRO		= 2;
	const static int DIAMANTE	= 3;
	const static int OURO		= 4;
	
	Ferramenta(int, Data &);
	Ferramenta(int, int, int, Data &);
	
	virtual void jogarNoChao();
	virtual void checarEstado() const;
	virtual void infoItem() const;
	virtual inline void destruir();
	virtual bool quebrarBloco(Bloco &);
	
	virtual int getTipoN() const;
	virtual string getTipoS() const;
	virtual int getAtualRes() const;
	virtual int getMaxRes() const;
	virtual string getTipoDaFerramenta() const;
	virtual ~Ferramenta();
private:
	const int tipoFerramentaN = 0;
	const string tipoFerramentaS = "";
	void setTipoFerramentaS(int);
protected:
	Data * dataDeCriacao;
	const int maxRes = 0;
	float atualRes;
	
	void setMaxRes(int);
	void setAtualRes(int);
};

#endif // FERRAMENTA_H
