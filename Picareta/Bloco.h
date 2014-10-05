#ifndef BLOCO_H
#define BLOCO_H

#include <iostream>
#include <vector>
class Ferramenta;

using namespace std;

class Bloco
{
public:
	Bloco();
	Bloco(const Bloco &);
	Bloco(string, float[5], bool[5]);
	bool quebrarBloco(Ferramenta &);
	
	void setNome(string);
	void setResMat(float[5]);
	void setColherMat(bool[5]);
	
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
