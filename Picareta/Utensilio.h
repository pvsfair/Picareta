#ifndef UTENSILIO_H
#define UTENSILIO_H

#include <iostream>

using namespace std;

class Utensilio {
    friend ostream &operator<<(ostream &output, const Utensilio &utensilio);
public:
    Utensilio();
    Utensilio(int, float);
    virtual void jogarNoChao() = 0;
    virtual void checarEstado() const = 0;
    virtual void infoItem() const = 0;
    virtual inline void destruir() = 0;

    virtual int getTipoN() const;
    virtual string getTipoS() const;
    virtual void setTipoN(int);
    virtual void setTipoS(string);

    virtual ~Utensilio();
protected:
    string nome;
    const int maxRes = 0;
    float atualRes;
    const int tipoN = 0;
    const string tipoS = "";
    
};

#endif // UTENSILIO_H
