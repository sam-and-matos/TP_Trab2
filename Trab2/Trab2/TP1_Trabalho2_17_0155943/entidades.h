/** 
 *  @file entidades.h
 *  Assinatura de todas as entidades do software de hospedagem em viagens.
 *  
 *  Estas entidades são implementados por classes contendo os domínios do
 *  software de hospedagem em viagens e métodos para o usuário conseguir
 *  trabalhar com as entidades desse software.
 */

#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

using namespace std;


/** 
 *  Classe da Acomodação.
 *  
 *  A classe descreve uma acomodação, composta pelas seguintes classes de
 *  domínios: CodigoEvento, TipoAcomodacao (tipo de acomodação), uma 
 *  CapacidadeAcomodacao (capacidade de acomodação), duas classes de Data 
 *  (uma de início e uma de fim), Nome, Estado e Diária. Seus métodos 
 *  criam os domínios e o retornam se necessário.  
 */
class Evento {
	private:
		CodigoEvento codigo; 
		NomeEvento nome; 
		Cidade cidade; 
		ClasseEvento classe; 
		Estado estado; 
		FaixaEtaria faixa;

	public:

		// Metodos de acesso

		/**
		 * Método para criação da classe do identificador da acomodação.
		 * 
		 * Esse método cria uma classe CodigoEvento para a entidade 
		 * "Acomodacao".
		 * 
		 * @param identificador o ponteiro para a classe "identificador" que será criada
		 * 
		 * @see CodigoEvento
		 * 
		*/
		void setCodigoEvento(const CodigoEvento &codigo) {
			this->codigo = codigo;
		}
		
		/**
		 * Método para criação da classe do tipo da acomodação.
		 * 
		 * Esse método cria uma classe TipoAcomodacao para a entidade 
		 * "Acomodacao".
		 * 
		 * @param tipoAcomodacao o ponteiro para a classe "tipoAcomodacao" que será criada
		 * 
		 * @see TipoAcomodacao
		 * 
		*/
		void setNomeEvento(const NomeEvento &nome) {
			this->nome = nome;
		}

		/**
		 * Método para criação da classe da capacidade da acomodação.
		 * 
		 * Esse método cria uma classe CapacidadeAcomodacao para a entidade 
		 * "Acomodacao".
		 * 
		 * @param capaidadeAcomodacao o ponteiro para a classe "capaidadeAcomodacao" que será criada
		 * 
		 * @see CapacidadeAcomodacao
		 * 
		*/
		void setCidade(const Cidade &cidade) {
			this->cidade = cidade;
		}

		/**
		 * Método para criação da classe do estado da acomodação.
		 * 
		 * Esse método cria uma classe Estado correspondente ao estado brasileiro 
		 * da acomodação para a entidade "Acomodacao".
		 * 
		 * @param estado o ponteiro para a classe "estado" que será criada
		 * 
		 * @see Estado
		 * 
		*/
		void setEstado(const Estado &estado) {
			this->estado = estado;
		}

		/**
		 * Método para criação da classe do estado da acomodação.
		 *
		 * Esse método cria uma classe Estado correspondente ao estado brasileiro
		 * da acomodação para a entidade "Acomodacao".
		 *
		 * @param estado o ponteiro para a classe "estado" que será criada
		 *
		 * @see Estado
		 *
		*/
		void setFaixaEtaria(const FaixaEtaria& faixa) {
			this->faixa = faixa;
		}

		/**
		 * Método para criação da classe do estado da acomodação.
		 *
		 * Esse método cria uma classe Estado correspondente ao estado brasileiro
		 * da acomodação para a entidade "Acomodacao".
		 *
		 * @param estado o ponteiro para a classe "estado" que será criada
		 *
		 * @see Estado
		 *
		*/
		void setClasseEvento(const ClasseEvento& classe) {
			this->classe = classe;
		}

		/**
		 * Método para o acesso à classe do identificador.
		 * 
		 * Esse método acessa a classe do identificador relacionada a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe do identificador. 
		 * 
		*/
		CodigoEvento getCodigoEvento() const {
			return codigo;
		}

