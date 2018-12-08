#include "Agendamento.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

Agendamento::Agendamento(string _data, PontoDeColeta &_local, Pessoa &_doador, Pessoa &_receptor, Residuo &_residuos, string _id) {
    data = _data;
    local = &_local;
    doador = &_doador;
    receptor = &_receptor;
    residuos = &_residuos;
    id = _id;
}

void Agendamento::setData(string _data) { data = _data;}
void Agendamento::setLocal(PontoDeColeta &_local) { local = &_local;}
void Agendamento::setDoador(Pessoa &_doador) { doador = &_doador;}
void Agendamento::setReceptor(Pessoa &_receptor) { receptor = &_receptor;}
void Agendamento::setResiduos(Residuo &_residuos) { residuos = &_residuos;}
void Agendamento::setId(string _id) { id = _id;}


string Agendamento::getData(){return data;}
PontoDeColeta Agendamento::getLocal(){return *local;}
Pessoa Agendamento::getDoador(){return *doador;}
Pessoa Agendamento::getReceptor(){return *receptor;}
Residuo Agendamento::getResiduos(){return *residuos;}
string Agendamento::getId(){return id;}
