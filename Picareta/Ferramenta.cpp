#include "Ferramenta.h"
#include "Bloco.h"
#include "Data.h"

ostream &operator<< (ostream &output, const Ferramenta &ferramenta){
	output << ferramenta.getTipoDaFerramenta();
	return output;
}



Ferramenta::Ferramenta(int tipoFerramenta, Data & dataDeCriacao)
{
	const_cast<int&>(this->tipoFerramentaN) = tipoFerramenta;
	this->setTipoFerramentaS(tipoFerramenta);
	this->dataDeCriacao = new Data(dataDeCriacao);// criado usando um construtor cópia que foi aparentemente gerado pelo compilador.
}

Ferramenta::Ferramenta(int tipoFerramenta, int maxRes, float atualRes, Data & dataDeCriacao)
{
	const_cast<int&>(this->tipoFerramentaN) = tipoFerramenta;
	this->setTipoFerramentaS(tipoFerramenta);
	this->setMaxRes(maxRes);
	this->setAtualRes(atualRes);
	this->dataDeCriacao = new Data(dataDeCriacao);// criado usando um construtor cópia que foi aparentemente gerado pelo compilador.
}

void Ferramenta::jogarNoChao()
{
	
}

void Ferramenta::checarEstado() const
{
	
}

void Ferramenta::infoItem() const
{
	cout << "Ferramenta criada no dia: ";
	dataDeCriacao->print();
	cout << endl << "Este Item e ";
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
	const_cast<int&>(this->maxRes) = maxRes;
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

void Ferramenta::setTipoFerramentaS(int tipo)
{
	switch(this->tipoFerramentaN)
	{
		case TIPO_PICARETA:
			const_cast<string&>(this->tipoFerramentaS) = "Picareta";
			break;
	}
}

string Ferramenta::getTipoDaFerramenta() const
{
	return this->tipoFerramentaS;
}

Ferramenta Ferramenta::operator =(Ferramenta fer)
{
	Ferramenta ferramenta(fer.tipoFerramentaN, fer.maxRes, fer.atualRes, *fer.dataDeCriacao);
	
	//ferramenta.atualRes = fer.atualRes;
	//ferramenta.dataDeCriacao = fer.dataDeCriacao;
	//ferramenta.maxRes = fer.maxRes;
	//ferramenta.setTipoFerramentaS(fer.tipoFerramentaN);
	
	return ferramenta;
}

Ferramenta::~Ferramenta()
{
	delete dataDeCriacao;
	//delete this;
}

