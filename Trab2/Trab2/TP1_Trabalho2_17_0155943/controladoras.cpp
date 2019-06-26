#include "controladoras.h"
#include <iostream>


using namespace std;

void ControladoraSQL::conectar() throw(ErroBanco) {
	rc = sqlite3_open(nm_DB, &db);
	if (rc != SQLITE_OK)
		throw ErroBanco("Erro na conexao com o banco de dados");
}

void ControladoraSQL::desconectar() throw(ErroBanco){
	rc = sqlite3_close(db);
	if (rc != SQLITE_OK)
		throw ErroBanco("Erro na desconexao com o banco de dados");
}

void ControladoraSQL::executar() throw (ErroBanco) {
	conectar();
	rc = sqlite3_exec(db, comandoSQL.c_str(), callback, 0, &mensagem);
	if (rc != SQLITE_OK) {
		if (mensagem)
			free(mensagem);
		throw ErroBanco("Erro na execucao do comando SQL");
	}
	desconectar();
}

list<ElementoResultado> ControladoraSQL::listaResultado;

int ControladoraSQL::callback(void* NotUsed, int argc, char** valorColuna, char** nomeColuna) {
	NotUsed = 0;
	ElementoResultado elemento;
	int i;
	for (i = 0; i < argc; i++) {
		elemento.setNomeColuna(nomeColuna[i]);
		elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
		listaResultado.emplace_front(elemento);
	}
	return 0;
}

bool ControladoraServicoAutenticacao::autenticar(CPF cpf, Senha senha) throw (ErroBanco){
	ControladoraSQL CtrSQL;
	CtrSQL.listaResultado.clear();
	string cmd;

	cmd = "SELECT SENHA FROM USUARIOS WHERE CPF = ";
	cmd += cpf.getCPF();
	
	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Usuario nao cadastrado.");
		return false;
	}
	else
		return true;
}

bool ControladoraServicoUsuario::cadastrar(CPF cpf, Senha senha, CartaoDeCredito cartao) throw (ErroBanco) {
	ControladoraSQL CtrSQL;
	CtrSQL.listaResultado.clear();
	string cmd;
	NumeroCartaoCredito nr_cartao;
	DataValidade dt_validade;
	CodigoSeguranca cd_seg;
	
	nr_cartao = cartao.getNumeroCartaoCredito();
	dt_validade = cartao.getDataValidade();
	cd_seg = cartao.getCodigoSeguranca();

	cmd = "SELECT NUMERO_CARTAO FROM CARTOES WHERE NUMERO_CARTAO = ";
	cmd += nr_cartao.getNumero();


	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();
	
	if (!CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Cartao ja cadastrado.");
		return false;
	}
	else {
		cmd = "INSERT INTO CARTOES VALUES(";
		cmd += "'" + nr_cartao.getNumero() + "',";
		cmd += "'" + cd_seg.getCodigoSeguranca() + "',";
		cmd += "'" + dt_validade.getDataDeValidade() + "')";

		CtrSQL.comandoSQL = cmd;
		CtrSQL.executar();

		cmd = "INSERT INTO USUARIOS VALUES(";
		cmd += "'" + cpf.getCPF() + "',";
		cmd += "'" + senha.getSenha() + "',";
		cmd += "'" + nr_cartao.getNumero() + "')";

		CtrSQL.comandoSQL = cmd;
		CtrSQL.executar();
	}
	return true;
}

bool ControladoraServicoUsuario::excluir(CPF cpf) throw(ErroBanco) {
	ControladoraSQL CtrSQL;
	CtrSQL.listaResultado.clear();
	string cmd;

	cmd = "SELECT CPF FROM USUARIOS WHERE CPF = ";
	cmd += cpf.getCPF();

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Usuario nao cadastrado.");
		return false;
	}
	else {
		cmd = "DELETE FROM USUARIOS WHERE CPF = ";
		cmd += cpf.getCPF();

		CtrSQL.comandoSQL = cmd;
		CtrSQL.executar();
	}
	return true;
}

