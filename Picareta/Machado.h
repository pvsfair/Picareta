#ifndef MACHADO_H
#define MACHADO_H

#include "Ferramenta.h"
#include <iostream>
#include "Bloco.h"

using namespace std;

class Machado : public Ferramenta {
    friend ostream &operator<<(ostream &, const Machado &);
public:
    Machado(string, int = 0, int = 60, int = 60, Bloco * = new Bloco(), Data * = new Data());
    Machado(const Machado &);
    Machado(int, Data &);
    Machado();

    static int menuMachado();

    void brandirMachado();

    virtual bool quebrarBloco(Bloco&);

    virtual void jogarNoChao();

    virtual void checarEstado() const;

    virtual void infoItem() const;

    virtual void destruir() {
        Machado::numMachadosQuebrados++;
        cout << "O seu " << *this << " acabou de quebrar." << endl;
        cout << "Construa outra ferramenta." << endl;
    }

    void setArvoreObjetivo(Bloco *);

    virtual int getTipoN() const;
    virtual string getTipoS() const;

    virtual void setTipoN(int);
    virtual void setTipoS(string);

    Machado operator=(Machado&);

    virtual ~Machado();
private:
    static int numMachadosQuebrados;
    Bloco * arvoreObjetivo;
};

#endif // MACHADO_H