		/**
		 * Método para o acesso à classe do tipo de acomodação.
		 * 
		 * Esse método acessa a classe do tipo de acomodação relacionada a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe do tipo de acomodação. 
		 * 
		*/
		NomeEvento getNomeEvento() const {
			return nome;
		}

		/**
		 * Método para o acesso à classe da capacidade de acomodação.
		 * 
		 * Esse método acessa a classe da capacidade de acomodação relacionada 
		 * a ele no código principal e retorna essa classe. 
		 * 
		 * @return a classe da capacidade de acomodação. 
		 * 
		*/
		Cidade getCidade() const {
			return cidade;
		}

		/**
		 * Método para o acesso à classe do estado.
		 * 
		 * Esse método acessa a classe do estado relacionado a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe do estado. 
		 * 
		*/
		Estado getEstado() const {
			return estado;
		}

		/**
		 * Método para o acesso à classe da diária.
		 * 
		 * Esse método acessa a classe da diária relacionado a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe da diária. 
		 * 
		*/
		ClasseEvento getClasseEvento() const {
			return classe;
		}

		/**
		 * Método para o acesso à classe da diária.
		 *
		 * Esse método acessa a classe da diária relacionado a ele no
		 * código principal e retorna essa classe.
		 *
		 * @return a classe da diária.
		 *
		*/
		FaixaEtaria getFaixaEtaria(){
			return faixa;
		}

};

/** 
 *  Classe do Cartão de Créditos.
 *  
 *  A classe descreve um cartão de crédito, composto pelas seguintes classes de
 *  domínios: NumeroCartaoCredito (número de cartão de crédito) e DataValidade
 *  (data de validade). Seus métodos criam os domínios e o retornam se necessário.  
 */
class CartaoDeCredito {
	private:
		NumeroCartaoCredito numero;
		DataValidade data; 
		CodigoSeguranca codigo;

	public:

		// Metodos de acesso

		/**
		 * Método para criação da classe do número do cartão de crédito.
		 * 
		 * Esse método cria uma classe NumeroCartaoCredito para a entidade 
		 * "CartaoDeCredito".
		 * 
		 * @param numeroCartaoCredito o ponteiro para a classe "numeroCartaoCredito" 
		 * que será criada
		 * 
		 * @see NumeroCartaoCredito
		 * 
		*/
		void setNumeroCartaoCredito(const NumeroCartaoCredito &numeroCartaoCredito) {
			this->numero = numeroCartaoCredito;
		}

		/**
		 * Método para criação da classe da data de validade do cartão de crédito.
		 * 
		 * Esse método cria uma classe DataValidade para a entidade 
		 * "CartaoDeCredito".
		 * 
		 * @param dataValidade o ponteiro para a classe "dataValidade" 
		 * que será criada
		 * 
		 * @see DataValidade
		 * 
		*/
		void setDataValidade(const DataValidade &dataValidade) {
			this->data = dataValidade;
		}

		/**
		 * Método para criação da classe da data de validade do cartão de crédito.
		 *
		 * Esse método cria uma classe DataValidade para a entidade
		 * "CartaoDeCredito".
		 *
		 * @param dataValidade o ponteiro para a classe "dataValidade"
		 * que será criada
		 *
		 * @see DataValidade
		 *
		*/
		void setCodigoSeguranca(const CodigoSeguranca& codigo) {
			this->codigo = codigo;
		}

		/**
		 * Método para o acesso à classe do número cartão de crédito.
		 * 
		 * Esse método acessa a classe do número do cartão de crédito 
		 * relacionado a ele no código principal e retorna essa classe. 
		 * 
		 * @return a classe do número do cartão de crédito. 
		 * 
		*/
		NumeroCartaoCredito getNumeroCartaoCredito() const {
			return numero;
		}

		/**
		 * Método para o acesso à classe da data de validade.
		 * 
		 * Esse método acessa a classe da data de validade relacionada a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe da data de validade. 
		 * 
		*/
		DataValidade getDataValidade() const {
			return data;
		}

		/**
		 * Método para o acesso à classe do código de segurança.
		 *
		 * Esse método acessa a classe do código de segurança relacionada a ele no
		 * código principal e retorna essa classe.
		 *
		 * @return a classe do código de segurança.
		 *
		*/
		CodigoSeguranca getCodigoSeguranca() const {
			return codigo;
		}

};

