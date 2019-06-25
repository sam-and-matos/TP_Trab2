/** 
 *  @file dominios.h
 *  Assinatura de todos os domínios do software de hospedagem em viagens.
 *  
 *  Estes domínios são implementados por um misto de classes e funções, e estas
 *  são capazes de descrever cada um dos domínios necessários para o software de 
 *  hospedagem em viagens.
 */

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>
#include <array>
#include <regex>

using namespace std;

// Funções auxiliares

/** 
 *  Função que checa se o número do cartão de crédito é válido.
 *  
 *  A função analisa o número informado pelo usuário como seu
 *  número de cartão de crédito e checa se esse número é válido
 *  ou não.
 * 
 *  @param numero string que contém o número informado pelo usuário.  
 */



class ChecaNumero {
public:
/**
* Funcao que checa se dada string é composta só por números.
*
* A função analisa todos os caracteres da string e retorna True se
* a string for composta só por números e False se ao menos um caracter
* não for número.
*
* @param string fornecida pelo usuário.
*/
	bool checkNumero(string);
};

class ChecaPresente {
public:
	bool checkPresent(int num, int vector[4]);
};

/**
 *  Classe da cidade.
 *
 *  A classe descreve o nome de uma cidade. Seus
 *  métodos validam o nome da cidade, criam
 *  essa cidade e retornam o nome da cidade ao usuário.
 */
class Cidade {
private:
	string cidade; 

	const static int LIMITE = 15; 

	// Metodo de validacao
	void validar(string) throw(invalid_argument);

public:

	// Metodos de acesso

	/**
	 * Método para criação da cidade.
	 *
	 * Esse método invoca o outro método para validar o valor fornecido pelo usuário para a string cidade.
	 * Se ele for válido, a Cidade com o nome da string cidade é criada contendo
	 * aquele valor específico. Se ele não for válido, se for invalido não é criada.
	 *
	 * @param cidade string que contém nome da cidade.
	 *
	*/
	void setCidade(string) throw(invalid_argument);

	/**
	 * Método para o acesso ao nome da cidade.
	 *
	 * Esse método acessa o número da conta corrente relacionada a ele no
	 * código principal e retorna o seu valor.
	 *
	 * @return cidade string com o nome da cidade.
	 *
	*/
	string getCidade() const {
		return cidade;
	}
};

/**
*Classe da classificação do evento.
*
* A classe descreve a classificação do evento de um
* determinado evento.Seus métodos validam uma
* string do classificação do evento, criam essa string e retornam
* o string criada ao usuário.
*/

class ClasseEvento {
private:
	int classe; 

	const static int VALOR_MIN = 1; 
	const static int VALOR_MAX = 4; 

	// Metodo de validacao
	void validar(int) throw(invalid_argument);

public:
	// Metodos de acesso


	/**
	 * Método para criação do classificação do evento
	 *
	 * Esse método invoca o outro método para validar o valor fornecido pelo usuário para a string
	 * correspondente a classificação do evento. Se ele for válido, o
	 * classificação do evento é criado contendo aquele valor específico.
	 * Se ela não for válido, o classificação do evento não é criado.
	 *
	 * @param classe int que correspondente ao classificação do evento.
	 *
	*/

	void setClasseEvento(int) throw(invalid_argument);

	/**
	 * Método para o acesso ao classificação do evento.
	 *
	 * Esse método acessa o classificação do evento relacionado a ele no
	 * programa e retorna o seu valor.
	 *
	 * @return classe int com o número do classificação do evento.
	 *
	*/

	int getClasseEvento() const {
		return classe;
	}
};

/** 
 *  Classe do código do evento.
 *  
 *  A classe descreve um código do evento. Seus métodos validam o código do evento,
 *  criam esse código e retornam o código criado ao usuário.  
 */

class CodigoEvento: public ChecaNumero{
	private:

		string codigo; 

		const static int LIMITE = 3; 

		// Metodo de validacao
		void validar(string) throw (invalid_argument); 

