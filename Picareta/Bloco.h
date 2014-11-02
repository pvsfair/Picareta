#ifndef BLOCO_H
#define BLOCO_H

#include <iostream>
#include <vector>
#include "Ferramenta.h"

using namespace std;

class Bloco
{
	friend ostream &operator<< (ostream &, const Bloco &);
	
public:
	Bloco();
	Bloco(const Bloco &);
	Bloco(string, float[5], bool[5]);
	bool quebrarBloco(const Ferramenta *);
	
	void setNome(string);
	void setResMat(float[5]);
	void setColherMat(bool[5]);
	inline void setInvalid()
	{
		this->nome = "invalid";
	}
	
	string getNome() const;
	vector<float> getResMat() const;
	vector<bool> getColherMat() const;
	
	Bloco operator = (Bloco b);
	
	~Bloco();
	
private:
	string nome;
	vector<float> resMat;
	vector<bool> colherMat;

};

#endif // BLOCO_H