bool ControladoraServicoEvento::cadatrar(CPF cpf, Evento evento) throw(ErroBanco) {
	ControladoraSQL CtrSQL;
	CtrSQL.listaResultado.clear();
	string cmd;
	CodigoEvento codigo;
	NomeEvento nome;
	Cidade cidade;
	ClasseEvento classe;
	Estado estado;
	FaixaEtaria faixa;

	codigo = evento.getCodigoEvento();
	nome = evento.getNomeEvento();
	cidade = evento.getCidade();
	classe = evento.getClasseEvento();
	estado = evento.getEstado();
	faixa = evento.getFaixaEtaria();

	cmd = "SELECT CODIGO FROM EVENTOS WHERE CODIGO = ";
	cmd += codigo.getCodigoEvento();

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (!CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Evento ja cadastrado.");
		return false;
	}
	else {
		cmd = "INSERT INTO EVENTOS VALUES(";
		cmd += "'" + codigo.getCodigoEvento() + "',";
		cmd += "'" + nome.getNomeEvento() + "',";
		cmd += "'" + cidade.getCidade() + "',";
		cmd += "'" + to_string(classe.getClasseEvento()) + "',";
		cmd += "'" + estado.getEstado() + "',";
		cmd += "'" + faixa.getFaixaEtaria() + "',";
		cmd += "'" + cpf.getCPF() + "')";

		CtrSQL.comandoSQL = cmd;
		CtrSQL.executar();
	}
	return true;
}

list<Apresentacao> ControladoraServicoEvento::apresentacoes(Evento evento) throw(ErroBanco){
	ControladoraSQL CtrSQL;
	CtrSQL.listaResultado.clear();
	string cmd;
	CodigoEvento codigo;
	list<Apresentacao> lista;
	Apresentacao apre;
	CodigoApresentacao codigoApre; 
	Data data; 
	Horario horario; 
	Preco preco; 
	NumeroSala sala; 
	Disponibilidade disponibilidade;
	int colunas = 0, i = 0;

	codigo = evento.getCodigoEvento();

	cmd = "SELECT CODIGO, DATA, HORARIO, PRECO, SALA, DISPONIBILIDADE FROM APRESENTACOES WHERE EVENTO = ";
	cmd += codigo.getCodigoEvento();

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	for (auto it = CtrSQL.listaResultado.begin(); it != CtrSQL.listaResultado.end(); it++){
		if (colunas == 0){
			codigoApre.setCodigoApresentacao(CtrSQL.listaResultado.front().getValorColuna());
			i++;
			CtrSQL.listaResultado.pop_front();
		}
		if (colunas == 1){
			data.setData(CtrSQL.listaResultado.front().getValorColuna());
			i++;
			CtrSQL.listaResultado.pop_front();
		}
		if (colunas == 2){
			horario.setHorario(CtrSQL.listaResultado.front().getValorColuna());
			i++;
			CtrSQL.listaResultado.pop_front();
		}
		if (colunas == 3){
			preco.setPreco(CtrSQL.listaResultado.front().getValorColuna());
			i++;
			CtrSQL.listaResultado.pop_front();
		}
		if (colunas == 4){
			sala.setNumero(stoi(CtrSQL.listaResultado.front().getValorColuna()));
			i++;
			CtrSQL.listaResultado.pop_front();
		}
		if (colunas == 5){
			disponibilidade.setDisponibilidade(stoi(CtrSQL.listaResultado.front().getValorColuna()));
			i++;
			CtrSQL.listaResultado.pop_front();
		}
		if (colunas > 5){
			apre.setCodigoApresentacao(codigoApre);
			apre.setData(data);
			apre.setHorario(horario);
			apre.setPreco(preco);
			apre.setNumeroSala(sala);
			apre.setDisponibilidade(disponibilidade);

			lista.emplace_front(apre);
			colunas = 0;
		}
	}
	return lista;
}

