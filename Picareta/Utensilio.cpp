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

Utensilio::Utensilio(int maxRes, float atualRes) {
    const_cast<int&> (this->maxRes) = maxRes;
    this->atualRes = maxRes;
}

Utensilio::~Utensilio() {
}

