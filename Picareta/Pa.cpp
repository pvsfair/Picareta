#include "Pa.h"
#include "Bloco.h"
#include "Ferramenta.h" 
#include "Data.h"

#include <iostream>
#include <windows.h>
#include <stdlib.h>

using namespace std;

int Pa::numPasQuebradas = 0;

ostream &operator<<(ostream &output, const Pa &pa) {
    output << static_cast<const Ferramenta&> (pa);
    output << " de " << pa.getTipoS();
    return output;
}

Pa::Pa(string tipoS, int tipoN, int maxRes, int atualRes, Bloco* blocoObjetivo, Data* dataDeCriacao) : Ferramenta(TIPO_PA, maxRes, atualRes, dataDeCriacao) {
    this->setTipoS(tipoS);
    this->setTipoN(tipoN);
    this->blocoObjetivo = new Bloco(*blocoObjetivo);
}

Pa::Pa(const Pa& pa) : Ferramenta(TIPO_PA, pa.maxRes, pa.atualRes, pa.getDataDeCriacao()) {
    const_cast<int&> (this->tipoN) = pa.tipoN;
    const_cast<string&> (this->tipoS) = pa.tipoS;
    this->blocoObjetivo = new Bloco(*pa.blocoObjetivo);
}

Pa::Pa(int tipoN, Data& dataDeCriacao) : Ferramenta(TIPO_PA, &dataDeCriacao) {
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
    this->blocoObjetivo = new Bloco();
}

Pa::Pa() : Ferramenta(TIPO_PA, new Data()) {
    this->setTipoS(Utensilio::MADEIRA);
    this->setTipoN(0);
    this->setBlocoObetivo(new Bloco());
    this->setTipoS("madeira");
    this->setMaxRes(60);
}

bool Pa::cavarParaBaixo() {
    cout << "Voce tem certeza que quer fazer isso?(S/N)" << endl;
    char sn;
    cin >> sn;
    if (sn == 's' || sn == 'S') {
        cout << "Cavando para baixo" << endl;
        system("cls");
        for (int i = 0; i < 20; i++) {
            cout << '.' << endl;
            Sleep(200);
        }
        cout << "PARABENS!! Voce chegou ao final do mapa, e caiu do mundo!" << endl;
        cout << "Voce se matou!!" << endl;
        return true;
    } else {
        cout << "Otima escolha, jovem padawan!" << endl;
        return false;
    }
}

void Pa::checarEstado() const {
    cout << "Sua " << *this << " esta com " << (this->atualRes / this->maxRes) * 100.0 << "% de resistencia ";
    cout << "(" << this->atualRes << " de " << this->maxRes << ")" << endl;
}

void Pa::infoItem() const {
    Ferramenta::infoItem();
    cout << "uma " << *this << '.' << endl;
}

void Pa::jogarNoChao() {
    cout << "Voce jogou a sua " << *this << " no chao" << endl;
}

int Pa::menuPa() {
    int opcao = -1;
    cout << "Menu de criacao de Pa" << endl;
    cout << "Voce deseja criar uma pa de qual material?" << endl;
    cout << "1 - Madeira" << endl;
    cout << "2 - Pedra" << endl;
    cout << "3 - Ferro" << endl;
    cout << "4 - Diamante" << endl;
    cout << "5 - Ouro" << endl;
    cin >> opcao;
    while (opcao > 5 || opcao < 1) {
        cout << "Por favor, escolha uma opcao valida" << endl;
        cout << "Menu de criacao de Pa" << endl;
        cout << "Voce deseja criar uma pa de qual material?" << endl;
        cout << "1 - Madeira" << endl;
        cout << "2 - Pedra" << endl;
        cout << "3 - Ferro" << endl;
        cout << "4 - Diamante" << endl;
        cout << "5 - Ouro" << endl;
        cin >> opcao;
    }
    return opcao - 1;
}

Pa Pa::operator=(Pa& pa) {
    return pa;
}

bool Pa::quebrarBloco(Bloco& bloco) {
    if (atualRes > 0) {
        this->atualRes--;
        bool caiuNoChao = bloco.quebrarBloco(this);
        if (atualRes == 0) this->destruir();
        return caiuNoChao;
    } else {
        cout << "Voce nao deveria usar uma pa quebrada..." << endl;
        cout << "Construa uma pa nova" << endl;
        return false;
    }
}

void Pa::setBlocoObetivo(Bloco* blocoObjetivo) {
    this->blocoObjetivo = new Bloco(*blocoObjetivo);
}

void Pa::setTipoS(string tipoS) {
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

void Pa::setTipoN(int tipoN) {
    if (tipoN > OURO || tipoN < MADEIRA)
        cout << "Numero invalido para tipo de ferramenta\n";
    else
        const_cast<int&> (this->tipoN) = tipoN;
}

int Pa::getTipoN() const {
    return tipoN;
}

string Pa::getTipoS() const {
    return this->tipoS;
}

Pa::~Pa() {
    delete blocoObjetivo;
}