Evento ControladoraServicoEvento::pesquisar(CodigoEvento codigo) throw(ErroBanco) {
	ControladoraSQL CtrSQL;
	CtrSQL.listaResultado.clear();
	Evento evnt;
	NomeEvento nome;
	Cidade cidade;
	ClasseEvento classe;
	Estado estado;
	FaixaEtaria faixa;
	string cmd;
	int i = 0;

	cmd = "SELECT * FROM EVENTOS WHERE CODIGO = ";
	cmd += "'" + codigo.getCodigoEvento() + "'";

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Nao ha evento cadastrado com este cpf existe!");
		return evnt;
	}

	for (auto it = CtrSQL.listaResultado.end(); it != CtrSQL.listaResultado.begin(); it--) {
		if (i == 0)
			CtrSQL.listaResultado.pop_back();
		if (i == 1) {
			faixa.setFaixaEtaria(CtrSQL.listaResultado.back().getValorColuna());
			CtrSQL.listaResultado.pop_back();
		}
		if (i == 2) {
			classe.setClasseEvento(stoi(CtrSQL.listaResultado.back().getValorColuna()));
			CtrSQL.listaResultado.pop_back();
		}
		if (i == 3) {
			estado.setEstado(CtrSQL.listaResultado.back().getValorColuna());
			CtrSQL.listaResultado.pop_back();
		}
		if (i == 4) {
			cidade.setCidade(CtrSQL.listaResultado.back().getValorColuna());
			CtrSQL.listaResultado.pop_back();
		}
		if (i == 5) {
			nome.setNomeEvento(CtrSQL.listaResultado.back().getValorColuna());
			CtrSQL.listaResultado.pop_back();
		}
		i++;
	}

	evnt.setCodigoEvento(codigo);
	evnt.setNomeEvento(nome);
	evnt.setCidade(cidade);
	evnt.setClasseEvento(classe);
	evnt.setEstado(estado);
	evnt.setFaixaEtaria(faixa);


	return evnt;
}

bool ControladoraServicoEvento::pesquisar(NomeEvento nome) throw(ErroBanco) {
	ControladoraSQL CtrSQL;
	string cmd;
	
	cmd = "SELECT NOME FROM EVENTOS WHERE NOME = ";
	cmd += "'" + nome.getNomeEvento() + "'";

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Evento nao cadastrado existe!");
		return false;
	}

	return true;
}

bool ControladoraServicoEvento::pesquisar(CodigoEvento codigo, CPF cpf) throw(ErroBanco) {
	ControladoraSQL CtrSQL;
	string cmd;

	cmd = "SELECT CODIGO FROM EVENTOS WHERE CODIGO = ";
	cmd += codigo.getCodigoEvento();
	cmd += "AND CPF = " + cpf.getCPF();

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Evento nao cadastrado!");
		return false;
	}

	return true;
}

bool ControladoraServicoEvento::alterar(Evento evento, CPF cpf) throw(ErroBanco) {
	ControladoraSQL CtrSQL;
	string cmd;
	CodigoEvento codigo;
	NomeEvento nome;
	Cidade cidade;
	ClasseEvento classe;
	Estado estado;
	FaixaEtaria faixa;

	codigo = evento.getCodigoEvento();
	nome = evento.getNomeEvento();
	cidade = evento.getCidade();
	classe = evento.getClasseEvento();
	estado = evento.getEstado();
	faixa = evento.getFaixaEtaria();

	cmd = "SELECT CODIGO FROM EVENTOS WHERE CODIGO = ";
	cmd += codigo.getCodigoEvento();

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Evento nao cadastrado.");
		return false;
	}
	else {
		cmd = "UPDATE EVENTOS SET ";
		cmd += "NOME = " + nome.getNomeEvento() + ",";
		cmd += "NOME = " + cidade.getCidade() + ",";
		cmd += "NOME = " + to_string(classe.getClasseEvento()) + ",";
		cmd += "NOME = " + estado.getEstado() + ",";
		cmd += "NOME = " + faixa.getFaixaEtaria();
		cmd += "WHERE CODIGO = ";
		cmd += codigo.getCodigoEvento();

		CtrSQL.comandoSQL = cmd;
		CtrSQL.executar();
	}

	CtrSQL.listaResultado.clear();
	return true;
}

