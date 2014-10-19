#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#include "Bloco.h"
#include "Ferramenta.h"
#include "Picareta.h"

using namespace std;

int main(int argc, char **argv)
{
	bool rodando = true;
	int opcao = -1;
	int opcaoInterna = -1;
	char opcaoSN = 's';
	Picareta *picareta;
	picareta = new Picareta(0);
	vector<Bloco> mapa;
	
	
	float minerioFerroRes[5] = {15.0, 1.15, 0.75, 0.6, 15.0};
	bool minerioFerroColh[5] = {false, true, true, true, false};
	Bloco bF("Minerio de Ferro",  minerioFerroRes, minerioFerroColh);
	mapa.push_back(bF);
	float minerioOuroRes[5] = {15.0, 15.0, 0.75, 0.6, 15.0};
	bool minerioOuroColh[5] = {false, false, true, true, false};
	Bloco bO("Minerio de Ouro",  minerioOuroRes, minerioOuroColh);
	mapa.push_back(bO);
	float minerioDiamanteRes[5] = {15.0, 15.0, 0.75, 0.6, 15.0};
	bool minerioDiamanteColh[5] = {false, false, true, true, false};
	Bloco bD("Minerio de Diamante",  minerioDiamanteRes, minerioDiamanteColh);
	mapa.push_back(bD);
	
	while(rodando)
	{
		system("cls");
		cout << "==========Minecraft==========" << endl;
		cout << "Você tem uma picareta de " << picareta->getTipoS() << " na sua mao" << endl;
		cout << "1 - Construir Picareta" << endl;
		cout << "2 - Checar Mapa" << endl;
		cout << "3 - Sair" << endl;
		cin >> opcao;
		switch(opcao){
			case 1:
				//opcaoInterna = Picareta::menuPicareta();
				cout << "ate o momento voce so pode ter a picareta padrao" << endl;
				break;
			case 2:
				for(int i = 0; i < (int)mapa.size(); i ++)
				{
					if(mapa[i].getNome() != "invalid") cout << i << " - " << mapa[i];
					cout << endl;
				}
				getch();
				cout << "Voce deseja destruir algum bloco?" << endl;
				opcaoSN = getch();
				if(opcaoSN == 's')
				{
					cout << "Qual bloco vc deseja quebrar?" <<endl;
					cin >> opcaoInterna;
					if(mapa[opcaoInterna].getNome() != "invalid")
					{
						if(picareta->quebrarBloco(mapa[opcaoInterna]))
							mapa[opcaoInterna].setInvalid();
					} else cout << "bloco invalido";
					getch();
				}
				else if(opcaoSN == 'n')
				{
					break;
				} else
				{
					cout << "opcao invalida" << endl;
					getch();
				}
				break;
			case 3:
				cout << "Fechando o Minecraft" << endl;
				Sleep(1000);
				return 0;
				break;
			
		}
	}
	
	delete picareta;
	
	system("pause");
	return 0;
}