/**
 *  Classe do Usuário.
 *
 *  A classe descreve um usuário, composto pelas seguintes classes de
 *  domínios: Nome, Identificador e Senha. Seus métodos criam os domínios
 *  e o retornam se necessário.
 */
class Usuario {

private:
	CPF cpf;
	Senha senha;
	CartaoDeCredito cartao;

public:

	// Metodos de acesso

	/**
	 * Método para criação da classe do CPF.
	 *
	 * Esse método cria uma classe CPF para o cpf da entidade "Usuário".
	 *
	 * @param nome o ponteiro para a classe "CPF" que será criada
	 *
	 * @see CPF
	 *
	*/
	void setCPF(const CPF& cpf) {
		this->cpf = cpf;
	}

	/**
	 * Método para criação da classe da senha.
	 *
	 * Esse método cria uma classe Senha para a senha da entidade "Usuário".
	 *
	 * @param senha o ponteiro para a classe "senha" que será criada
	 *
	 * @see Senha
	 *
	*/
	void setSenha(const Senha& senha) {
		this->senha = senha;
	}

	/**
	 * Método para criação da classe da senha.
	 *
	 * Esse método cria uma classe Senha para a senha da entidade "Usuário".
	 *
	 * @param senha o ponteiro para a classe "senha" que será criada
	 *
	 * @see Senha
	 *
	*/
	void setCartaoCredito(const CartaoDeCredito& cartao) {
		this->cartao = cartao;
	}

	/**
	 * Método para o acesso à classe da senha.
	 *
	 * Esse método acessa a classe da senha relacionada a ele no
	 * código principal e retorna essa classe.
	 *
	 * @return a classe da senha.
	 *
	*/
	Senha getSenha() const {
		return senha;
	}

	/**
	 * Método para o acesso à classe do nome.
	 *
	 * Esse método acessa a classe do nome relacionado a ele no
	 * código principal e retorna essa classe.
	 *
	 * @return a classe do nome.
	 *
	*/
	CPF getCPF() const {
		return cpf;
	}

	/**
	 * Método para o acesso à classe do nome.
	 *
	 * Esse método acessa a classe do nome relacionado a ele no
	 * código principal e retorna essa classe.
	 *
	 * @return a classe do nome.
	 *
	*/
	CartaoDeCredito getCartaoCredito() const {
		return cartao;
	}

};

/** 
 *  Classe da Apresentação.
 *  
 *  A classe descreve uma apresentação, composta pelas seguintes classes de
 *  domínios: CodigoApresetancao, Data, Horario, Preco, NumeroSala e Disponibilidade.
 *  Seus métodos criam os domínios e o retornam se necessário.  
 */
class Apresentacao {
	private:
		CodigoApresentacao codigo; 
		Data data; 
		Horario horario; 
		Preco preco; 
		NumeroSala sala; 
		Disponibilidade disponibilidade;

	public:

		// Metodos de acesso

		/**
		 * Método para criação da classe do código de apresentação.
		 * 
		 * Esse método cria uma classe CodigoApresentacao para a entidade 
		 * "Aprensentacao".
		 * 
		 * @param codigo o ponteiro para a classe "CodigoApresentacao" que será criada
		 * 
		 * @see CodigoApresentacao
		 * 
		*/
		void setCodigoApresentacao(const CodigoApresentacao &codigo) {
			this->codigo = codigo;
		}

		/**
		 * Método para criação da classe da data da apresentação.
		 * 
		 * Esse método cria uma classe Data para a entidade 
		 * "CodigoApresentacao".
		 * 
		 * @param data o ponteiro para a classe "Data" que será criada
		 * 
		 * @see Agencia
		 * 
		*/
		void setData(const Data &data) {
			this->data = data;
		}
		
		/**
		 * Método para criação da classe do horario da apresentação.
		 * 
		 * Esse método cria uma classe Horario para a entidade 
		 * "Apresentacao".
		 * 
		 * @param horario o ponteiro para a classe "Horario" que será criada
		 * 
		 * @see Horario
		 * 
		*/
		void setHorario(const Horario &horario) {
			this->horario = horario;
		}

