#ifndef UTENSILIO_H
#define UTENSILIO_H

#include <iostream>

using namespace std;

class Utensilio
{
    friend ostream &operator<<(ostream &output, Utensilio &utensilio);
public:
	Utensilio(int, float);
        virtual void jogarNoChao() = 0;
        virtual void checarEstado() = 0;
        virtual void infoItem() = 0;
        virtual void destruir()= 0;
        
	virtual ~Utensilio();
private:
    string nome;
    const int maxRes = 0;
    float atualRes;
};

#endif // UTENSILIO_H
