#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Bloco.h"
#include "Data.h"
#include "Ferramenta.h"
#include "Picareta.h"

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
    Picareta *picareta = new Picareta(0, *data);
    picareta->getDataDeCriacao()->print();
    getch();
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

    while (rodando) {
        system("cls");
        cout << "==========Minecraft==========" << endl;
        cout << "Voce tem uma " << *picareta << " na sua mao" << endl;
        cout << "1 - Construir Picareta" << endl;
        cout << "2 - Checar Mapa" << endl;
        cout << "3 - Checar Itens" << endl;
        cout << "4 - Sair" << endl;
        cin >> opcao;
        switch (opcao) {
            case 1:
                opcaoInterna = Picareta::menuPicareta();
                picareta = new Picareta(opcaoInterna, *data);
                //cout << "ate o momento voce so pode ter a picareta padrao" << endl;
                break;
            case 2:
                for (int i = 0; i < (int) mapa.size(); i++) {
                    if (mapa[i].getNome() != "invalid") cout << i << " - " << mapa[i];
                    cout << endl;
                }
                getch();
                cout << "Voce deseja destruir algum bloco?" << endl;
                opcaoSN = getch();
                if (opcaoSN == 's') {
                    cout << "Qual bloco vc deseja quebrar?" << endl;
                    cin >> opcaoInterna;
                    if (mapa[opcaoInterna].getNome() != "invalid") {
                        if (picareta->quebrarBloco(mapa[opcaoInterna]))
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
                picareta->infoItem();
                getch();
                cout << endl;
                picareta->checarEstado();
                getch();
                break;
            case 4:
                cout << "Fechando o Minecraft";
                for (int i = 0; i < 3; i++) {
                    Sleep(150);
                    cout << '.';
                }
                Sleep(150);
                return 0;
                break;
            case 5:
                delete picareta;
                break;
            default:
                cout << "Opcao Invalida";
                getch();
                break;
        }
    }

    delete picareta;
    delete data;

    system("pause");
    return 0;
}
