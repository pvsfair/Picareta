#include "Picareta.h"
#include "Bloco.h"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

Picareta::Picareta(string tipoS, int tipoN, int maxRes, int atualRes, Bloco matMine) : Ferramenta(TIPO_PICARETA, maxRes, atualRes)
{
	this->setTipoS(tipoS);
	this->setTipoN(tipoN);
	this->setMatMine(matMine);
}

Picareta::Picareta(const Picareta &pic) : Ferramenta(TIPO_PICARETA, pic.maxRes, pic.atualRes)
{
	this->tipoN = pic.tipoN;
	this->tipoS = pic.tipoS;
	this->matMine = pic.matMine;
}

Picareta::Picareta(int tipoN) : Ferramenta(TIPO_PICARETA)
{
	this->setTipoN(tipoN);
	switch(tipoN)
	{
		case MADEIRA:
			this->setTipoS("madeira");
			this->setMaxRes(60);
			break;
		case PEDRA:
			this->setTipoS("pedra");
			this->setMaxRes(132);
			break;
		case FERRO:
			this->setTipoS("ferro");
			this->setMaxRes(251);
			break;
		case DIAMANTE:
			this->setTipoS("diamante");
			this->setMaxRes(1563);
			break;
		case OURO:
			this->setTipoS("ouro");
			this->setMaxRes(33);
			break;
		default:
			cout << "Err\n";
	}
	this->setAtualRes(maxRes);
	this->matMine = Bloco();
	
}
void Picareta::setTipoN(int tipoN)
{
	if(tipoN > OURO || tipoN < MADEIRA)
		cout << "Numero invalido para tipo de ferramenta\n";
	else
		this->tipoN = tipoN;
}

void Picareta::setTipoS(string tipoS)
{
	locale loc;
	string local;
	for(string::size_type i = 0; i < tipoS.length(); i++)
	{
		local.push_back(tolower(tipoS[i], loc));
	}
	if((local != "madeira") && (local != "pedra") && (local != "ferro") && (local != "diamante") && (local != "ouro"))
	{
		cout << "String invalida para tipo de ferramenta\n" << local;
	} else
		this->tipoS = local;
}

void Picareta::setMatMine(Bloco b)
{
	this->matMine = b;
}

void Picareta::jogarNoChao()
{
	cout << "Voce jogou sua picareta de " << this->tipoS << " no chao" << endl;
}

void Picareta::checarEstado() const
{
	cout << "Sua picareta de " << this->tipoS << " esta com " << (this->atualRes / this->maxRes) * 100 << "% de resistencia ";
	cout << "(" << this->atualRes << " de " << this->maxRes << ")" << endl;
}

void Picareta::exibirMensagem() const
{
	
}

void Picareta::destruir()
{
	
}

bool Picareta::quebrarBloco(Bloco &b)
{
	this->atualRes--;
	return b.quebrarBloco(this);
}

int Picareta::getTipoN() const
{
	return this->tipoN;
}

Picareta::~Picareta()
{
	
}

