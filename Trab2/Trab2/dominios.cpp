#include "dominios.h"
#include <algorithm>
#include <ctime>
#include <cctype>
#include <vector>

using namespace std;

// Limite dos valores da diaria
const static float DIARIA_PRECO_MIN = 1.00;
const static float DIARIA_PRECO_MAX = 10000.00;

// Definicao de funcoes fora das classes

bool NumeroCartaoCredito::checkLuhn(string numero) {
	int nSum = 0;
	int nDigits = numero.size();
	int nParity = (nDigits - 1) % 2;
	char cDigit[2] = "\0";
	for (int i = nDigits; i > 0; i--)
	{
		cDigit[0] = numero.at(i - 1);
		int nDigit = atoi(cDigit);

		if (nParity == i % 2)
			nDigit = nDigit * 2;

		nSum += nDigit / 10;
		nSum += nDigit % 10;
	}
	return 0 == nSum % 10;
}

bool ChecaNumero::checkNumero(string numero) {
	for (string::iterator it = numero.begin(); it != numero.end(); it++) {
		if (!isdigit(*it))
			return false;
	}

	return true;
}

bool ChecaPresente::checkPresent(int num, int vector[4]) {
	int pres = 0;
	for (int i = 0; i < 4; i++) {
		if (vector[i] == num)
			pres++;
	}

	if (pres == 0)
		return false;
	else
		return true;
}

bool CPF::checkCPF(string cpf) {
	string aux1 = cpf.substr(0, 3), aux2 = cpf.substr(4, 3), aux3 = cpf.substr(8, 3), aux4 = cpf.substr(12);
	string cpf_aux = aux1 + aux2 + aux3 + aux4;
	int checka_digito = 0, digito1 = 10, digito2 = 11;
	string cpf_aux1 = cpf_aux, cpf_aux2 = cpf_aux;

	cpf_aux1.resize(9);

	for (string::const_iterator it = cpf_aux1.begin(); it != cpf_aux1.end(); it++) {
		checka_digito += ((*it - 48) * digito1);
		digito1--;
	}
	int teste_digito = cpf_aux.at(9);
	int exp1 = (checka_digito * 10) % 11;
	int exp2 = (teste_digito - 48);

	cpf_aux2.resize(10);
	if (exp1 == exp2) {
		checka_digito = 0;
		for (string::const_iterator it = cpf_aux2.begin(); it != cpf_aux2.end(); it++) {
			checka_digito += ((*it - 48) * digito1);
			digito2--;
		}
		int teste_digito2 = cpf_aux.at(10);
		int exp3 = (checka_digito * 10) % 11;
		int exp4 = (teste_digito2 - 48);
		if (exp3 != exp4)
			return false;
	}
	else
		return false;

	return true;
}

// Definições dos métodos

void Cidade::validar(string cidade) throw(invalid_argument) {
	if (cidade.length() > LIMITE)
		throw invalid_argument("Cidade invalida! Nome da cidade pode ter no máximo 15 caracteres.");
	for (string::iterator it = cidade.begin(); it != cidade.end(); it++) {
		if (!isalpha(*it) && !isspace(*it) && !isdigit(*it))
			throw invalid_argument("Cidade invalida! Nome da cidade tem que ter ao menos uma letra, ponto só pode ser precedido de letra, espaço não pode ser seguido por espaço e tem que começar com uma letra.");
		if (isspace(*it) && isspace(*(it + 1)))
			throw invalid_argument("Cidade invalida! Nome da cidade tem que ter ao menos uma letra, ponto só pode ser precedido de letra, espaço não pode ser seguido por espaço e tem que começar com uma letra.");
		if (*it == '.' && !isalpha(*(it - 1)))
			throw invalid_argument("Cidade invalida! Nome da cidade tem que ter ao menos uma letra, ponto só pode ser precedido de letra, espaço não pode ser seguido por espaço e tem que começar com uma letra.");
	}
}

void Cidade::setCidade(string cidade) throw(invalid_argument){
	validar(cidade);
	this->cidade = cidade;
}

void ClasseEvento::validar(int classe) throw(invalid_argument) {
	if (classe < VALOR_MIN || classe > VALOR_MAX)
		throw invalid_argument("Clase do Evento invalida! Somento digitos de 1 a 4 são aceitos, onde: \n 1 - Teatro\n 2 - Esporte\n 3 - Show Nacional\n 4 - Show Internacional.");
}

