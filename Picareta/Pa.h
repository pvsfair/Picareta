#ifndef PA_H
#define PA_H

#include <iostream>
#include "Bloco.h"

using namespace std;

class Pa : public Ferramenta {
    friend ostream &operator<<(ostream &, const Pa &);
public:
    Pa(string, int = 0, int = 60, int = 60, Bloco * = new Bloco(), Data * = new Data());
    Pa(const Pa &);
    Pa(int, Data &);
    Pa();

    static int menuPa();

    bool cavarParaBaixo();

    virtual bool quebrarBloco(Bloco&);

    virtual void jogarNoChao();

    virtual void checarEstado() const;

    virtual void infoItem() const;

    virtual inline void destruir() {
        Pa::numPasQuebradas++;
        cout << "A sua " << *this << " acabou de quebrar." << endl;
        cout << "Construa outra ferramenta." << endl;
    }

    void setBlocoObetivo(Bloco *);

    virtual int getTipoN() const;
    virtual string getTipoS() const;

    virtual void setTipoN(int);
    virtual void setTipoS(string);


    Pa operator=(Pa &);

    virtual ~Pa();

private:
    static int numPasQuebradas;
    Bloco * blocoObjetivo;

};

#endif // PA_H