bool ControladoraServicoEvento::excluir(Evento evento, CPF cpf) throw(ErroBanco) {
	ControladoraSQL CtrSQL;
	string cmd;
	CodigoEvento codigo;
	NomeEvento nome;
	Cidade cidade;
	ClasseEvento classe;
	Estado estado;
	FaixaEtaria faixa;
	
	codigo = evento.getCodigoEvento();
	nome = evento.getNomeEvento();
	cidade = evento.getCidade();
	classe = evento.getClasseEvento();
	estado = evento.getEstado();
	faixa = evento.getFaixaEtaria();

	cmd = "SELECT CODIGO FROM EVENTOS WHERE CODIGO = ";
	cmd += codigo.getCodigoEvento();

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();

	if (CtrSQL.listaResultado.empty()) {
		throw ErroBanco("Evento nao cadastrado");
		return false;
	}
	else {
		cmd = "SELECT CPF FROM EVENTOS WHERE CODIGO = ";
		cmd += codigo.getCodigoEvento();
		
		CtrSQL.comandoSQL = cmd;
		CtrSQL.executar();
		for (auto it = CtrSQL.listaResultado.begin(); it != CtrSQL.listaResultado.end(); it++) {
			if (cpf.getCPF() != CtrSQL.listaResultado.front().getValorColuna())
				throw ErroBanco("Evento n�o relacionado a esse CPF.");
			else
			CtrSQL.listaResultado.pop_front();
		}

		cmd = "DELETE FROM EVENTOS WHERE CPF = ";
		cmd += cpf.getCPF();
		cmd += "AND CODIGO = " + evento.getCodigoEvento().getCodigoEvento();

		CtrSQL.comandoSQL = cmd;
		CtrSQL.executar();
	}
	return true;
}

list<ElementoResultado> ControladoraServicoVendas::vendas(Evento evto)  throw(ErroBanco){
	ControladoraSQL CtrSQL;
	CtrSQL.listaResultado.clear();
	string cmd;
	list<ElementoResultado> resultado;
	ElementoResultado vendas;

	cmd = "SELECT DISTINCT(CPF) FROM INGRESSOS";

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();
	resultado = CtrSQL.listaResultado;


	cmd = "SELECT SUM(PRECO) FROM EVENTOS INNER JOIN APRESENTACOES ON APRESENTACOES.EVENTO = EVENTOS.CODIGO	INNER JOIN INGRESSOS ON INGRESSOS.APRESENTACAO = APRESENTACOES.CODIGO";

	CtrSQL.comandoSQL = cmd;
	CtrSQL.executar();
	resultado.emplace_front(CtrSQL.listaResultado.front());

	return resultado;
}

bool ControladoraApresentacaoAutenticacao::autenticar(CPF cpf, Senha senha) throw(invalid_argument){
	ControladoraServicoAutenticacao CtrServ;
	
	try
	{
		CtrServ.autenticar(cpf, senha);
	}
	catch (ErroBanco exp)
	{
		cout << exp.what() << endl;
		return false;
	}
	return true;
}

void ControladoraApresentacaoUsuario::executar(CPF cpf, Senha senha) throw(invalid_argument) {
	ControladoraServicoUsuario CtrServUsu;
	ControladoraApresentacaoEventos CtrApreEve;
	ControladoraApresentacaoVendas CtrApreVen;
	int choice;
	Apresentacao apre;
	Evento evt;

	 
	cout << "Digite o numero correspondente a funcao desejada, numero entre ():" << endl << "(1)Eventos" << endl << "(2)Comprar Ingresso" << endl << "(3)Descadastrar" << endl;
	cin >> choice;

	switch (choice)
	{
	case 1:
		CtrApreEve.executar(cpf);
		break;
	case 2:
		CtrApreVen.executar();
		break;
	case 3:
		CtrServUsu.excluir(cpf);
		break;
	default:
		break;
	}
}

