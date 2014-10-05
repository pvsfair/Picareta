#include "Ferramenta.h"
#include "Bloco.h"

Ferramenta::Ferramenta(int tipoFerramenta)
{
	this->tipoFerramenta = tipoFerramenta;
}
Ferramenta::Ferramenta(int tipoFerramenta, int maxRes, int atualRes)
{
	this->tipoFerramenta = tipoFerramenta;
	this->maxRes = maxRes;
	this->atualRes = atualRes;
}

void Ferramenta::jogarNoChao()
{
	
}

void Ferramenta::checarEstado() const
{
	
}

void Ferramenta::exibirMensagem() const
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

Ferramenta::~Ferramenta()
{
}

