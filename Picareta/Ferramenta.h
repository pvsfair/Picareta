#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include <iostream>
class Bloco;

using namespace std;

class Ferramenta
{
public:
	const static int TIPO_PICARETA = 0;
	const static int MADEIRA	= 0;
	const static int PEDRA		= 1;
	const static int FERRO		= 2;
	const static int DIAMANTE	= 3;
	const static int OURO		= 4;
	
	Ferramenta(int);
	Ferramenta(int, int, int);
	
	virtual void jogarNoChao();
	virtual void checarEstado() const;
	virtual void exibirMensagem() const;
	virtual void destruir();
	virtual bool quebrarBloco(Bloco &);	
	virtual int getTipoN() const;
	
	void setMaxRes(int);
	void setAtualRes(int);
	~Ferramenta();
private:
	int tipoFerramenta;
protected:
	int maxRes;
	int atualRes;
};

#endif // FERRAMENTA_H