	public:
		// Metodos de acesso

		
		/**
		 * Método para criação do código de evento.
		 * 
		 * Esse método invoca o outro método para validar
		 * o valor fornecido pelo usuário para a string código. Se ele for 
		 * válido, o código de evento é criado contendo aquele valor específico. Se 
		 * ele não for válido, o código de evento não é criado. 
		 * 
		 * @param codigo string que contém os números correspondente ao código de evento. 
		 * 
		*/
		void setCodigoEvento(string) throw (invalid_argument);


		/**
		 * Método para o acesso ao código do evento.
		 * 
		 * Esse método acessa a evento relacionada a ele no 
		 * código principal e retorna o seu código. 
		 * 
		 * @return codigo string com o valor do código de evento. 
		 * 
		*/

		string getCodigoEvento() const {
			return codigo;

		}
};


/** 
 *  Classe do código da apresentação.
 *  
 *  A classe descreve um código da apresentacao. Seus métodos validam um 
 *  código, criam esse código e retornam o código criado 
 *  ao usuário.  
 */

class CodigoApresentacao:public ChecaNumero {
	private:
		string codigo; 

		const static int LIMITE = 4; 

		// Metodo de validacao
		
		void validar(string) throw (invalid_argument);

	public:
		// Metodos de acesso


		/**
		 * Método para criação do código de aparesentação.
		 * 
		 * Esse método invoca o outro método para validar
		 * o valor fornecido pelo usuário para a string código. Se ele for 
		 * válido, o objeto com o número do código de apresentação é criada contendo aquele 
		 * valor específico. Se ele não for válido, o objeto não é criada. 
		 * 
		 * @param codigo string que contém os números correspondente ao banco. 
		 * 
		*/
		void setCodigoApresentacao(string) throw (invalid_argument);

		/**
		 * Método para o acesso ao código de apresentação.
		 * 
		 * Esse método acessa o número do código de apresentação relacionado a ele no 
		 * código principal passado e retorna o seu valor. 
		 * 
		 * @return codigo string que contém o valor do código da apresentação. 
		 * 
		*/
		string getCodigoApresentacao() const {
			return codigo;
		}
};

/** 
 *  Classe do código do ingresso.
 *  
 *  A classe descreve o número do código do ingresso de um 
 *  determinado evento. Seus métodos validam uma
 *  string do código do ingresso, criam essa string e retornam 
 *  o string criada ao usuário.   
 */

class CodigoIngresso :public ChecaNumero {
	private:
		string codigo; 

		const static int LIMITE = 5;  

		// Metodo de validacao
		void validar(string) throw(invalid_argument);

	public:
		// Metodos de acesso


		/**
		 * Método para criação do código do ingresso
		 * 
		 * Esse método invoca o outro método para validar o valor fornecido pelo
		 * usuário para a string correspondente ao código do ingresso. Se ele for válido,
		 * o código do ingresso é criado contendo aquele valor específico. 
		 * Se ela não for válido, o código do ingresso não é criado. 
		 * 
		 * @param codigo string correspondente ao código do ingresso. 
		 * 
		*/

		void setCodigoIngresso(string) throw(invalid_argument);

		/**
		 * Método para o acesso ao código do ingresso.
		 * 
		 * Esse método acessa o código do ingresso relacionado a ele no 
		 * programa e retorna o seu valor. 
		 * 
		 * @return codigo número do código do ingresso. 
		 * 
		*/	

		string getCodigoIngresso() const {
			return codigo;
		}
};

/**
 *  Classe do código de segurança.
 *
 *  A classe descreve o número do código de segurança de um
 *  determinado evento. Seus métodos validam uma
 *  string do código de segurança, criam essa string e retornam
 *  o string criada ao usuário.
 */

class CodigoSeguranca :public ChecaNumero {
private:
	string codigo; 

	const static int LIMITE = 3;  

	// Metodo de validacao
	void validar(string) throw(invalid_argument);

public:
	// Metodos de acesso


