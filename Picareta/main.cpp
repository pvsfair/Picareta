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
	Picareta *picareta;
	vector<Bloco> mapa;
	
	
	float minerioFerroRes[5] = {15.0f, 1.15f, 0.75f, 0.6f, 15.0f};
	bool minerioFerroColh[5] = {false, true, true, true, false};
	Bloco bF("Minerio de Ferro",  minerioFerroRes, minerioFerroColh);
	mapa.push_back(bF);
	float minerioOuroRes[5] = {15.0f, 15.0f, 0.75f, 0.6f, 15.0f};
	bool minerioOuroColh[5] = {false, false, true, true, false};
	Bloco bO("Minerio de Ouro",  minerioOuroRes, minerioOuroColh);
	mapa.push_back(bO);
	float minerioDiamanteRes[5] = {15.0f, 15.0f, 0.75f, 0.6f, 15.0f};
	bool minerioDiamanteColh[5] = {false, false, true, true, false};
	Bloco bD("Minerio de Diamante",  minerioDiamanteRes, minerioDiamanteColh);
	mapa.push_back(bD);
	
	while(rodando)
	{
		system("cls");
		cout << "==========Minecraft==========" << endl;
		cout << "Você tem " << "alguma coisa" << " na sua mao" << endl;
		cout << "1 - Construir Picareta" << endl;
		cout << "2 - Checar Mapa" << endl;
		cout << "3 - Sair" << endl;
		cin >> opcao;
		switch(opcao){
			case 1:
				Picareta::menuPicareta();
				break;
			case 2:
				for(int i = 0; i < (int)mapa.size(); i ++)
				{
					cout << mapa[i].getNome() << endl;
				}
				getch();
				cout << "Voce deseja destruir algum bloco" << endl;
				break;
			case 3:
				cout << "Fechando o Minecraft" << endl;
				Sleep(1000);
				return 0;
				break;
			
		}
	}
	
	Picareta p(1);
	
	system("pause");
	return 0;
}
