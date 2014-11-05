#include "Utensilio.h"
#include "Ferramenta.h"

using namespace std;

ostream &operator<<(ostream &output, const Utensilio &utensilio) {
    output << utensilio.nome;
    return output;
}

Utensilio::Utensilio(){
    this->atualRes = this->maxRes;
}

int Utensilio::getTipoN() const{
    return this->tipoN;
}

string Utensilio::getTipoS() const{
    return this->tipoS;
}

void Utensilio::setTipoN(int tipoN){
    const_cast<int&>(tipoN) = tipoN;
}

void Utensilio::setTipoS(string tipoS){
    const_cast<string&>(tipoS) = tipoS;
}

Utensilio::Utensilio(int maxRes, float atualRes) {
    const_cast<int&> (this->maxRes) = maxRes;
    this->atualRes = maxRes;
}

Utensilio::~Utensilio() {
}