	/**
	 * Método para criação do código de segurança
	 *
	 * Esse método invoca o outro método para validar o valor fornecido pelo usuário para a string
	 * correspondente ao código de segurança. Se ele for válido, o
	 * código de segurança é criado contendo aquele valor específico.
	 * Se ela não for válido, o código de segurança não é criado.
	 *
	 * @param codigo string correspondente ao código de segurança.
	 *
	*/

	void setCodigoSeguranca(string) throw(invalid_argument);

	/**
	 * Método para o acesso ao código de segurança.
	 *
	 * Esse método acessa o código de segurança relacionado a ele no
	 * programa e retorna o seu valor.
	 *
	 * @return codigo número do código de segurança.
	 *
	*/

	string getCodigoSeguranca() const {
		return codigo;
	}
};

/**
 *  Classe do CPF.
 *
 *  A classe descreve um CPF. Seus
 *  métodos validam o nome da cidade, criam
 *  esse CPF e retornam o nome da cidade ao usuário.
 */

class CPF {
private:
	string cpf;
	
	// Metodo de validacao

	void validar(string) throw(invalid_argument);
	bool checkCPF(string);
public:

	// Metodos de acesso

	/**
	 * Método para criação do número do cpf.
	 *
	 * Esse método invoca o outro método para validar o valor fornecido pelo usuário para a string cpf.
	 * Se ele for válido, o número de CPF é criado contendo aquele valor específico. Se ele não for válido,
	 * o número de CPF não é criado.
	 *
	 * @param cpf string que contém o número do CPF.
	 *
	*/
	void setCPF(string) throw(invalid_argument);

	/**
	 * Método para o acesso ao número do cpf.
	 *
	 * Esse método acessa o número da conta corrente relacionada a ele no
	 * código principal e retorna o seu valor.
	 *
	 * @return cpf string contendo o número de CPF.
	 *
	*/
	string getCPF(){
		return cpf;
	}
};

/**
 *  Classe da data.
 *
 *  A classe descreve uma data. Seus métodos validam a data,
 *  criam essa data e retornam a data criada ao usuário.
 */

class Data {
	private:
		string data; 
		
		// Defincao de constantes limites para Dia, Mes e Ano

		const static int DIA_MIN = 01;
		const static int DIA_31 = 31;
		const static int DIA_30 = 30;
		const static int DIA_29 = 29;
		const static int DIA_28 = 28;
		const static int MES_MIN = 01;
		const static int MES_MAX = 12;
		const static int ANO_MIN = 00;
		const static int ANO_MAX = 99;


		// Metodo de validacao
		void validar(string) throw(invalid_argument);

	public:
		// Metodos de acesso

		/**
		 * Método para criação da data.
		 * 
		 * Esse método invoca o método para validar
		 * o valor fornecido pelo usuário para a string data.
		 * Se a string for válida, a data é criada contendo 
		 * a string. Se eles não forem válidos, a data 
		 * não é criada. 
		 * 
		 * @param data string que corresponde a data no formato dd/mm/yy.
		 * 
		*/
		void setData(string) throw (invalid_argument);

		/**
		 * Método para o acesso à data.
		 * 
		 * Esse método acessa a data relacionada a ele no 
		 * código principal e retorna o seu valor. 
		 * 
		 * @return data string com o a data. 
		 * 
		*/
		string getData() const {
			return data;
		}
};

/** 
 *  Classe da data de validade.
 *  
 *  A classe descreve uma data de validade. Seus métodos validam 
 *  a data de validade, criam essa data de validade e retornam a 
 *  data de validade criada ao usuário.  
 */

class DataValidade {
	private:
		string dt_validade;
		
		// Metodos de validacao
		void validar(string) throw(invalid_argument);

	public:

		/**
		 * Método para criação da data de validade.
		 * 
		 * Esse método invoca o outro método para validar
		 * os inteiros de dia e de ano fornecidos pelo usuário para . Se eles forem 
		 * válidos, a data de validade é criada contendo aqueles valores específicos. 
		 * Se não forem válidos, a data de validade não é criada. 
		 * 
		 * @param dt_validade string que contém a data.
		 * 
		*/
		void setDataDeValidade(string) throw(invalid_argument);

