#include <iostream>
#include "dominios.h"
#include "entidades.h"
#include "controladoras.h"
#include <stdlib.h>
#include <vector>

using namespace std;

int main(){
	int choice, highlight = 0;
	vector<string> choices= { "Pesquisar Evento","Cadastrar", "Entrar" };
	ControladoraApresentacaoEventos CtrApreEve;
	ControladoraApresentacaoAutenticacao CtrApreAut;
	ControladoraApresentacaoUsuario CtrApreUsu;
	ControladoraApresentacaoVendas CtrApreVen;
	bool teste;
	
	CPF cpf;
	Senha senha;
	string aux;

	for(auto it = choices.begin(); it != choices.end(); it++){
		cout << "Escolha uma das opcoes a seguir:" << endl;
		cout << "(%d)" << (highlight + 1) << choices.at(highlight);
		highlight++;
	}
	cin >> choice;

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
		try
		{
			teste = CtrApreAut.autenticar(cpf, senha);
		}
		catch (ErroBanco exp)
		{
			cout << endl << exp.what() << endl;
		}
		if (teste) {
			try
			{
				CtrApreUsu.executar(cpf, senha);
			}
			catch (ErroBanco exp)
			{
				cout << endl << exp.what() << endl;
			}
		}
		break;
	default:
		break;
	}

	return 0;
}
