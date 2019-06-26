#include "testes.h"
#include "dominios.h"
#include "entidades.h"
#include <iostream>
#include <stdlib.h>


// Definições de métodos.

void TUCodigoEvento::setUp(){
    codigo = new CodigoEvento();
    estado = SUCESSO;
}

void TUCodigoEvento::tearDown(){
    delete codigo;
}

void TUCodigoEvento::testarCenarioSucesso(){
    try{
        codigo->setCodigoEvento(VALOR_VALIDO);
        if (codigo->getCodigoEvento() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUCodigoEvento::testarCenarioFalha(){
    try{
        codigo->setCodigoEvento(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUCodigoEvento::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUCodigoApresentacao::setUp(){
    codigo = new CodigoApresentacao();
    estado = SUCESSO;
}

void TUCodigoApresentacao::tearDown(){
    delete codigo;
}

void TUCodigoApresentacao::testarCenarioSucesso(){
    try{
        codigo->setCodigoApresentacao(VALOR_VALIDO);
        if (codigo->getCodigoApresentacao() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUCodigoApresentacao::testarCenarioFalha(){
    try{
        codigo->setCodigoApresentacao(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUCodigoApresentacao::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUCodigoIngresso::setUp(){
    codigo = new CodigoIngresso();
    estado = SUCESSO;
}

void TUCodigoIngresso::tearDown(){
    delete codigo;
}

void TUCodigoIngresso::testarCenarioSucesso(){
    try{
        codigo->setCodigoIngresso(VALOR_VALIDO);
        if (codigo->getCodigoIngresso() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUCodigoIngresso::testarCenarioFalha(){
    try{
        codigo->setCodigoIngresso(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUCodigoIngresso::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUNomeEvento::setUp(){
    nm_evento = new NomeEvento();
    estado = SUCESSO;
}

void TUNomeEvento::tearDown(){
    delete nm_evento;
}

void TUNomeEvento::testarCenarioSucesso(){
    try{
        nm_evento->setNomeEvento(VALOR_VALIDO);
        if (nm_evento->getNomeEvento() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUNomeEvento::testarCenarioFalha(){
    try{
        nm_evento->setNomeEvento(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUNomeEvento::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioSucesso(){
    try{
        data->setData(VALOR_VALIDO);
        if (data->getData() != VALOR_VALIDO)  
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUData::testarCenarioFalha(){
    try{
        data->setData(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUData::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUDataValidade::setUp(){
    dataValidade = new DataValidade();
    estado = SUCESSO;
}

void TUDataValidade::tearDown(){
    delete dataValidade;
}

void TUDataValidade::testarCenarioSucesso(){
    try{
        dataValidade->setDataDeValidade(VALOR_VALIDO);
        if (dataValidade->getDataDeValidade() != (VALOR_VALIDO)) // checar! 
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUDataValidade::testarCenarioFalha(){
    try{
        dataValidade->setDataDeValidade(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUDataValidade::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUEstado::setUp(){
    estadoBr = new Estado();
    estado = SUCESSO;
}

void TUEstado::tearDown(){
    delete estadoBr;
}

void TUEstado::testarCenarioSucesso(){
    try{
        estadoBr->setEstado(VALOR_VALIDO);
        if (estadoBr->getEstado() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUEstado::testarCenarioFalha(){
    try{
        estadoBr->setEstado(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUEstado::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUHorario::setUp(){
    horario = new Horario();
    estado = SUCESSO;
}

void TUHorario::tearDown(){
    delete horario;
}

void TUHorario::testarCenarioSucesso(){
    try{
        horario->setHorario(VALOR_VALIDO);
        if (horario->getHorario() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUHorario::testarCenarioFalha(){
    try{
        horario->setHorario(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUHorario::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUPreco::setUp(){
    preco = new Preco();
    estado = SUCESSO;
}

void TUPreco::tearDown(){
    delete preco;
}

void TUPreco::testarCenarioSucesso(){
    try{
        preco->setPreco(VALOR_VALIDO);
        if (preco->getPreco() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
	try {
		preco->setPreco(VALOR_VALIDO1);
		if (preco->getPreco() != VALOR_VALIDO1)
			estado = FALHA;
	}
	catch (invalid_argument excecao) {
		estado = FALHA;
	}
}

void TUPreco::testarCenarioFalha(){
    try{
        preco->setPreco(VALOR_INVALIDO1);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
   try{
        preco->setPreco(VALOR_INVALIDO2);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUPreco::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUNumeroCartaoCredito::setUp(){
    numeroCartaoCredito = new NumeroCartaoCredito();
    estado = SUCESSO;
}

void TUNumeroCartaoCredito::tearDown(){
    delete numeroCartaoCredito;
}

void TUNumeroCartaoCredito::testarCenarioSucesso(){
    try{
        numeroCartaoCredito->setNumero(VALOR_VALIDO);
        if (numeroCartaoCredito->getNumero() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUNumeroCartaoCredito::testarCenarioFalha(){
    try{
        numeroCartaoCredito->setNumero(VALOR_INVALIDO1);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
 try{
        numeroCartaoCredito->setNumero(VALOR_INVALIDO2);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUNumeroCartaoCredito::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUNumeroSala::setUp(){
    sala = new NumeroSala();
    estado = SUCESSO;
}

void TUNumeroSala::tearDown(){
    delete sala;
}

void TUNumeroSala::testarCenarioSucesso(){
    try{
        sala->setNumero(VALOR_VALIDO);
        if (sala->getNumero() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUNumeroSala::testarCenarioFalha(){
    try{
        sala->setNumero(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUNumeroSala::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try{
        senha->setSenha(VALOR_VALIDO);
        if (senha->getSenha() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha(){
    try{
        senha->setSenha(VALOR_INVALIDO1);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
    }
    try{
        senha->setSenha(VALOR_INVALIDO2);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
    }
    try{
        senha->setSenha(VALOR_INVALIDO3);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
    }
    try{
        senha->setSenha(VALOR_INVALIDO4);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUDisponibilidade::setUp(){
    disponibilidade = new Disponibilidade();
    estado = SUCESSO;
}

void TUDisponibilidade::tearDown(){
    delete disponibilidade;
}

void TUDisponibilidade::testarCenarioSucesso(){
    try{
        disponibilidade->setDisponibilidade(VALOR_VALIDO);
        if (disponibilidade->getDisponibilidade() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUDisponibilidade::testarCenarioFalha(){
    try{
        disponibilidade->setDisponibilidade(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUDisponibilidade::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUClasseEvento::setUp(){
    classe = new ClasseEvento();
    estado = SUCESSO;
}

void TUClasseEvento::tearDown(){
    delete classe;
}

void TUClasseEvento::testarCenarioSucesso(){
    try{
        classe->setClasseEvento(VALOR_VALIDO);
        if (classe->getClasseEvento() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument excecao){
        estado = FALHA;
    }
}

void TUClasseEvento::testarCenarioFalha(){
    try{
        classe->setClasseEvento(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument excecao){
        return;
    }
}

int TUClasseEvento::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUFaixaEtaria::setUp() {
	faixa = new FaixaEtaria();
	estado = SUCESSO;
}

void TUFaixaEtaria::tearDown() {
	delete faixa;
}

void TUFaixaEtaria::testarCenarioSucesso() {
	try {
		faixa->setFaixaEtaria(VALOR_VALIDO);
		if (faixa->getFaixaEtaria() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch (invalid_argument excecao) {
		estado = FALHA;
	}
}

void TUFaixaEtaria::testarCenarioFalha() {
	try {
		faixa->setFaixaEtaria(VALOR_INVALIDO);
		estado = FALHA;
	}
	catch (invalid_argument excecao) {
		return;
	}
}

int TUFaixaEtaria::run() {
	setUp();
	testarCenarioSucesso();
	testarCenarioFalha();
	tearDown();
	return estado;
}

void TUCPF::setUp() {
	cpf = new CPF();
	estado = SUCESSO;
}

void TUCPF::tearDown() {
	delete cpf;
}

void TUCPF::testarCenarioSucesso() {
	try {
		cpf->setCPF(VALOR_VALIDO);
		if (cpf->getCPF() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch (invalid_argument excecao) {
		estado = FALHA;
	}
}

void TUCPF::testarCenarioFalha() {
	try {
		cpf->setCPF(VALOR_INVALIDO);
		estado = FALHA;
	}
	catch (invalid_argument excecao) {
	}
	try {
		cpf->setCPF(VALOR_INVALIDO2);
		estado = FALHA;
	}
	catch (invalid_argument excecao) {
		return;
	}
}

int TUCPF::run() {
	setUp();
	testarCenarioSucesso();
	testarCenarioFalha();
	tearDown();
	return estado;
}

void TUCidade::setUp() {
	cidade = new Cidade();
	estado = SUCESSO;
}

void TUCidade::tearDown() {
	delete cidade;
}

void TUCidade::testarCenarioSucesso() {
	try {
		cidade->setCidade(VALOR_VALIDO);
		if (cidade->getCidade() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch (invalid_argument excecao) {
		estado = FALHA;
	}
}

void TUCidade::testarCenarioFalha() {
	try {
		cidade->setCidade(VALOR_INVALIDO);
		estado = FALHA;
	}
	catch (invalid_argument excecao) {
		return;
	}
}

int TUCidade::run() {
	setUp();
	testarCenarioSucesso();
	testarCenarioFalha();
	tearDown();
	return estado;
}

void TUCodigoSeguranca::setUp() {
	codigo = new CodigoSeguranca();
	estado = SUCESSO;
}

void TUCodigoSeguranca::tearDown() {
	delete codigo;
}

void TUCodigoSeguranca::testarCenarioSucesso() {
	try {
		codigo->setCodigoSeguranca(VALOR_VALIDO);
		if (codigo->getCodigoSeguranca() != VALOR_VALIDO)
			estado = FALHA;
	}
	catch (invalid_argument excecao) {
		estado = FALHA;
	}
}

void TUCodigoSeguranca::testarCenarioFalha() {
	try {
		codigo->setCodigoSeguranca(VALOR_INVALIDO);
		estado = FALHA;
	}
	catch (invalid_argument excecao) {
		return;
	}
}

int TUCodigoSeguranca::run() {
	setUp();
	testarCenarioSucesso();
	testarCenarioFalha();
	tearDown();
	return estado;
}