		/**
		 * Método para o acesso à data de validade.
		 * 
		 * Esse método acessa a data de validade relacionada a ele no 
		 * código principal e retorna o seu valor. 
		 * 
		 * @return dt_validade data de validade. 
		 * 
		*/
		string getDataDeValidade() const {
			return dt_validade;
		}
};

/**
 *  Classe do disponibilidade.
 *
 *  A classe descreve a disponibilidade para um evento. Seus métodos validam a disponibilidade,
 *  criam esse disponibilidade e retornam a disponibilidade criada ao usuário.
 */

class Disponibilidade {
private:
	int disponibilidade; 

	const static int LIMITE_MIN = 0; 
	const static int LIMITE_MAX = 250; 


	// Metodo de validacao

	void validar(int) throw(invalid_argument);

public:
	// Metodos de acesso

	/**
	 * Método para criação da disponibilidade.
	 *
	 * Esse método invoca o outro método para validar o inteiro fornecido pelo
	 * usuário para a disponibilidade. Se ela for válida, a disponibilidade é criada
	 * contendo o valor forneciso. Se o valor não for valido, a disponibilidade não é criada.
	 *
	 * @param disponibilidade int entre 0 e 250 correspondendo a disponibilidade.
	 *
	*/
	void setDisponibilidade(int) throw(invalid_argument);

	/**
	 * Método para o acesso ao disponibilidade.
	 *
	 * Esse método acessa o disponibilidade relacionada a ele no
	 * código principal e retorna o seu valor.
	 *
	 * @return disponibilidade int contendo o valor da disponibilidade.
	 *
	*/
	int getDisponibilidade() const {
		return disponibilidade;
	}
};

/** 
 *  Classe do estado.
 *  
 *  A classe descreve um estado. Seus métodos validam a sigla do
 *  estado, criam esse estado com essa sigla e retornam a sigla 
 *  criada ao usuário.  
 */

class Estado {
	private:
		string estado; 

		// Limite de tamanho de estado

		const static int LIMITE = 2; 

		// Metodo de valdiacao

		void validar(string) throw(invalid_argument);

	public:
		// Metodos de acesso

		/**
		 * Método para criação do estado.
		 * 
		 * Esse método invoca o outro método para validar
		 * a string com a sigla do estado fornecida pelo usuário. Se ela for 
		 * válida, o estado é criado contendo aquela string específica. Se 
		 * ela não for válida, o estado não é criada. 
		 * 
		 * @param estado string que contém a sigla de um estado brasileiro. 
		 * 
		*/
		void setEstado(string) throw(invalid_argument);

		/**
		 * Método para o acesso ao estado.
		 * 
		 * Esse método acessa o estado relacionado a ele no 
		 * código principal e retorna o seu valor. 
		 * 
		 * @return valor do estado. 
		 * 
		*/
		string getEstado() const {
			return estado;
		}
};

/** 
 *  Classe da faixa etária.
 *  
 *  A classe descreve um faixa etária. Seus métodos validam o faixa etária,
 *  criam esse faixa etária e retornam o faixa etária criado ao usuário.  
 */

class FaixaEtaria {
	private:
		string faixa_et;

		// Definicoes de limites para os caracteres do faixa etária em codigo ASCII 

		string LIM_FAIXA_L= "L",LIM_FAIXA_10 = "10", LIM_FAIXA_12 = "12", LIM_FAIXA_14 = "14", LIM_FAIXA_16 = "16", LIM_FAIXA_18 = "18";

		// Metodo de validacao

		void validar(string) throw(invalid_argument);
		

	public:
		// Metodos de acesso

		/**
		 * Método para criação do faixa etária.
		 * 
		 * Esse método invoca o outro método para validar
		 * a string faixa etária fornecida pelo usuário. Se ela for válida, a faixa etária
		 * é criada contendo aquela string específica. Se ele não for válida, 
		 * o faixa etária não é criada. 
		 * 
		 * @param faixa_et string que contém a faixa etária. 
		 * 
		*/
		void setFaixaEtaria(string) throw(invalid_argument);

