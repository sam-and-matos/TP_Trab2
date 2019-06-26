/** 
 *  @file testes.h
 *  Assinatura de todos os testes de unidade do software de hospedagem em viagens.
 *  
 *  Estes testes são implementados por classes e seus métodos, que são capazes de 
 *  testar cada um dos domínios necessários para o software de hospedagem em viagens 
 * e determinar se eles estão em um bom funcionamento ou não.
 */

#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"
#include <iostream>
#include <string>

using namespace std;

// Declaração de classes.

/** 
 *  Classe de Teste de Unidade da Agência.
 *  
 *  A classe descreve o teste de unidade de uma agência. Seus métodos criam e 
 *  destroem essa agência. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUCodigoEvento {
    private:

        // Definições de constantes para evitar numeros mágicos.
    
        string VALOR_VALIDO   = "295"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO = "3000"; /**< string contendo um exemplo de valor inválido */

        // Referência para o objeto a ser testado.

        CodigoEvento *codigo; /**< instância da classe para a execução de testes unitários */
		
        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe Agencia estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see Agencia
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe Agencia estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see Agencia
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUCodigoEvento::setUp()
         * @see TUCodigoEvento::tearDown()
         * @see TUCodigoEvento::testarCenarioSucesso()
         * @see TUCodigoEvento::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade do Codigo de Apresentação.
 *  
 *  A classe descreve o teste de unidade de um código de apresentação. Seus métodos criam e 
 *  destroem este. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUCodigoApresentacao {
    private:

        // Definições de constantes para evitar numeros mágicos.
    
        string VALOR_VALIDO   = "3244"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO = "40000"; /**< string contendo um exemplo de valor inválido */

        // Referência para o objeto a ser testado.

        CodigoApresentacao *codigo; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe Banco estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see Banco
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe Banco estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see Banco
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUCodigoApresentacao::setUp()
         * @see TUCodigoApresentacao::tearDown()
         * @see TUCodigoApresentacao::testarCenarioSucesso()
         * @see TUCodigoApresentacao::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade da Capacidade de Acomodação.
 *  
 *  A classe descreve o teste de unidade de uma capacidade de acomodação. Seus métodos criam e 
 *  destroem essa capacidade de acomodação. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUCodigoIngresso {
    private:

        // Definições de constantes para evitar numeros mágicos.
    
		string VALOR_VALIDO = "32444"; /**< string contendo um exemplo de valor válido */
		string VALOR_INVALIDO = "400000"; /**< string contendo um exemplo de valor inválido */

        // Referência para o objeto a ser testado.

        CodigoIngresso *codigo; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe CodigoIngresso estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see CodigoIngresso
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe CodigoIngresso estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see CodigoIngresso
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUCodigoIngresso::setUp()
         * @see TUCodigoIngresso::tearDown()
         * @see TUCodigoIngresso::testarCenarioSucesso()
         * @see TUCodigoIngresso::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade da Diária.
 *  
 *  A classe descreve o teste de unidade de uma diária. Seus métodos criam e 
 *  destroem essa diária. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUNomeEvento {

    private:

        // Definições de constantes para evitar numeros m�gicos.

		string VALOR_VALIDO = "Show Luan Santana"; /**< string contendo um exemplo de valor válido */
		string VALOR_INVALIDO = "Show  Luan  Santana"; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        NomeEvento *nm_evento; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe NomeEvento estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see NomeEvento
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe NomeEvento estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see NomeEvento
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUNomeEvento::setUp()
         * @see TUNomeEvento::tearDown()
         * @see TUNomeEvento::testarCenarioSucesso()
         * @see TUNomeEvento::testarCenarioFalha()
         * 
		*/
        int run();
};


/** 
 *  Classe de Teste de Unidade da Data.
 *  
 *  A classe descreve o teste de unidade de uma data. Seus métodos criam e 
 *  destroem essa data. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */

class TUData {

    private:

        // Definições de constantes para evitar numeros m�gicos.
        
        string VALOR_VALIDO  = "28/02/12"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO = "30/02/12"; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        Data *data; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe Data estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see Data
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe Data estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see Data
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUData::setUp()
         * @see TUData::tearDown()
         * @see TUData::testarCenarioSucesso()
         * @see TUData::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade da Data de Validade.
 *  
 *  A classe descreve o teste de unidade de uma data de validade. Seus métodos criam e 
 *  destroem essa data de validade. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUDataValidade {

    private:

        // Definições de constantes para evitar numeros m�gicos.

		const string VALOR_VALIDO = "09/21";
		const string VALOR_INVALIDO = "13/18";

        // Refer�ncia para o objeto a ser testado.

        DataValidade *dataValidade; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe DataValidade estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see DataValidade
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe DataValidade estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see DataValidade
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUDataValidade::setUp()
         * @see TUDataValidade::tearDown()
         * @see TUDataValidade::testarCenarioSucesso()
         * @see TUDataValidade::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade do Estado.
 *  
 *  A classe descreve o teste de unidade de um estado brasileiro. Seus métodos criam e 
 *  destroem esse estado. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUEstado {

    private:

        // Definições de constantes para evitar numeros m�gicos.

        string VALOR_VALIDO   = "GO"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO = "RT"; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        Estado *estadoBr; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe Estado estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see Estado
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe Estado estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see Estado
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUEstado::setUp()
         * @see TUEstado::tearDown()
         * @see TUEstado::testarCenarioSucesso()
         * @see TUEstado::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade do Identificador.
 *  
 *  A classe descreve o teste de unidade de um identificador. Seus métodos criam e 
 *  destroem esse identificador. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUHorario {

    private:

        // Definições de constantes para evitar numeros m�gicos.

        string VALOR_VALIDO   = "07:30"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO = "07:22"; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        Horario *horario; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe Identificador estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see Identificador
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe Identificador estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see Identificador
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUIdentificador::setUp()
         * @see TUIdentificador::tearDown()
         * @see TUIdentificador::testarCenarioSucesso()
         * @see TUIdentificador::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade do Nome.
 *  
 *  A classe descreve o teste de unidade de um nome. Seus métodos criam e 
 *  destroem esse nome. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUPreco {

    private:

        // Definições de constantes para evitar numeros m�gicos.

        string VALOR_VALIDO = "100,00"; /**< string contendo um exemplo de valor válido */
		string VALOR_VALIDO1 = "100.00"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO1 = "1250,00"; /**< string contendo um exemplo de valor inválido */
        string VALOR_INVALIDO2 = "1250.00"; /**< string contendo um exemplo de valor inválido */
        
        // Refer�ncia para o objeto a ser testado.

        Preco *preco; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe Nome estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see Nome
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe Nome estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see Nome
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUPreco::setUp()
         * @see TUPreco::tearDown()
         * @see TUPreco::testarCenarioSucesso()
         * @see TUPreco::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade do Número do Cartão de Crédito.
 *  
 *  A classe descreve o teste de unidade de um número do cartão de crédito. Seus métodos criam e 
 *  destroem esse número do cartão de crédito. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUNumeroCartaoCredito {

    private:

        // Definições de constantes para evitar numeros m�gicos.

        string VALOR_VALIDO    = "4717415691789511"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO1 = "2020101033445678"; /**< string contendo um exemplo de valor inválido */
        string VALOR_INVALIDO2 = "21679010301234567890"; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        NumeroCartaoCredito *numeroCartaoCredito; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe NumeroCartaoCredito estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see NumeroCartaoCredito
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe NumeroCartaoCredito estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see NumeroCartaoCredito
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUNumeroCartaoCredito::setUp()
         * @see TUNumeroCartaoCredito::tearDown()
         * @see TUNumeroCartaoCredito::testarCenarioSucesso()
         * @see TUNumeroCartaoCredito::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade do Número da Conta Corrente.
 *  
 *  A classe descreve o teste de unidade de um número da conta corrente. Seus métodos criam e 
 *  destroem esse número da conta corrente. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUNumeroSala {

    private:

        // Definições de constantes para evitar numeros m�gicos.

        int VALOR_VALIDO   = 3; /**< string contendo um exemplo de valor válido */
        int VALOR_INVALIDO = 12; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        NumeroSala *sala; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe NumeroContaCorrente estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see NumeroContaCorrente
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe NumeroContaCorrente estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see NumeroContaCorrente
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUNumeroSala::setUp()
         * @see TUNumeroSala::tearDown()
         * @see TUNumeroSala::testarCenarioSucesso()
         * @see TUNumeroSala::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade da Senha.
 *  
 *  A classe descreve o teste de unidade de uma senha. Seus métodos criam e 
 *  destroem essa senha. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUSenha {

    private:

        // Definições de constantes para evitar numeros m�gicos.

        string VALOR_VALIDO    = "Ab02Cd"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO1 = "0$Invalido"; /**< string contendo um exemplo de valor inválido */
        string VALOR_INVALIDO2 = "&!!234Ab"; /**< string contendo um exemplo de valor inválido */
        string VALOR_INVALIDO3 = "Tg2#"; /**< string contendo um exemplo de valor inválido */
        string VALOR_INVALIDO4 = "testes12"; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        Senha *senha; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe Senha estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see Senha
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe Senha estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see Senha
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUSenha::setUp()
         * @see TUSenha::tearDown()
         * @see TUSenha::testarCenarioSucesso()
         * @see TUSenha::testarCenarioFalha()
         * 
		*/
        int run();
};

/** 
 *  Classe de Teste de Unidade da Cidade.
 *  
 *  A classe descreve o teste de unidade de um objeto tipo Cidade. Seus métodos criam e 
 *  destroem esse objeto. Seus métodos também apresentam exemplos de valores 
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de 
 *  falha.
 *  
 */
class TUCidade {

    private:

        // Definições de constantes para evitar numeros m�gicos.

        string VALOR_VALIDO   = "Taguatinga"; /**< string contendo um exemplo de valor válido */
        string VALOR_INVALIDO = "Taguatinga.  .o"; /**< string contendo um exemplo de valor inválido */

        // Refer�ncia para o objeto a ser testado.

        Cidade *cidade; /**< instância da classe para a execução de testes unitários */

        // Estado do teste.

        int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

        // Declarações de métodos.
        
        /**
		 * Método para criar a classe a ser testada.
		 * 
		 * Esse método cria a classe que passará pelos testes unitários.
         * Se ela for criada sem erros, esse método iguala o estado do 
         * teste ao índice que corresponde ao sucesso da classe ter sido 
         * criada.
		 * 
		*/
        void setUp();

        /**
		 * Método para testar a classe em um cenário de sucesso.
		 * 
		 * Esse método testa se os métodos da classe TipoAcomodacao estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
         * o estado é igualado a SUCESSO do teste. Se não for, o estado é 
         * igualado a FALHA do teste.
         * 
         * @see TipoAcomodacao
		 * 
		*/
        void testarCenarioSucesso();

        /**
		 * Método para testar a classe em um cenário de falha.
		 * 
		 * Esse método testa se os métodos da classe TipoAcomodacao estão
         * funcionando perfeitamente para um cenário em que a entrada
         * do exemplo deve ser falha. Se ela falhar, o estado é igualado 
         * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA 
         * do teste.
         * 
         * @see TipoAcomodacao
		 * 
		*/
        void testarCenarioFalha();

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
		*/
        void tearDown();

    public:

        // Definições de constantes para reportar resultado do teste.

        const static int SUCESSO =  0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
        const static int FALHA   = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

        /**
		 * Método para destruir a classe que foi testada.
		 * 
		 * Esse método destroi a classe que passou pelos testes unitários.
		 * 
         * @see TUCidade::setUp()
         * @see TUCidade::tearDown()
         * @see TUCidade::testarCenarioSucesso()
         * @see TUCidade::testarCenarioFalha()
         * 
		*/
        int run();
};

/**
 *  Classe de Teste de Unidade da Disponibilidade.
 *
 *  A classe descreve o teste de unidade de um objeto Disponibilidade. Seus métodos criam e
 *  destroem esse objeto. Seus métodos também apresentam exemplos de valores
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de
 *  falha.
 *
 */
class TUDisponibilidade {

private:

	// Definições de constantes para evitar numeros m�gicos.

	int VALOR_VALIDO = 50; /**< int contendo um exemplo de valor válido */
	int VALOR_INVALIDO = 350; /**< int contendo um exemplo de valor inválido */

	// Refer�ncia para o objeto a ser testado.

	Disponibilidade* disponibilidade; /**< instância da classe para a execução de testes unitários */

	// Estado do teste.

	int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

	// Declarações de métodos.

	/**
	 * Método para criar a classe a ser testada.
	 *
	 * Esse método cria a classe que passará pelos testes unitários.
	 * Se ela for criada sem erros, esse método iguala o estado do
	 * teste ao índice que corresponde ao sucesso da classe ter sido
	 * criada.
	 *
	*/
	void setUp();

	/**
	 * Método para testar a classe em um cenário de sucesso.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
	 * o estado é igualado a SUCESSO do teste. Se não for, o estado é
	 * igualado a FALHA do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioSucesso();

	/**
	 * Método para testar a classe em um cenário de falha.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser falha. Se ela falhar, o estado é igualado
	 * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA
	 * do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioFalha();

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	*/
	void tearDown();

public:

	// Definições de constantes para reportar resultado do teste.

	const static int SUCESSO = 0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
	const static int FALHA = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	 * @see TUDisponibilidade::setUp()
	 * @see TUDisponibilidade::tearDown()
	 * @see TUDisponibilidade::testarCenarioSucesso()
	 * @see TUDisponibilidade::testarCenarioFalha()
	 *
	*/
	int run();
};

/**
 *  Classe de Teste de Unidade da Classe do Evento.
 *
 *  A classe descreve o teste de unidade de um objeto ClasseEvento. Seus métodos criam e
 *  destroem esse objeto. Seus métodos também apresentam exemplos de valores
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de
 *  falha.
 *
 */
class TUClasseEvento {

private:

	// Definições de constantes para evitar numeros m�gicos.

	int VALOR_VALIDO = 1; /**< int contendo um exemplo de valor válido */
	int VALOR_INVALIDO = 5; /**< int contendo um exemplo de valor inválido */

	// Refer�ncia para o objeto a ser testado.

	ClasseEvento* classe; /**< instância da classe para a execução de testes unitários */

	// Estado do teste.

	int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

	// Declarações de métodos.

	/**
	 * Método para criar a classe a ser testada.
	 *
	 * Esse método cria a classe que passará pelos testes unitários.
	 * Se ela for criada sem erros, esse método iguala o estado do
	 * teste ao índice que corresponde ao sucesso da classe ter sido
	 * criada.
	 *
	*/
	void setUp();

	/**
	 * Método para testar a classe em um cenário de sucesso.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
	 * o estado é igualado a SUCESSO do teste. Se não for, o estado é
	 * igualado a FALHA do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioSucesso();

	/**
	 * Método para testar a classe em um cenário de falha.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser falha. Se ela falhar, o estado é igualado
	 * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA
	 * do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioFalha();

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	*/
	void tearDown();

public:

	// Definições de constantes para reportar resultado do teste.

	const static int SUCESSO = 0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
	const static int FALHA = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	 * @see TUClasseEvento::setUp()
	 * @see TUClasseEvento::tearDown()
	 * @see TUClasseEvento::testarCenarioSucesso()
	 * @see TUClasseEvento::testarCenarioFalha()
	 *
	*/
	int run();
};

/**
 *  Classe de Teste de Unidade da Faixa Etária.
 *
 *  A classe descreve o teste de unidade de um objeto FaixaEtaria. Seus métodos criam e
 *  destroem esse objeto. Seus métodos também apresentam exemplos de valores
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de
 *  falha.
 *
 */
class TUFaixaEtaria {

private:

	// Definições de constantes para evitar numeros m�gicos.

	string VALOR_VALIDO = "12"; /**< string contendo um exemplo de valor válido */
	string VALOR_INVALIDO = "20"; /**< string contendo um exemplo de valor inválido */

	// Refer�ncia para o objeto a ser testado.

	FaixaEtaria* faixa; /**< instância da classe para a execução de testes unitários */

	// Estado do teste.

	int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

	// Declarações de métodos.

	/**
	 * Método para criar a classe a ser testada.
	 *
	 * Esse método cria a classe que passará pelos testes unitários.
	 * Se ela for criada sem erros, esse método iguala o estado do
	 * teste ao índice que corresponde ao sucesso da classe ter sido
	 * criada.
	 *
	*/
	void setUp();

	/**
	 * Método para testar a classe em um cenário de sucesso.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
	 * o estado é igualado a SUCESSO do teste. Se não for, o estado é
	 * igualado a FALHA do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioSucesso();

	/**
	 * Método para testar a classe em um cenário de falha.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser falha. Se ela falhar, o estado é igualado
	 * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA
	 * do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioFalha();

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	*/
	void tearDown();

public:

	// Definições de constantes para reportar resultado do teste.

	const static int SUCESSO = 0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
	const static int FALHA = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	 * @see TUFaixaEtaria::setUp()
	 * @see TUFaixaEtaria::tearDown()
	 * @see TUFaixaEtaria::testarCenarioSucesso()
	 * @see TUFaixaEtaria::testarCenarioFalha()
	 *
	*/
	int run();
};

/**
 *  Classe de Teste de Unidade do CPF.
 *
 *  A classe descreve o teste de unidade de um obejto CPF. Seus métodos criam e
 *  destroem esse objeto. Seus métodos também apresentam exemplos de valores
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de
 *  falha.
 *
 */
class TUCPF {

private:

	// Definições de constantes para evitar numeros m�gicos.

	string VALOR_VALIDO = "544.628.796-78"; /**< string contendo um exemplo de valor válido */
	string VALOR_INVALIDO = "544.628.796-54"; /**< string contendo um exemplo de valor inválido */
	string VALOR_INVALIDO2 = "54462879654";

	// Refer�ncia para o objeto a ser testado.

	CPF* cpf; /**< instância da classe para a execução de testes unitários */

	// Estado do teste.

	int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

	// Declarações de métodos.

	/**
	 * Método para criar a classe a ser testada.
	 *
	 * Esse método cria a classe que passará pelos testes unitários.
	 * Se ela for criada sem erros, esse método iguala o estado do
	 * teste ao índice que corresponde ao sucesso da classe ter sido
	 * criada.
	 *
	*/
	void setUp();

	/**
	 * Método para testar a classe em um cenário de sucesso.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
	 * o estado é igualado a SUCESSO do teste. Se não for, o estado é
	 * igualado a FALHA do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioSucesso();

	/**
	 * Método para testar a classe em um cenário de falha.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser falha. Se ela falhar, o estado é igualado
	 * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA
	 * do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioFalha();

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	*/
	void tearDown();

public:

	// Definições de constantes para reportar resultado do teste.

	const static int SUCESSO = 0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
	const static int FALHA = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	 * @see TUCPF::setUp()
	 * @see TUCPF::tearDown()
	 * @see TUCPF::testarCenarioSucesso()
	 * @see TUCPF::testarCenarioFalha()
	 *
	*/
	int run();
};

/**
 *  Classe de Teste de Unidade do Codigo de Segurança.
 *
 *  A classe descreve o teste de unidade de um obejto CodigoSeguranca. Seus métodos criam e
 *  destroem esse objeto. Seus métodos também apresentam exemplos de valores
 *  válidos e inválidos para esse domínio, checando se os valores válidos passam
 *  cenários de sucesso e se os inválidos têm exceção lançada nos cenários de
 *  falha.
 *
 */
class TUCodigoSeguranca {

private:

	// Definições de constantes para evitar numeros m�gicos.

	string VALOR_VALIDO = "529"; /**< string contendo um exemplo de valor válido */
	string VALOR_INVALIDO = "4567"; /**< string contendo um exemplo de valor inválido */

	// Refer�ncia para o objeto a ser testado.

	CodigoSeguranca* codigo; /**< instância da classe para a execução de testes unitários */

	// Estado do teste.

	int estado; /**< índice inteiro que indicará se o estado do teste é de sucesso ou de falha */

	// Declarações de métodos.

	/**
	 * Método para criar a classe a ser testada.
	 *
	 * Esse método cria a classe que passará pelos testes unitários.
	 * Se ela for criada sem erros, esse método iguala o estado do
	 * teste ao índice que corresponde ao sucesso da classe ter sido
	 * criada.
	 *
	*/
	void setUp();

	/**
	 * Método para testar a classe em um cenário de sucesso.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser bem-sucedida. Se ela for bem-sucedida,
	 * o estado é igualado a SUCESSO do teste. Se não for, o estado é
	 * igualado a FALHA do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioSucesso();

	/**
	 * Método para testar a classe em um cenário de falha.
	 *
	 * Esse método testa se os métodos da classe TipoAcomodacao estão
	 * funcionando perfeitamente para um cenário em que a entrada
	 * do exemplo deve ser falha. Se ela falhar, o estado é igualado
	 * a SUCESSO do teste. Se não falhar, o estado é igualado a FALHA
	 * do teste.
	 *
	 * @see TipoAcomodacao
	 *
	*/
	void testarCenarioFalha();

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	*/
	void tearDown();

public:

	// Definições de constantes para reportar resultado do teste.

	const static int SUCESSO = 0; /**< índice inteiro que iguala o estado do teste a 0 se este for bem-sucedido */
	const static int FALHA = -1; /**< índice inteiro que iguala o estado do teste a -1 se este for falhar */

	/**
	 * Método para destruir a classe que foi testada.
	 *
	 * Esse método destroi a classe que passou pelos testes unitários.
	 *
	 * @see TUCodigoSeguranca::setUp()
	 * @see TUCodigoSeguranca::tearDown()
	 * @see TUCodigoSeguranca::testarCenarioSucesso()
	 * @see TUCodigoSeguranca::testarCenarioFalha()
	 *
	*/
	int run();
};

#endif // TESTES_H_INCLUDED
