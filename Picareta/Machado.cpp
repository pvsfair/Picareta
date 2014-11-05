#include "Machado.h"
#include "Bloco.h"
#include "Data.h"
#include "Ferramenta.h"

using namespace std;

int Machado::numMachadosQuebrados = 0;

ostream &operator<<(ostream &output, const Machado &machado) {
    output << static_cast<const Ferramenta&> (machado);
    output << " de " << machado.getTipoS();
    return output;
}

Machado::Machado(string tipoS, int tipoN, int maxRes, int atualRes, Bloco* arvoreObjetivo, Data* dataDeCriacao) : Ferramenta(TIPO_MACHADO, maxRes, atualRes, dataDeCriacao) {
    this->setTipoS(tipoS);
    this->setTipoN(tipoN);
    this->arvoreObjetivo = new Bloco(*arvoreObjetivo);
}

Machado::Machado(const Machado& machado) : Ferramenta(TIPO_MACHADO, machado.maxRes, machado.atualRes, machado.getDataDeCriacao()) {
    const_cast<int&> (this->tipoN) = machado.tipoN;
    const_cast<string&> (this->tipoS) = machado.tipoS;
    this->arvoreObjetivo = new Bloco(*arvoreObjetivo);
}

Machado::Machado(int tipoN, Data& dataDeCriacao) : Ferramenta(TIPO_MACHADO, &dataDeCriacao) {
    this->setTipoN(tipoN);
    switch (tipoN) {
        case MADEIRA:
            this->setTipoS("madeira");
            this->setMaxRes(60);
            break;
        case PEDRA:
            this->setTipoS("pedra");
            this->setMaxRes(132);
            break;
        case FERRO:
            this->setTipoS("ferro");
            this->setMaxRes(251);
            break;
        case DIAMANTE:
            this->setTipoS("diamante");
            this->setMaxRes(1563);
            break;
        case OURO:
            this->setTipoS("ouro");
            this->setMaxRes(33);
            break;
        default:
            cout << "Err\n";
    }
    this->setAtualRes(maxRes);
    this->arvoreObjetivo = new Bloco();
}

Machado::Machado() : Ferramenta(TIPO_MACHADO, new Data()) {
    this->setTipoS(Utensilio::MADEIRA);
    this->setTipoN(0);
    this->setArvoreObjetivo(new Bloco());
    this->setTipoS("madeira");
    this->setMaxRes(60);
}

void Machado::brandirMachado() {
    cout << "vosh!!" << endl;
    cout << "vosh!!" << endl;
    cout << "eieiei!!!, cuidado com esse machado ai!" << endl;
}

void Machado::checarEstado() const {
    cout << "Sua " << *this << " esta com " << (this->atualRes / this->maxRes) * 100.0 << "% de resistencia ";
    cout << "(" << this->atualRes << " de " << this->maxRes << ")" << endl;
}

void Machado::infoItem() const {
    Ferramenta::infoItem();
    cout << "uma " << *this << '.' << endl;
}

void Machado::jogarNoChao() {
    cout << "Voce jogou o seu " << *this << " no chao" << endl;
}

int Machado::menuMachado() {
    int opcao = -1;
    cout << "Menu de criacao de Machado" << endl;
    cout << "Voce deseja criar um machado de qual material?" << endl;
    cout << "1 - Madeira" << endl;
    cout << "2 - Pedra" << endl;
    cout << "3 - Ferro" << endl;
    cout << "4 - Diamante" << endl;
    cout << "5 - Ouro" << endl;
    cin >> opcao;
    while (opcao > 5 || opcao < 1) {
        cout << "Por favor, escolha uma opcao valida" << endl;
        cout << "Menu de criacao de Machado" << endl;
        cout << "Voce deseja criar um machado de qual material?" << endl;
        cout << "1 - Madeira" << endl;
        cout << "2 - Pedra" << endl;
        cout << "3 - Ferro" << endl;
        cout << "4 - Diamante" << endl;
        cout << "5 - Ouro" << endl;
        cin >> opcao;
    }
    return opcao - 1;
}

Machado Machado::operator=(Machado& machado) {
    return machado;
}

bool Machado::quebrarBloco(Bloco& bloco) {
    if (atualRes > 0) {
        this->atualRes--;
        bool caiuNoChao = bloco.quebrarBloco(this);
        if (atualRes == 0) this->destruir();
        return caiuNoChao;
    } else {
        cout << "Voce nao deveria usar um machado quebrado..." << endl;
        cout << "Construa um machado novo" << endl;
        return false;
    }
}

void Machado::setArvoreObjetivo(Bloco* arvoreObjetivo) {
    this->arvoreObjetivo = new Bloco(*arvoreObjetivo);
}

void Machado::setTipoS(string) {
    locale loc;
    string local;
    for (string::size_type i = 0; i < tipoS.length(); i++) {
        local.push_back(tolower(tipoS[i], loc));
    }
    if ((local != "madeira") && (local != "pedra") && (local != "ferro") && (local != "diamante") && (local != "ouro")) {
        cout << "String invalida para tipo de ferramenta" << local << endl;
    } else
        const_cast<string&> (this->tipoS) = local;
}

void Machado::setTipoN(int tipoN) {
    if (tipoN > OURO || tipoN < MADEIRA)
        cout << "Numero invalido para tipo de ferramenta\n";
    else
        const_cast<int&> (this->tipoN) = tipoN;
}

int Machado::getTipoN() const {
    return tipoN;
}

string Machado::getTipoS() const {
    return this->tipoS;
}

Machado::~Machado() {
    delete arvoreObjetivo;
}