void ClasseEvento::setClasseEvento(int classe) throw (invalid_argument) {
	validar(classe);
	this->classe = classe;
}

void CodigoEvento::validar(string cd_evento) throw (invalid_argument) {
	if (!checkNumero(cd_evento))
		throw invalid_argument("Codigo de Evento invalido! Somente digitos sao aceitos.");
	if (cd_evento.size() != LIMITE)
		throw invalid_argument("Codigo de Evento invalido! Codigo tem que ter 3 digitos.");
}

void CodigoEvento::setCodigoEvento(string cd_evento) throw(invalid_argument) {
	validar(cd_evento);
	this->codigo = cd_evento;
}

void CodigoApresentacao::validar(string cd_apresentacao) throw (invalid_argument) {
	if (!checkNumero(cd_apresentacao))
		throw invalid_argument("Codigo de Apresentacao invalido! Somente digitos sao aceitos.");
	if (cd_apresentacao.size() != LIMITE)
		throw invalid_argument("Codigo de Apresentacao invalido! Codigo tem que ter 4 digitos.");
}

void CodigoApresentacao::setCodigoApresentacao(string cd_apresentacao) throw(invalid_argument) {
	validar(cd_apresentacao);
	this->codigo = cd_apresentacao;
}

void CodigoIngresso::validar(string cd_ingresso) throw(invalid_argument) {
	if (!checkNumero(cd_ingresso))
		throw invalid_argument("Codigo de Ingresso invalido! Somente digitos sao aceitos.");
	if (cd_ingresso.size() != LIMITE)
		throw invalid_argument("Codigo de Ingresso invalido! Codigo tem que ter 5 digitos.");
}

void CodigoIngresso::setCodigoIngresso(string cd_ingresso) throw (invalid_argument) {
	validar(cd_ingresso);
	this->codigo = cd_ingresso;
}

void CodigoSeguranca::validar(string cd_seguranca) throw(invalid_argument) {
	if (!checkNumero(cd_seguranca))
		throw invalid_argument("Codigo de Segurança invalido! Somente digitos sao aceitos.");
	if (cd_seguranca.size() != LIMITE)
		throw invalid_argument("Codigo de Segurança invalido! Codigo tem que ter 3 digitos.");
}

void CodigoSeguranca::setCodigoSeguranca(string cd_seguranca) throw (invalid_argument) {
	validar(cd_seguranca);
	this->codigo = cd_seguranca;
}

void CPF::validar(string cpf) throw(invalid_argument) {
	regex valida("^[0-9]{3}.[0-9]{3}.[0-9]{3}-[0-9]{2}$");

	if (!regex_match(cpf,valida))
		throw invalid_argument("CPF invalido! CPF tem que estar no seguinte formato: 000.000.000-00.");

	if (!checkCPF(cpf))
		throw invalid_argument("CPF invalido! Confira o CPF e tente novamente.");

}

void CPF::setCPF(string cpf) throw (invalid_argument) {
	validar(cpf);
	this->cpf = cpf;
}

void Data::validar(string data) throw (invalid_argument) {
	regex r{ "((0[1-9]|[12]\\d)\\/(0[1-9]|1[0-2])|30\\/(0[13-9]|1[0-2])|31\\/(0[13578]|1[02]))\\/\\d{2}" };


	if (!regex_match(data, r))
		throw invalid_argument("Data inválida! Verificar formato, data precisa estar no formato DD/MM/YY");

	string aux_dia = data.substr(0, 1), aux_mes, aux_ano, aux_time;
	size_t pos1 = data.find_first_of('/');
	size_t pos2 = data.find_last_of('/');
	aux_mes = data.substr(pos1 + 1, pos1 + 2);
	aux_ano = data.substr(pos2 + 1, pos2 + 2);

	size_t tam = data.length();


	switch (stoi(aux_mes))
	{
	case 1:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_31)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para janeiro.");
		break;
	case 2:
		if(stoi(aux_ano)% 4 == 0)
			if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_29)
				throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 29, para fevereiro em ano bissexto.");
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_28)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 28, para fevereiro em ano normal.");
		break;
	case 3:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_31)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para março.");
		break;
	case 4:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_30)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 30, para abril.");
		break;
	case 5:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_31)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para maio.");
		break;
	case 6:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_30)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para junho.");
		break;
	case 7:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_31)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para julho.");
		break;
	case 8:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_31)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para agosto.");
		break;
	case 9:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_30)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 30, para setembro.");
		break;
	case 10:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_31)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para outubro.");
		break;
	case 11:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_30)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 30, para novembro.");
		break;
	case 12:
		if (stoi(aux_dia) < DIA_MIN || stoi(aux_dia) > DIA_31)
			throw invalid_argument("Dia inválido! Dia deve estar entre 1 e 31, para dezembro.");
		break;
	default:
		break;
	}
}