		/**
		 * Método para criação da classe do preço da apresentação.
		 *
		 * Esse método cria uma classe Preco para a entidade
		 * "Apresentacao".
		 *
		 * @param preco o ponteiro para a classe "Preco" que será criada
		 *
		 * @see Preco
		 *
		*/
		void setPreco(const Preco& preco) {
			this->preco = preco;
		}

		/**
		 * Método para criação da classe do número da sala da aparesentação.
		 *
		 * Esse método cria uma classe NumeroSala para a entidade
		 * "Apresentacao".
		 *
		 * @param numero o ponteiro para a classe "NumeroSala" que será criada
		 *
		 * @see NumeroSala
		 *
		*/
		void setNumeroSala(const NumeroSala& numero) {
			this->sala = numero;
		}

		/**
		 * Método para criação da classe de disponibilidade da apresentação.
		 *
		 * Esse método cria uma classe Disponibilidade para a entidade
		 * "Apresentacao".
		 *
		 * @param disponibilidade o ponteiro para a classe "Disponibilidade" que será criada
		 *
		 * @see Disponibilidade
		 *
		*/
		void setDisponibilidade(const Disponibilidade& disponibilidade) {
			this->disponibilidade = disponibilidade;
		}

		/**
		 * Método para o acesso ao código da apresentação.
		 * 
		 * Esse método acessa a classe do CodigoApresentacao a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe CodigoApresentacao. 
		 * 
		*/
		CodigoApresentacao getCodigoApresentacao() const {
			return codigo;
		}

		/**
		 * Método para o acesso à classe da data.
		 * 
		 * Esse método acessa a classe da Data relacionada a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe Data. 
		 * 
		*/
		Data getData() const {
			return data;
		}

		/**
		 * Método para o acesso ao horário da apresentação.
		 * 
		 * Esse método acessa a classe do Horario relacionada a ele no 
		 * código principal e retorna essa classe. 
		 * 
		 * @return a classe Horario. 
		 * 
		*/
		Horario getHorario() const {
			return horario;
		}

		/**
		 * Método para o acesso ao preçõ da apresentação.
		 *
		 * Esse método acessa a classe do Preco relacionada a ele no
		 * código principal e retorna essa classe.
		 *
		 * @return a classe Preco.
		 *
		*/
		Preco getPreco() const {
			return preco;
		}

		/**
		 * Método para o acesso ao número da sala da apresentação.
		 *
		 * Esse método acessa a classe do NumeroSala relacionada a ele no
		 * código principal e retorna essa classe.
		 *
		 * @return a classe NumeroSala.
		 *
		*/
		NumeroSala getNumeroSala() const {
			return sala;
		}

		/**
		 * Método para o acesso à disponibilidade da apresentação.
		 *
		 * Esse método acessa a classe da Disponibilidade relacionada a ele no
		 * código principal e retorna essa classe.
		 *
		 * @return a classe Disponibilidade.
		 *
		*/
		Disponibilidade getDisponibilidade() const {
			return disponibilidade;
		}
};

/**
 *  Classe do Ingresso.
 *
 *  A classe descreve um ingresso, composto pelas seguintes classes de
 *  domínios: CodigoIngresso. Seus métodos criam os domínios
 *  e o retornam se necessário.
 */
class Ingresso {

private:
	CodigoIngresso ingresso;

public:

	// Metodos de acesso

	/**
	 * Método para criação da classe do código de ingresso.
	 *
	 * Esse método cria uma classe CodigoIngresso para a o ingresso da entidade "Ingresso".
	 *
	 * @param ingresso o ponteiro para a classe "CodigoIngresso" que será criada
	 *
	 * @see CodigoIngresso
	 *
	*/
	void setCodigoIngresso(const CodigoIngresso& ingresso) {
		this->ingresso = ingresso;
	}

	/**
	 * Método para o acesso à classe CodigoIngresso.
	 *
	 * Esse método acessa a classe do codigo de ingresso relacionado a ele no
	 * código principal e retorna essa classe.
	 *
	 * @return a classe do codigo de ingresso.
	 *
	*/
	CodigoIngresso getSenha() const {
		return ingresso;
	}

};

#endif // ENTIDADES_H_INCLUDED