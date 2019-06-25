#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "controladoras.h"
#include "curses.h"
#include <vector>

using namespace std;

int main(){
	int choice,linha, coluna, menuLinha, menuColuna, tam_string, posMenu, proxMenu, highlight = 0;
	vector<string> choices= { "Pesquisar Evento","Cadastrar", "Entrar" };
	ControladoraApresentacaoEventos CtrApreEve;
	ControladoraApresentacaoAutenticacao CtrApreAut;
	ControladoraApresentacaoUsuarios CtrApreUsu;
	ControladoraApresentacaoVendas CtrApreVen;
	CPF cpf;
	Senha senha;
	string aux;

	initscr();
	noecho();

	for(auto it = choices.begin(); it != choices.end(); i++){
		cout << "Escolha uma das opcoes a seguir:" << endl;
		cout << "(%d)" << (highlight + 1) << choices.at(highlight);
		highlight++;
	}
	cin << choice;

	switch(choice)
	{
	case 1:
		CtrApreEve.executar();
		break;
	case 2:
		CtrApreUsu.executar();
		break;
	case 3:
		while (true)
		{
			cout << "Digite o CPF: ";
			cin >> aux;
			try
			{
				cpf.setCPF(aux);
			}
			catch (invalid_argument exp)
			{
				cout << endl << exp.what() << endl;
			}
			break;
		}
		while (true)
		{
			cout << "Digite a senha: ";
			cin >> aux;
			try
			{
				senha.setSenha(aux);
			}
			catch (invalid_argument exp)
			{
				cout << endl << exp.what() << endl;
			}
			break;
		}
		break;
	default:
		break;
	}

	endwin();
	return 0;
}