void ControladoraApresentacaoUsuario::executar() throw(invalid_argument) {
	ControladoraServicoUsuario CtrServUsu;
	int contr = 0;
	CPF cpf;
	Senha senha;
	CartaoDeCredito cartao;
	NumeroCartaoCredito nrCartao;
	DataValidade dtCartao;
	CodigoSeguranca nrCodigo;
	char aux[50];
	string auxStr;

	while (true)
	{
		if (contr > 5)
			clear();
		cout << endl << "Digite o Numero do Cartao: " << endl;
		cin >> aux;
		auxStr = aux;
		try
		{
			nrCartao.setNumero(auxStr);
		}
		catch (invalid_argument exp)
		{
			cout << endl << exp.what() << endl;
			contr++;
		}
		break;
	}
	while (true)
	{
		if (contr > 5)
			clear();
		cout << endl << "Digite a data de validade: " << endl;
		cin >> aux;
		auxStr = aux;
		try
		{
			dtCartao.setDataDeValidade(auxStr);
		}
		catch (invalid_argument exp)
		{
			cout << endl << exp.what() << endl;
			contr++;
		}
		break;
	}
	while (true)
	{
		if (contr > 5)
			clear();
		cout << endl << "Digite o codigo de seguranca: " << endl;
		cin >> aux;
		auxStr = aux;
		try
		{
			nrCodigo.setCodigoSeguranca(auxStr);
		}
		catch (invalid_argument exp)
		{
			cout << endl << exp.what() << endl;
			contr++;
		}
		break;
	}
	while (true)
	{
		if (contr > 5)
			clear();
		cout << endl << "Digite o cpf: " << endl;
		cin >> aux;
		auxStr = aux;
		try
		{
			cpf.setCPF(auxStr);
		}
		catch (invalid_argument exp)
		{
			cout << endl << exp.what() << endl;
			contr++;
		}
		break;
	}
	while (true)
	{
		if (contr > 5)
			clear();
		cout << endl << "Digite a senha: " << endl;
		cin >> aux;
		auxStr = aux;
		try
		{
			senha.setSenha(auxStr);
		}
		catch (invalid_argument exp)
		{
			cout << endl << exp.what() << endl;
			contr++;
		}
		break;
	}
	try
	{
		cartao.setNumeroCartaoCredito(nrCartao);
	}
	catch (invalid_argument exp)
	{
		cout << endl << exp.what() << endl;
	}
	try
	{
		cartao.setDataValidade(dtCartao);
	}
	catch (invalid_argument exp)
	{
		cout << endl << exp.what() << endl;
	}
	try
	{
		cartao.setCodigoSeguranca(nrCodigo);
	}
	catch (invalid_argument exp)
	{
		cout << endl << exp.what() << endl;
	}
	try
	{
		CtrServUsu.cadastrar(cpf, senha, cartao);
	}
	catch (ErroBanco exp)
	{
		cout << endl << exp.what() << endl;
	}
	
}

void ControladoraApresentacaoEventos::executar() throw(invalid_argument) {
	ControladoraServicoEvento CtrServEve;
	int contr = 0;
	NomeEvento nome;
	string aux_str;
	char aux[20];
	
	while (true)
	{
		while (true)
		{
			if (contr > 5)
				clear();
			cout << "Digite o nome do evento que deseja procurar: ";
			cin >> aux;
			aux_str = aux;
			try
			{
				nome.setNomeEvento(aux_str);
			}
			catch (invalid_argument exp)
			{
				cout << endl << exp.what() << endl;
			}
			break;
		}
		try
		{
			CtrServEve.pesquisar(nome);
		}
		catch (ErroBanco exp)
		{
			cout << endl << exp.what() << endl;
			contr++;
		}
		break;
	}
}

