#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <typeinfo>

#include "Bloco.h"
#include "Data.h"
#include "Ferramenta.h"
#include "Picareta.h"
#include "Pa.h"
#include "Machado.h"

using namespace std;

int main(int argc, char **argv) {
    Data * data;
    cout << "Qual a data de hoje?" << endl;
    int dia, mes, ano;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;
    data = new Data(dia, mes, ano);

    bool rodando = true;
    int opcao = -1;
    int opcaoInterna = -1;
    char opcaoSN = 's';
    int itemAtivo = 0;

    Picareta *picareta1 = new Picareta(Utensilio::MADEIRA, *data);
    Picareta *picareta2 = new Picareta(Utensilio::FERRO, *data);
    Picareta *picareta3 = new Picareta(Utensilio::DIAMANTE, *data);
    Pa *pa1 = new Pa(Utensilio::MADEIRA, *data);
    Pa *pa2 = new Pa(Utensilio::PEDRA, *data);
    Pa *pa3 = new Pa(Utensilio::DIAMANTE, *data);
    Machado *machado1 = new Machado(Utensilio::MADEIRA, *data);
    Machado *machado2 = new Machado(Utensilio::OURO, *data);
    Machado *machado3 = new Machado(Utensilio::DIAMANTE, *data);

    vector<Ferramenta*> inventario;
    vector<Bloco> mapa;

    float minerioFerroRes[5] = {15.0, 1.15, 0.75, 0.6, 15.0};
    bool minerioFerroColh[5] = {false, true, true, true, false};
    Bloco bF("Minerio de Ferro", minerioFerroRes, minerioFerroColh);
    mapa.push_back(bF);
    float minerioOuroRes[5] = {15.0, 15.0, 0.75, 0.6, 15.0};
    bool minerioOuroColh[5] = {false, false, true, true, false};
    Bloco bO("Minerio de Ouro", minerioOuroRes, minerioOuroColh);
    mapa.push_back(bO);
    float minerioDiamanteRes[5] = {15.0, 15.0, 0.75, 0.6, 15.0};
    bool minerioDiamanteColh[5] = {false, false, true, true, false};
    Bloco bD("Minerio de Diamante", minerioDiamanteRes, minerioDiamanteColh);
    mapa.push_back(bD);

    inventario.push_back(picareta1);
    inventario.push_back(picareta2);
    inventario.push_back(picareta3);
    inventario.push_back(pa1);
    inventario.push_back(pa2);
    inventario.push_back(pa3);
    inventario.push_back(machado1);
    inventario.push_back(machado2);
    inventario.push_back(machado3);

    while (rodando) {
        system("cls");
        cout << "==========Minecraft==========" << endl;
        cout << "Voce tem uma ";
        
        Picareta* derivedPic = dynamic_cast<Picareta*> (inventario[itemAtivo]);
        if (derivedPic != 0) cout << *derivedPic;
        Pa* derivedPa = dynamic_cast<Pa*> (inventario[itemAtivo]);
        if (derivedPa != 0) cout << *derivedPa;
        Machado* derivedMach = dynamic_cast<Machado*> (inventario[itemAtivo]);
        if (derivedMach != 0) cout << *derivedMach;
        
        cout << " na sua mao" << endl;
        cout << "1 - Construir Ferramenta" << endl;
        cout << "2 - Checar Mapa" << endl;
        cout << "3 - Checar Itens" << endl;
        cout << "4 - Checar Inventario" << endl;
        cout << "5 - Sair" << endl;
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Voce deseja construir:" << endl;
                cout << "1 - Uma picareta" << endl;
                cout << "2 - Uma pa" << endl;
                cout << "3 - Um machado" << endl;
                cin >> opcaoInterna;
                switch (opcaoInterna) {
                    case 1:
                        opcaoInterna = Picareta::menuPicareta();
                        inventario[itemAtivo] = new Picareta(opcaoInterna, *data);
                        break;
                    case 2:
                        opcaoInterna = Pa::menuPa();
                        inventario[itemAtivo] = new Pa(opcaoInterna, *data);
                        break;
                    case 3:
                        opcaoInterna = Machado::menuMachado();
                        inventario[itemAtivo] = new Machado(opcaoInterna, *data);
                        break;
                    default:
                        cout << "Numero invalido." << endl;
                }
                //cout << "ate o momento voce so pode ter a picareta padrao" << endl;
                break;
            case 2:
                for (int i = 0; i < (int) mapa.size(); i++) {
                    if (mapa[i].getNome() != "invalid") cout << i << " - " << mapa[i];
                    cout << endl;
                }
                getch();
                cout << "Voce deseja destruir algum bloco? (S/N)" << endl;
                opcaoSN = getch();
                if (opcaoSN == 's') {
                    cout << "Qual bloco vc deseja quebrar?" << endl;
                    cin >> opcaoInterna;
                    if (mapa[opcaoInterna].getNome() != "invalid") {
                        if (inventario[itemAtivo]->quebrarBloco(mapa[opcaoInterna]))
                            mapa[opcaoInterna].setInvalid();
                    } else cout << "bloco invalido";
                    getch();
                } else if (opcaoSN == 'n') {
                    break;
                } else {
                    cout << "opcao invalida" << endl;
                    getch();
                }
                break;
            case 3:
                inventario[itemAtivo]->infoItem();
                getch();
                cout << endl;
                inventario[itemAtivo]->checarEstado();
                getch();
                break;
            case 4:
                cout << "Seu Inventario: " << endl;
                for (int i = 0; i < inventario.size(); i++) {
                    Picareta* derivedPic = dynamic_cast<Picareta*> (inventario[i]);
                    if (derivedPic != 0) cout << i + 1 << " - " << *derivedPic << endl;
                    Pa* derivedPa = dynamic_cast<Pa*> (inventario[i]);
                    if (derivedPa != 0) cout << i + 1 << " - " << *derivedPa << endl;
                    Machado* derivedMach = dynamic_cast<Machado*> (inventario[i]);
                    if (derivedMach != 0) cout << i + 1 << " - " << *derivedMach << endl;
                }
                cout << "Voce desesa trocar o iten da sua mao? (S/N)" << endl;
                opcaoSN = getch();
                if (opcaoSN == 's') {
                    cout << "Qual iten voce deseja pegar?" << endl;
                    cin >> opcaoInterna;
                    if (opcaoInterna < 1 || opcaoInterna > inventario.size()) {
                        cout << "Numero invalido" << endl;
                        cout << "voce nao trocou de ferramenta" << endl;
                    } else {
                        itemAtivo = opcaoInterna;
                        cout << "Voce tem em suas maos um(a) " << *inventario[itemAtivo] << endl;
                    }
                    getch();
                } else if (opcaoSN == 'n') {
                    break;
                } else {
                    cout << "opcao invalida" << endl;
                    getch();
                }
                break;
            case 5:
                cout << "Fechando o Minecraft";
                for (int i = 0; i < 3; i++) {
                    Sleep(150);
                    cout << '.';
                }
                Sleep(150);
                return 0;
                break;
            default:
                cout << "Opcao Invalida";
                getch();
                break;
        }
    }

    delete picareta1;
    delete picareta2;
    delete picareta3;
    delete pa1;
    delete pa2;
    delete pa3;
    delete machado1;
    delete machado2;
    delete machado3;
    delete data;

    system("pause");
    return 0;
}
