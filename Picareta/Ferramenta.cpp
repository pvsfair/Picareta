#include "Ferramenta.h"
#include "Bloco.h"
#include "Data.h"

ostream &operator<<(ostream &output, const Ferramenta &ferramenta) {
    output << ferramenta.getTipoDaFerramenta();
    return output;
}

Ferramenta::Ferramenta(){
    
}
Ferramenta::Ferramenta(int tipoFerramenta, Data * dataDeCriacao) {
    const_cast<int&> (this->tipoFerramentaN) = tipoFerramenta;
    this->setTipoFerramentaS(tipoFerramenta);
    this->dataDeCriacao = new Data(*dataDeCriacao); // criado usando um construtor cópia que foi aparentemente gerado pelo compilador.
    cout << 1;
    this->dataDeCriacao->print();
    cout << endl;
    dataDeCriacao->print();
}

Ferramenta::Ferramenta(int tipoFerramenta, int maxRes, float atualRes, Data * dataDeCriacao) : Utensilio(maxRes, atualRes) {
    const_cast<int&> (this->tipoFerramentaN) = tipoFerramenta;
    this->setTipoFerramentaS(tipoFerramenta);
    this->setMaxRes(maxRes);
    this->setAtualRes(atualRes);
    this->dataDeCriacao = new Data(*dataDeCriacao); // criado usando um construtor cópia que foi aparentemente gerado pelo compilador.
    cout << 2;
    this->dataDeCriacao->print();
    cout << endl;
    dataDeCriacao->print();

}

void Ferramenta::infoItem() const {
    cout << "Ferramenta criada no dia: ";
    this->dataDeCriacao->print();
    cout << endl << "Este Item e ";
}

// <editor-fold defaultstate="collapsed" desc="Get's e Set's">

void Ferramenta::setMaxRes(int maxRes) {
    const_cast<int&> (this->maxRes) = maxRes;
}

void Ferramenta::setAtualRes(int atualRes) {
    this->atualRes = atualRes;
}

int Ferramenta::getAtualRes() const {
    return this->atualRes;
}

int Ferramenta::getMaxRes() const {
    return this->maxRes;
}

Data* Ferramenta::getDataDeCriacao() const {
    return this->dataDeCriacao;
}

void Ferramenta::setTipoFerramentaS(int tipo) {
    switch (this->tipoFerramentaN) {
        case TIPO_PICARETA:
            const_cast<string&> (this->tipoFerramentaS) = "Picareta";
            break;
        case TIPO_PA:
            const_cast<string&> (this->tipoFerramentaS) = "Pa";
            break;
        case TIPO_MACHADO:
            const_cast<string&> (this->tipoFerramentaS) = "Machado";
            break;
            
    }
}

string Ferramenta::getTipoDaFerramenta() const {
    return this->tipoFerramentaS;
}// </editor-fold>


Ferramenta::~Ferramenta() {
    delete dataDeCriacao;
    //delete this;
}