void ControladoraApresentacaoEventos::executar(CPF cpf) throw(invalid_argument) {
	ControladoraServicoEvento CtrServEve;
	ControladoraServicoVendas CtrSerVen;
	int linha, coluna, highlight = 0, tam_str, choice, choice2, index = 0;
	Evento evento;
	CodigoEvento codigo;
	NomeEvento nome;
	Cidade cidade;
	ClasseEvento classe;
	Estado estado;
	FaixaEtaria faixa;
	string aux_str;
	char aux[20];
	char confirm;
	vector<string> choices = { "Cadastar Evento", "Alterar Evento", "Exluir Evento" , "Vendas total do evento" };
	list<ElementoResultado> resultado;

	while (true)
	{
		for (int i = 0; i < choices.size(); i++)
			cout << "(%d)" << (i + 1) << choices.at(i) << endl;
		cout << "Digite a opcao desejada: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Para cadastrar o evento voce precisa prover as seguintes informacoes:" << endl;
			while (true)
			{
				while (true)
				{
					cout << endl << "Codigo do evento:" << endl;
					cin >> aux;
					aux_str = aux;
					try
					{
						codigo.setCodigoEvento(aux_str);
					}
					catch (invalid_argument exp)
					{
						cout << exp.what() << endl;
					}
					evento.setCodigoEvento(codigo);
					clear();
					break;
				}
				while (true)
				{
					cout << endl << "Nome do evento:" << endl;
					cin >> aux;
					aux_str = aux;
					try
					{
						nome.setNomeEvento(aux_str);
					}
					catch (invalid_argument exp)
					{
						cout << exp.what() << endl;
					}
					evento.setNomeEvento(nome);
					clear();
					break;
				}
				while (true)
				{
					cout << endl << "Cidade:" << endl;
					cin >> aux;
					aux_str = aux;
					try
					{
						cidade.setCidade(aux_str);
					}
					catch (invalid_argument exp)
					{
						cout << exp.what() << endl;
					}
					evento.setCidade(cidade);
					clear();
					break;
				}
				while (true)
				{
					cout << endl << "Estado:" << endl;
					cin >> aux;
					aux_str = aux;
					try
					{
						estado.setEstado(aux_str);
					}
					catch (invalid_argument exp)
					{
						cout << exp.what() << endl;
					}
					evento.setEstado(estado);
					clear();
					break;
				}
				while (true)
				{
					cout << endl << "Tipo de evento(Possiveis valores: 1-Teatro, 2-Esporte, 3-Show Nacional, 4-Show Internacional):" << endl;
					cin >> aux;
					aux_str = aux;
					try
					{
						classe.setClasseEvento(stoi(aux_str));
					}
					catch (invalid_argument exp)
					{
						cout << exp.what() << endl;
					}
					evento.setClasseEvento(classe);
					clear();
					break;
				}
				while (true)
				{
					cout << endl << "Faixa etaria(Possiveis valores: L,10,12,14,16,18):" << endl;
					cin >> aux;
					aux_str = aux;
					try
					{
						faixa.setFaixaEtaria(aux_str);
					}
					catch (invalid_argument exp)
					{
						cout << exp.what() << endl;
					}
					evento.setFaixaEtaria(faixa);
					clear();
					break;
				}
				break;
			}
			break;
		case 2:
			clear();
			highlight = 0;
			
			while (true)
			{
				while (true)
				{
					if (highlight > 5)
						clear();
					cout << "Digite o codigo do evento que deseja alterar: ";
					cin >> aux;
					aux_str = aux;
					try
					{
						codigo.setCodigoEvento(aux_str);
					}
					catch (invalid_argument exp)
					{
						cout<< endl << exp.what() << endl;
						highlight++;
					}
					break;
				}
				try
				{
					evento = CtrServEve.pesquisar(codigo);
				}
				catch (ErroBanco exp)
				{
					cout << endl << exp.what() << endl;
				}
				break;
			}
			cout << "Digite a opcao que corresponde ao campo que deseja alterar, numero entre ():" << endl;
			cout << "(1)Codigo do Evento:" << endl << "(2)Nome do evento:" << endl << "(3)Cidade:" << endl;
			cout << "(4)Estado:" << endl << "(5)Tipo Evento:" << endl << "(6)Faixa Etaria:" << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				clear();
				while (true)
				{
					while (true)
					{
						if (highlight > 5)
							clear();
						cout << "Digite novo codigo do evento: ";
						cin >> aux;
						aux_str = aux;
						try
						{
							codigo.setCodigoEvento(aux_str);
						}
						catch (invalid_argument exp)
						{
							cout << endl << exp.what() << endl;
							highlight++;
						}
						if (CtrServEve.pesquisar(codigo, cpf))
							cout << endl << "Ja existe um evento cadastrado com esse codigo" << endl;
						else
							break;
					}
					evento.setCodigoEvento(codigo);
					try
					{
						CtrServEve.alterar(evento, cpf);
					}
					catch (ErroBanco exp)
					{
						cout << endl << exp.what() << endl;
					}
					break;
				}
				break;
			case 2:
				clear();
				while (true)
				{
					while (true)
					{
						if (highlight > 5)
							clear();
						cout << "Digite novo nome do evento: ";
						cin >> aux;
						aux_str = aux;
						try
						{
							nome.setNomeEvento(aux_str);
						}
						catch (invalid_argument exp)
						{
							cout << endl << exp.what() << endl;
							highlight++;
						}
						break;
					}
					evento.setNomeEvento(nome);
					try
					{
						CtrServEve.alterar(evento, cpf);
					}
					catch (ErroBanco exp)
					{
						cout << endl << exp.what() << endl;
					}
					break;
				}
				break;
			case 3:
				clear();
				while (true)
				{
					while (true)
					{
						if (highlight > 5)
							clear();
						cout << "Digite nova cidade do evento: ";
						cin >> aux;
						aux_str = aux;
						try
						{
							cidade.setCidade(aux_str);
						}
						catch (invalid_argument exp)
						{
							cout << endl << exp.what() << endl;
							highlight++;
						}
						break;
					}
					evento.setCidade(cidade);
					try
					{
						CtrServEve.alterar(evento, cpf);
					}
					catch (ErroBanco exp)
					{
						cout << endl << exp.what() << endl;
					}
					break;
				}
				break;
			case 4:
				clear();
				while (true)
				{
					while (true)
					{
						if (highlight > 5)
							clear();
						cout << "Digite novo estado do evento: ";
						cin >> aux;
						aux_str = aux;
						try
						{
							estado.setEstado(aux_str);
						}
						catch (invalid_argument exp)
						{
							cout << endl << exp.what() << endl;
							highlight++;
						}
						break;
					}
					evento.setEstado(estado);
					try
					{
						CtrServEve.alterar(evento, cpf);
					}
					catch (ErroBanco exp)
					{
						cout << endl << exp.what() << endl;
					}
					break;
				}
				break;
			case 5:
				clear();
				while (true)
				{
					while (true)
					{
						if (highlight > 5)
							clear();
						cout << "Digite novo tipo de evento: ";
						cin >> aux;
						aux_str = aux;
						try
						{
							classe.setClasseEvento(stoi(aux_str));
						}
						catch (invalid_argument exp)
						{
							cout << endl << exp.what() << endl;
							highlight++;
						}
						break;
					}
					evento.setClasseEvento(classe);
					try
					{
						CtrServEve.alterar(evento, cpf);
					}
					catch (ErroBanco exp)
					{
						cout << endl << exp.what() << endl;
					}
					break;
				}
				break;
			case 6:
				clear();
				while (true)
				{
					while (true)
					{
						if (highlight > 5)
							clear();
						cout << "Digite nova faixa etaria do evento: ";
						cin >> aux;
						aux_str = aux;
						try
						{
							faixa.setFaixaEtaria(aux_str);
						}
						catch (invalid_argument exp)
						{
							cout << endl << exp.what() << endl;
							highlight++;
						}
						break;
					}
					evento.setFaixaEtaria(faixa);
					try
					{
						CtrServEve.alterar(evento, cpf);
					}
					catch (ErroBanco exp)
					{
						cout << endl << exp.what() << endl;
					}
					break;
				}
				break;
			default:
				break;
			}
			break;
		case 3:
			clear();
			highlight = 0;
			while (true)
			{
				while (true)
				{
					if (highlight > 5)
						clear();
					cout << "Digite o codigo do evento que deseja exlcuir: ";
					cin >> aux;
					aux_str = aux;
					try
					{
						codigo.setCodigoEvento(aux_str);
					}
					catch (invalid_argument exp)
					{
						cout << endl << exp.what() << endl;
						highlight++;
					}
					break;
				}
				try
				{
					evento = CtrServEve.pesquisar(codigo);
				}
				catch (invalid_argument exp)
				{
					cout << endl << exp.what() << endl;
				}
				break;
			}
			try
			{
				CtrServEve.excluir(evento, cpf);
			}
			catch (ErroBanco exp)
			{
				cout << endl << exp.what() << endl;
			}
			break;
		case 4:
			while (true)
			{
				if (highlight > 5)
					clear();
				cout << endl << "Digite o codigo do evento: ";
				cin >> aux;
				aux_str = aux;
				try
				{
					codigo.setCodigoEvento(aux_str);
				}
				catch (invalid_argument exp)
				{
					cout << endl << exp.what() << endl;
					highlight++;
				}
			}
			try
			{
				evento = CtrServEve.pesquisar(codigo);
			}
			catch (ErroBanco exp)
			{
				cout << endl << exp.what() << endl;
			}
			try
			{
				resultado = CtrSerVen.vendas(evento);
			}
			catch (ErroBanco exp)
			{
				cout << endl << exp.what() << endl;
			}
			for (auto it = resultado.begin(); it != resultado.end(); it++) {
				if (index == 0) {
					cout << endl << "Total de vendas: " << resultado.front().getValorColuna() << endl;
					resultado.pop_front();
					index++;
				}
				else{
					cout << resultado.front().getNomeColuna() << " : " << resultado.front().getValorColuna();
					resultado.pop_front();
				}
			}
			break;
		default: 
			break;
		}
	}
	
}

