#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "entidades.h"
#include "dominios.h"
#include <list>
#include "curses.h"

class ErroBanco {
private:
	string mensagem;
public:
	ErroBanco(string);
	string what();
};

class ElementoResultado {
private:
	string nomeColuna;
	string valorColuna;
	
public:
	void setNomeColuna(string);
	string getNomeColuna() const{
		return nomeColuna;
	};
	void setValorColuna(string);
	string getValorColuna() const{
		return valorColuna;
	};
};

class InterfaceApresentacaoAutenticacao {
public:
	virtual bool autenticar(CPF, Senha) throw(invalid_argument) = 0;
};

class InterfaceApresentacaoUsuario {
public:
	virtual void executar(CPF, Senha) throw(invalid_argument) = 0;
	virtual void executar() throw(invalid_argument) = 0;
};

class InterfaceApresentacaoEventos {
public:
	virtual void executar(CPF) throw(invalid_argument) = 0;
	virtual void executar() throw(invalid_argument) = 0;
};

class InterfaceApresentacaoVendas {
public:
	virtual void executar(Evento) throw(invalid_argument) = 0;
	virtual void executar()  throw (invalid_argument) = 0;
};

class InterfaceServicoAutenticacao {
public:
	virtual bool autenticar(CPF, Senha) throw(ErroBanco) = 0;
};

class InterfaceServicoUsuario {
public:
	virtual bool cadastrar(CPF, Senha, CartaoDeCredito) throw(ErroBanco) = 0;
	virtual bool excluir(CPF) throw(ErroBanco) = 0;
};

class InterfaceServicoEvento {
public:
	virtual list<Apresentacao> apresentacoes(Evento) throw (ErroBanco) = 0;
	virtual Evento pesquisar(CodigoEvento) throw(ErroBanco) = 0;
	virtual bool pesquisar(NomeEvento) throw(ErroBanco) = 0;
	virtual bool pesquisar(CodigoEvento, CPF) throw(ErroBanco) = 0;
	virtual bool cadatrar(CPF, Evento) throw(ErroBanco) = 0;
	virtual bool alterar(Evento, CPF) throw(ErroBanco) = 0;
	virtual bool excluir(Evento, CPF) throw(ErroBanco) = 0;
};

class InterfaceServicoVendas {
public:
	virtual list<ElementoResultado> vendas(Evento) throw(ErroBanco) = 0;
};

#endif
