#ifndef CONTROLADORAS_H_INCLUDED
#define CONTROLADORAS_H_INCLUDED

#include "interfaces.h"
#include "dominios.h"
#include "sqlite3.h"
#include <list>

class ControladoraApresentacaoAutenticacao :public InterfaceApresentacaoAutenticacao{
public:
	bool autenticar(CPF, Senha) throw (invalid_argument);
};

class ControladoraApresentacaoUsuario :public InterfaceApresentacaoUsuario{
public:
	void executar(CPF, Senha)  throw (invalid_argument);
	void executar()  throw (invalid_argument);
};

class ControladoraApresentacaoEventos :public InterfaceApresentacaoEventos{
public:
	void executar(CPF)  throw (invalid_argument);
	void executar()  throw (invalid_argument);
};

class ControladoraApresentacaoVendas :public InterfaceApresentacaoVendas{
public:
	void executar(Evento)  throw (invalid_argument);
	void executar()  throw (invalid_argument);
};

class ControladoraServicoAutenticacao :public InterfaceServicoAutenticacao{
public:
	bool autenticar(CPF, Senha) throw (ErroBanco);
};

class ControladoraServicoUsuario :public InterfaceServicoUsuario{
public:
	bool cadastrar(CPF, Senha, CartaoDeCredito) throw(ErroBanco);
	bool excluir(CPF) throw(ErroBanco);
};

class ControladoraServicoEvento :public InterfaceServicoEvento{
public:
	list<Apresentacao> apresentacoes(Evento) throw (ErroBanco);
	Evento pesquisar(CodigoEvento) throw (ErroBanco);
	bool pesquisar(NomeEvento) throw (ErroBanco);
	bool pesquisar(CodigoEvento,CPF) throw (ErroBanco);
	bool cadatrar(CPF, Evento) throw(ErroBanco);
	bool alterar(Evento, CPF) throw (ErroBanco);
	bool excluir(Evento, CPF) throw (ErroBanco);
};

class ControladoraServicoVendas :public InterfaceServicoVendas{
public:
	list<ElementoResultado> vendas(Evento) throw (ErroBanco);
};

class ControladoraSQL {
private:
	const char* nm_DB;
	sqlite3* db;
	char* mensagem;
	int rc;
	void conectar() throw(ErroBanco);
	void desconectar() throw(ErroBanco);
	static int callback(void*, int, char**, char**);
public:
	static list<ElementoResultado> listaResultado;
	string comandoSQL;
	ControladoraSQL() {
		nm_DB = "DB_Dados";
	}
	void executar() throw(ErroBanco);
};

#endif