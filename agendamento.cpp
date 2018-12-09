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
    verficarData(_data, _id);
}

void Agendamento::setData(string _data) {
     verficarData(_data, id);
    data = _data;}
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

void Agendamento:: verficarData(string _data, string _nome){
    string data = _data;
    string mensagemErroData = "Erro: Data de " + _nome + " invalida.";

    if(data.size() == 10 && ((data[2] == '/' && data[5] == '/') || (data[2] == '-' && data[5] == '-')))
        {
            string delimiter = "/";
            string dia = data.substr(0, 2);
            string mes = data.substr(3, 2);
            string ano = data.substr(6, 4);

            int _dia = atoi(dia.c_str());
            int _mes = atoi(mes.c_str());
            int _ano = atoi(ano.c_str());

            if(_ano < 1900 || _ano > 2030 || _mes < 1 || _mes > 12 || _dia > 31 || _dia < 1)
                throw mensagemErroData;
            else if(_dia > 28 && _mes == 2)
                throw mensagemErroData;
            else if(_dia > 30 && (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11))
                throw mensagemErroData;
        }
        else
            throw mensagemErroData;
}