		/**
		 * Método para o acesso ao faixa etária.
		 * 
		 * Esse método acessa o faixa etária relacionado a ele no 
		 * código principal e retorna o seu valor. 
		 * 
		 * @return faixa_et string que contém a faixa etária. 
		 * 
		*/
		string getFaixaEtaria(){
			return faixa_et;
		}
};

/**
 *  Classe do horário do evento.
 *
 *  A classe descreve uma data. Seus métodos validam a data,
 *  criam essa data e retornam a data criada ao usuário.
 */

class Horario:public ChecaPresente {
private:

	string horario;

	const static int LIMITE_HR_MIN = 07, LIMITE_HR_MAX = 22;
	int LIMITE_MIN[4] = { 00, 15, 30, 45 };

	void validar(string) throw (invalid_argument);

public:
	// Metodos de acesso


	/**
	 * Método para criação do horário.
	 *
	 * Esse método invoca o outro método para validar
	 * o valor fornecido pelo usuário para a string horario. Se ele for
	 * válido, o horario de evento é criado contendo aquele valor específico. Se
	 * ele não for válido, o código de evento não é criado.
	 *
	 * @param horario string que contém os horario do evento.
	 *
	*/
	void setHorario(string) throw (invalid_argument);


	/**
	 * Método para o acesso ao código do evento.
	 *
	 * Esse método acessa a evento relacionada a ele no
	 * código principal e retorna o seu código.
	 *
	 * @return horario string contendo o horário.
	 *
	*/

	string getHorario() const {
		return horario;
	}
};

 /**
  *  Classe do nome do evento.
  *
  *  A classe descreve o nome de uma cidade. Seus
  *  métodos validam o nome da cidade, criam
  *  essa cidade e retornam o nome da cidade ao usuário.
  */

class NomeEvento {
private:
	string nm_evento;

	const static int LIMITE = 20;

	// Metodo de validacao

	void validar(string) throw(invalid_argument);

public:

	// Metodos de acesso

	/**
	 * Método para criação do número da conta corrente.
	 *
	 * Esse método invoca o outro método para validar o valor fornecido pelo usuário para a string numero.
	 * Se ele for válido, o número da conta corrente é criado contendo aquele valor específico. Se ele não for válido,
	 * o número da conta corrente não é criado.
	 *
	 * @param numero string que contém os números correspondente ao
	 * número da conta corrente.
	 *
	*/
	void setNomeEvento(string) throw(invalid_argument);

	/**
	 * Método para o acesso ao número da conta corrente.
	 *
	 * Esse método acessa o número da conta corrente relacionada a ele no
	 * código principal e retorna o seu valor.
	 *
	 * @return nome do evento.
	 *
	*/
	string getNomeEvento() const {
		return nm_evento;
	}
};

/**
 *  Classe do número da sala.
 *
 *  A classe descreve um número da sala. Seus
 *  métodos validam o número da sala, criam
 *  esse número e retornam o número da sala criada
 *  ao usuário.
 */

class NumeroSala {
private:
	int numero; 

	const static int LIMITE_MIN = 1; 
	const static int LIMITE_MAX = 10; 

	void validar(int) throw (invalid_argument);

public:

	//Metodos de acesso

	/**
	 * Método para criação do número da sala.
	 *
	 * Esse método invoca o outro método para validar o valor fornecido pelo usuário
	 * para o numero. Se ele for válido, o número da sala é criada contendo
	 * aquele valor específico. Se ele não for válido, o número da sala não é criado.
	 *
	 * @param numero int número correspondente ao número da sala.
	 *
	*/
	void setNumero(int) throw(invalid_argument);

	/**
	 * Método para o acesso ao número da sala.
	 *
	 * Esse método acessa o número da sala relacionado a ele no
	 * código principal e retorna o seu valor.
	 *
	 * @return numero int do número da sala.
	 *
	*/
	int getNumero() const {
		return numero;
	}

};

