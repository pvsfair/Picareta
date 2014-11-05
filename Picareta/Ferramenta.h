#ifndef FERRAMENTA_H
#define FERRAMENTA_H

#include <iostream>
#include "Data.h"
#include "Utensilio.h"
class Bloco;

using namespace std;

class Ferramenta : public Utensilio {
    friend ostream &operator<<(ostream &, const Ferramenta &);
public:
    const static int TIPO_PICARETA = 0;
    const static int TIPO_PA = 1;
    const static int TIPO_MACHADO = 2;

    Ferramenta();
    Ferramenta(int, Data * = new Data());
    Ferramenta(int, int, float, Data *);

    virtual void infoItem() const;
    virtual bool quebrarBloco(Bloco &)=0;


    virtual int getAtualRes() const;
    virtual int getMaxRes() const;
    virtual string getTipoDaFerramenta() const;
    virtual Data* getDataDeCriacao() const;

    virtual ~Ferramenta();
private:
    const int tipoFerramentaN = 0;
    const string tipoFerramentaS = "";
    void setTipoFerramentaS(int);
    Data * dataDeCriacao;
protected:

    void setMaxRes(int);
    void setAtualRes(int);
};

#endif // FERRAMENTA_H
