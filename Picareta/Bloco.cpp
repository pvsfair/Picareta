#include <conio.h>
#include <windows.h>
#include "Bloco.h"

using namespace std;
//Construtores
Bloco::Bloco()
{
	this->nome = "invalid";
}

Bloco::Bloco(const Bloco &bloco)
{
	this->nome = bloco.nome;
	this->resMat = bloco.resMat;
	this->colherMat = bloco.colherMat;
}

Bloco::Bloco(string nome, float resMat[5], bool colherMat[5])
{
	this->setNome(nome);
	this->setResMat(resMat);
	this->setColherMat(colherMat);
}
//Fim construtores

//Funcoes
bool Bloco::quebrarBloco(Ferramenta * const f)
{
	int tipo = f->getTipoN();
	cout << "Quebrando Bloco" << endl << "Para cancelar aperte C";
	int oldTime;
	for(int i = 0; i < resMat[tipo] * 100; i++)
	{
		Sleep(1);
		if(kbhit())
			if(getch() == 'c') break;
		int time = i / 1000;
		if(time != oldTime) cout << time + 1 << endl; 
		oldTime = time;
	}
	return colherMat[tipo];
}
//Operator
Bloco Bloco::operator = (Bloco b)
{
	Bloco bloco;
	
	bloco.nome = b.nome;
	bloco.resMat = b.resMat;
	bloco.colherMat = b.colherMat;
	
	return bloco;
}
//Fim funcoes

//Get's e Set's
void Bloco::setNome(string nome)
{
	this->nome = nome;
}

void Bloco::setResMat(float resMat[5])
{
	this->resMat = vector<float>(resMat,  resMat + sizeof(resMat) / sizeof(float));
}

void Bloco::setColherMat(bool colherMat[5])
{
	this->colherMat = vector<bool>(colherMat,  colherMat + sizeof(colherMat) / sizeof(bool));
}

string Bloco::getNome() const
{
	return this->nome;
}

vector<float> Bloco::getResMat() const
{
	return this->resMat;
}

vector<bool> Bloco::getColherMat() const
{
	return this->colherMat;
}
//Fim Get's e Set's

Bloco::~Bloco()
{
	
}