void ControladoraApresentacaoVendas::executar(Evento evento) throw(invalid_argument) {
	ControladoraServicoVendas CtrServ;
	list<ElementoResultado> vendasRes;
	int i = 0;
	vendasRes = CtrServ.vendas(evento);

	for(auto it = vendasRes.begin(); it != vendasRes.end(); it++){
		cout << vendasRes.front().getNomeColuna() << ": ";
		cout << vendasRes.front().getValorColuna() << endl;
	}
}

void ControladoraApresentacaoVendas::executar() throw(invalid_argument) {
	ControladoraServicoVendas CtrServ;
	ControladoraServicoEvento CtrSerEve;
	char aux[30];
	string auxStr;
	CodigoEvento codigo;
	Evento evento;
	list<Apresentacao> apresentacoes;

	while (true)
	{
		cout << endl << "Digite o codigo do evento que deseja comprar o ingresso: " << endl;
		cin >> aux;
		auxStr = aux;

		try
		{
			codigo.setCodigoEvento(aux);
		}
		catch (invalid_argument exp)
		{
			cout << exp.what() << endl;
		}

		try
		{
			evento = CtrSerEve.pesquisar(codigo);
		}
		catch (ErroBanco exp)
		{
			cout << exp.what() << endl;
		}
		
		try
		{
			apresentacoes = CtrSerEve.apresentacoes(evento);
		}
		catch (ErroBanco exp)
		{
			cout << exp.what() << endl;
		}

		break;
	}

}