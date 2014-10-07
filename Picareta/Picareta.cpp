#include "Picareta.h"
#include "Bloco.h"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int Picareta::numPicaretasQuebradas = 0;

//CONSTRUTORES
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
//FIM CONSTRUTORES
//GET'S e SET'S
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
		cout << "String invalida para tipo de ferramenta" << local << endl;
	} else
		this->tipoS = local;
}

void Picareta::setMatMine(Bloco b)
{
	this->matMine = b;
}

int Picareta::getTipoN() const
{
	return this->tipoN;
}
//FIM GET'S e SET'S

int Picareta::menuPicareta()
{
	
	return 0;
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

bool Picareta::quebrarBloco(Bloco &b)
{
	if(atualRes > 0)
	{
		this->atualRes--;
		return b.quebrarBloco(this);
		if(atualRes == 0) this->destruir();
	}
	else
	{
		cout << "Voce nao deveria usar uma picareta quebrada..." << endl;
	}
}

string Picareta::getTipoS() const
{
	return this->tipoS;
}

Picareta::~Picareta()
{
	
}