void Data::setData(string data) throw (invalid_argument) {
	validar(data);
	this->data = data;
}

void DataValidade::validar(string dt_validade) throw (invalid_argument) {
	regex valida("^(0[135789]|1[02])\\/\\d{2}$"); // Método para criar um objeto regex.
	if (!regex_match(dt_validade, valida))
		throw invalid_argument("Data de validade invalida! Data deve estar no formato MM/YY  e ser válida, ser maior que a data atual.");
}

void DataValidade::setDataDeValidade(string dt_validade) throw (invalid_argument) {
	validar(dt_validade);
	this->dt_validade = dt_validade;
}

void Disponibilidade::validar(int disponibilidade) throw (invalid_argument) {
	if (disponibilidade < LIMITE_MIN || disponibilidade > LIMITE_MAX)
		throw invalid_argument("Disponibilidade invalida! Valor precisa estar entre 0 e 250.");
}

void Disponibilidade::setDisponibilidade(int disponibilidade) throw (invalid_argument) {
	validar(disponibilidade);
	this->disponibilidade = disponibilidade;
}

void FaixaEtaria::validar(string faixa_et) throw (invalid_argument) {
	if (faixa_et != LIM_FAIXA_L && faixa_et != LIM_FAIXA_10 && faixa_et != LIM_FAIXA_12 && faixa_et != LIM_FAIXA_14 && faixa_et != LIM_FAIXA_16 && faixa_et != LIM_FAIXA_18)
		throw invalid_argument("Faixa etária invalida! Faixa etária deve estar uma dessas: L, 10, 12, 14, 16, 18");
}

void FaixaEtaria::setFaixaEtaria(string faixa_et) throw (invalid_argument) {
	validar(faixa_et);
	this->faixa_et = faixa_et;
}

void Estado::validar(string estado) throw (invalid_argument) {
	if (estado.size() != LIMITE)
		throw invalid_argument("Estado invalido! Somente as siglas do estado são aceitas.");

	if (estado == "AC");
	else if (estado == "AL");
	else if (estado == "AP");
	else if (estado == "AM");
	else if (estado == "BA");
	else if (estado == "CE");
	else if (estado == "DF");
	else if (estado == "ES");
	else if (estado == "GO");
	else if (estado == "MA");
	else if (estado == "MG");
	else if (estado == "MS");
	else if (estado == "MT");
	else if (estado == "PA");
	else if (estado == "PB");
	else if (estado == "PE");
	else if (estado == "PI");
	else if (estado == "PR");
	else if (estado == "RJ");
	else if (estado == "RN");
	else if (estado == "RO");
	else if (estado == "RR");
	else if (estado == "RS");
	else if (estado == "SC");
	else if (estado == "SE");
	else if (estado == "SP");
	else if (estado == "TO");
	else
		throw invalid_argument("Estado invalido! Não existe estado com essa sigla.");
}

void Estado::setEstado(string estado) throw (invalid_argument) {
	validar(estado);
	this->estado = estado;
}

void Horario::validar(string horario) throw (invalid_argument) {
	string hr, min;
	hr = horario.substr(0,2);
	size_t pos = horario.find(":");
	min = horario.substr(pos + 1, pos + 2);

	if (stoi(hr) < LIMITE_HR_MIN || stoi(hr)> LIMITE_HR_MAX)
		throw invalid_argument("Horario invalido! Somente são aceitos eventos das 07 as 22 hrs");
	if (!checkPresent(stoi(min),LIMITE_MIN))
			throw invalid_argument("Horario invalido! Somente são aceitos eventos com os seguintes minutos: 00, 15, 30 e 45");
}

void Horario::setHorario(string horario) throw (invalid_argument) {
	validar(horario);
	this->horario = horario;
}