/**
 *  Classe do número de cartão de crédito.
 *
 *  A classe descreve uma número de cartão de crédito. Seus
 *  métodos validam o número de cartão de crédito, criam
 *  esse número e retornam o número de cartão de crédito criado
 *  ao usuário.
 */

class NumeroCartaoCredito {
	private:
		string numero;

		// Quantidade minima de numeros que o numero do cartao deve ter

		const static int LIMITE = 16; /**< inteiro correspondente ao limite de caracteres da string numero */

		// Metodo de validacao

		void validar(string) throw (invalid_argument);
		bool checkLuhn(string numero);

	public:

		//Metodos de acesso

		/**
		 * Método para criação do número do cartão de crédito.
		 * 
		 * Esse método invoca o outro método para validar o valor fornecido pelo
		 * usuário para a string numero.Se ele for válido, o número do cartão de crédito
		 * é criado contendo aquele valor específico. Se ele não for válido, o número do cartão
		 * de crédito não é criado. 
		 * 
		 * @param numero string que contém os números correspondente ao 
		 * número do cartão de crédito. 
		 * 
		 * @see checkLuhn()
		*/
		void setNumero(string) throw(invalid_argument);

		/**
		 * Método para o acesso ao número cartão de crédito.
		 * 
		 * Esse método acessa o número do cartão de crédito relacionado a ele no 
		 * código principal e retorna o seu valor. 
		 * 
		 * @return numero string contendo o número do cartão de crédito. 
		 * 
		*/
		string getNumero() const {
			return numero;
		}

};

/**
 *  Classe do preço do evento.
 *
 *  A classe descreve um tipo de acomodação. Seus métodos validam
 *  o tipo de acomodação, criam esse tipo e retornam o tipo de
 *  acomodação criado ao usuário.
 */

class Preco {
private:
	string preco; 

	float PRECO_MIN = 0;
	float PRECO_MAX = 1000;

	// Metodo de validacao

	void validar(string) throw(invalid_argument);

public:

	// Metodos de acesso

	/**
	 * Método para criação do preço.
	 *
	 * Esse método invoca o outro método para validar a string preco.
	 * Se ela for válida, o tipo de acomodação é criado contendo aquela string específica.
	 * Se ele não for válida, o tipo de acomodação não é criado.
	 *
	 * @param preco string que contém o preço.
	 *
	*/
	void setPreco(string) throw(invalid_argument);

	/**
	 * Método para o acesso ao tipo de acomodação.
	 *
	 * Esse método acessa o tipo de acomodação relacionada a ele no
	 * código principal e retorna o seu valor.
	 *
	 * @return preco string contendo o valor do preço.
	 *
	*/
	string getPreco() const {
		return preco;
	}
};

/** 
 *  Classe da senha.
 *  
 *  A classe descreve uma senha. Seus métodos validam a senha,
 *  criam essa senha e retornam a senha criada ao usuário.  
 */

class Senha{
	private:
		string senha;
		
		const static int LIMITE = 6;
		
		// Metodo para validacao
		void validar(string) throw(invalid_argument);
	public:

		// Metodos de acesso

		/**
		 * Método para criação da senha.
		 * 
		 * Esse método invoca o outro método para validar
		 * o valor fornecido pelo usuário para a string senha. Se ele for 
		 * válido, a senha é criada contendo aquele valor específico. Se 
		 * ele não for válido, a senha não é criada. 
		 * 
		 * @param senha string que contém os números correspondente à senha. 
		 * 
		*/
		void setSenha(string) throw(invalid_argument);

		/**
		 * Método para o acesso à senha.
		 * 
		 * Esse método acessa a senha relacionada a ele no 
		 * código principal e retorna o seu valor. 
		 * 
		 * @return senha string contendo a senha. 
		 * 
		*/
		string getSenha() const {
			return senha;
		}
};


#endif // DOMINIOS_H_INCLUDED
