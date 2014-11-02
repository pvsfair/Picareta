#include "Ferramenta.h"
#include "Bloco.h"

Ferramenta::Ferramenta(int tipoFerramenta)
{
	this->tipoFerramenta = tipoFerramenta;
}
Ferramenta::Ferramenta(int tipoFerramenta, int maxRes, int atualRes)
{
	this->tipoFerramenta = tipoFerramenta;
	this->setMaxRes(maxRes);
	this->setAtualRes(atualRes);
}

void Ferramenta::jogarNoChao()
{
	
}

void Ferramenta::checarEstado() const
{
	
}

void Ferramenta::infoItem() const
{
	cout << "Este Item e uma ferramenta:" << endl;
}

void Ferramenta::destruir()
{
	
}

bool Ferramenta::quebrarBloco(Bloco &)
{
	return true;
}

void Ferramenta::setMaxRes(int maxRes)
{
	this->maxRes = maxRes;
}

void Ferramenta::setAtualRes(int atualRes)
{
	this->atualRes = atualRes;
}

int Ferramenta::getTipoN() const
{
	return -1;
}

string Ferramenta::getTipoS() const
{
	return "";
}
int Ferramenta::getAtualRes() const
{
	return this->atualRes;
}
int Ferramenta::getMaxRes() const
{
	return this->maxRes;
}

Ferramenta::~Ferramenta()
{
	delete this;
}

