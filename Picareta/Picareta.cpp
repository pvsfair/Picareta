#include "Picareta.h"
#include "Bloco.h"
#include <iostream>
#include <string>
#include <locale>

using namespace std;

int Picareta::numPicaretasQuebradas = 0;

ostream &operator<< (ostream &output, const Picareta &picareta){
	output << static_cast<Ferramenta>(picareta);
	output << " de " << picareta.getTipoS();
	return output;
}

//CONSTRUTORES
Picareta::Picareta(string tipoS, int tipoN, int maxRes, int atualRes, Bloco * matMine, Data * dataDeCriacao) : Ferramenta(TIPO_PICARETA, maxRes, atualRes, *dataDeCriacao)
{
	this->setTipoS(tipoS);
	this->setTipoN(tipoN);
	this->setMatMine(*matMine);
	cout << "Dentro do Construtor 1" << endl;
}

Picareta::Picareta(const Picareta &pic) : Ferramenta(TIPO_PICARETA, pic.maxRes, pic.atualRes, *pic.getDataDeCriacao())
{
	const_cast<int&>(this->tipoN) = pic.tipoN;
	const_cast<string&>(this->tipoS) = pic.tipoS;
	this->matMine = new Bloco(*pic.matMine);
	cout << "Dentro do Construtor 2" << endl;
}

Picareta::Picareta(int tipoN, Data & dataDeCriacao) : Ferramenta(TIPO_PICARETA, dataDeCriacao)
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
	this->matMine = new Bloco();	
	cout << "Dentro do Construtor 3" << endl;
}
//FIM CONSTRUTORES
//GET'S e SET'S
void Picareta::setTipoN(int tipoN)
{
	if(tipoN > OURO || tipoN < MADEIRA)
		cout << "Numero invalido para tipo de ferramenta\n";
	else
		const_cast<int&>(this->tipoN) = tipoN;
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
		const_cast<string&>(this->tipoS) = local;
}

void Picareta::setMatMine(Bloco & b)
{
	this->matMine = new Bloco(b);
}

int Picareta::getTipoN() const
{
	return this->tipoN;
}
//FIM GET'S e SET'S

int Picareta::menuPicareta()
{
	int opcao = -1;
	cout << "Menu de criação de Picareta" << endl;
	cout << "Voce deseja criar uma picareta de qual material?" << endl;
	cout << "1 - Madeira" << endl;
	cout << "2 - Pedra" << endl;
	cout << "3 - Ferro" << endl;
	cout << "4 - Diamante" << endl;
	cout << "5 - Ouro" << endl;
	cin >> opcao;
	while(opcao > 5 || opcao < 1)
	{
		cout << "Por favor, escolha uma opcao valida" << endl;
		cout << "Menu de criação de Picareta" << endl;
		cout << "Voce deseja criar uma picareta de qual material?" << endl;
		cout << "1 - Madeira" << endl;
		cout << "2 - Pedra" << endl;
		cout << "3 - Ferro" << endl;
		cout << "4 - Diamante" << endl;
		cout << "5 - Ouro" << endl;
		cin >> opcao;
	}
	return opcao - 1;
}

void Picareta::jogarNoChao()
{
	cout << "Voce jogou sua picareta de " << this->tipoS << " no chao" << endl;
}

void Picareta::checarEstado() const
{
	cout << "Sua picareta de " << this->tipoS << " esta com " << (this->atualRes / this->maxRes) * 100.0 << "% de resistencia ";
	cout << "(" << this->atualRes << " de " << this->maxRes << ")" << endl;
}

void Picareta::infoItem() const
{
	Ferramenta::infoItem();
	cout << "uma Picareta de " << this->tipoS << '.' << endl;
}

bool Picareta::quebrarBloco(Bloco &b)
{
	if(atualRes > 0)
	{
		this->atualRes--;
		bool caiuNoChao = b.quebrarBloco(this);
		if(atualRes == 0) this->destruir();
		return caiuNoChao;
	}
	else
	{
		cout << "Voce nao deveria usar uma picareta quebrada..." << endl;
		cout << "Construa uma picareta nova" << endl;
		return false;
	}
}

string Picareta::getTipoS() const
{
	return this->tipoS;
}

Picareta Picareta::operator =(Picareta pic)
{
	Picareta picareta(pic);
	
	cout << "Dentro de picareta" << endl;
	
	return picareta;
}

Picareta::~Picareta()
{
	delete matMine;
	//delete this;
}