void NomeEvento::validar(string nome) throw(invalid_argument) {
	if (nome.length() > LIMITE)
		throw invalid_argument("Nome do evento invalido! Nome do evento pode ter no máximo 20 caracteres.");
	for (string::iterator it = nome.begin(); it != nome.end(); it++) {
		if (!isalpha(*it) && !isspace(*it) && !isdigit(*it))
			throw invalid_argument("Nome do evento invalido! Nome do evento tem que ter ao menos uma letra, ponto só pode ser precedido de letra, espaço não pode ser seguido por espaço e tem que começar com uma letra.");
		if (isspace(*it) && isspace(*(it + 1)))
			throw invalid_argument("Nome do evento invalido! Nome do evento tem que ter ao menos uma letra, ponto só pode ser precedido de letra, espaço não pode ser seguido por espaço e tem que começar com uma letra.");
		if (*it == '.' && !isalpha(*(it - 1)))
			throw invalid_argument("Nome do evento invalido! Nome do evento tem que ter ao menos uma letra, ponto só pode ser precedido de letra, espaço não pode ser seguido por espaço e tem que começar com uma letra.");
	}
}

void NomeEvento::setNomeEvento(string nome) throw(invalid_argument){
	validar(nome);
	this->nm_evento = nome;
}

void NumeroSala::validar(int numero) throw(invalid_argument) {
	if (numero < LIMITE_MIN || numero > LIMITE_MAX)
		throw invalid_argument("Numero da sala invalido! Sala só pode ter numero de 1 a 10.");
}

void NumeroSala::setNumero(int numero) throw(invalid_argument) {
	validar(numero);
	this->numero = numero;
}

void NumeroCartaoCredito::validar(string numero) throw (invalid_argument) {
	if (numero.size() != LIMITE)
		throw invalid_argument("Numero de cartao invalido! Numero precisa conter 16 digitos(0-9)!");

	if (!checkLuhn(numero))
		throw invalid_argument("Numero de cartão invalido! Confira o número do cartão, cartão inexistente");
}

void NumeroCartaoCredito::setNumero(string numero) throw (invalid_argument) {
	validar(numero);
	this->numero = numero;
}

void Preco::validar(string preco) throw (invalid_argument) {
	if (stof(preco) < PRECO_MIN || stof(preco) > PRECO_MAX)
		throw invalid_argument("Preço invalido! Preço deve estar entre 0,00 e 1000,00");
}

void Preco::setPreco(string preco) throw (invalid_argument) {
	validar(preco);
	this->preco = preco;
}

void Senha::validar(string senha) throw (invalid_argument) {
	string auxMaiuscula, auxMinuscula, auxNumero;

	if (senha.size() != LIMITE)
		throw invalid_argument("Tamano da senha invalido! Senha precisa conter 6 caracteres!");

	for (string::iterator it = senha.begin(); it != senha.end(); it++) {
		if (isupper(*it)) {
			if (auxMaiuscula.empty())
				auxMaiuscula += *it;
			else {
				for (string::iterator it2 = auxMaiuscula.begin(); it2 != auxMaiuscula.end(); it2++) {
					if (*it == *it2)
						throw invalid_argument("Senha invalida! Caracter repetido!");

				}
				auxMaiuscula += *it;
			}

		}
		else if (islower(*it)) {
			if (auxMinuscula.empty())
				auxMinuscula += *it;
			else {
				for (string::iterator it2 = auxMinuscula.begin(); it2 != auxMinuscula.end(); it2++) {
					if (*it == *it2)
						throw invalid_argument("Senha invalida! Caracter repetido!");
				}
				auxMinuscula += *it;
			}
		}
		else if (isdigit(*it)) {
			if (auxNumero.empty())
				auxNumero += *it;
			else {
				for (string::iterator it2 = auxNumero.begin(); it2 != auxNumero.end(); it2++) {
					if (*it == *it2)
						throw invalid_argument("Senha invalida! Caracter repetido!");
				}
				auxNumero += *it;
			}
		}
		else
			throw invalid_argument("Senha invalida! Caracter nao permitido presente!");

	}

	if (auxMaiuscula.empty() || auxMinuscula.empty() || auxNumero.empty())
		throw invalid_argument("Senha invalida! Senha precisa conter ao menos uma letra maiuscula, uma miniscula, um numero e um simbolo");

}

void Senha::setSenha(string senha) throw (invalid_argument) {
	validar(senha);
	this->senha = senha;
}
