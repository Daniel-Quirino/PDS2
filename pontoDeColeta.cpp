#include "pontoDeColeta.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

PontoDeColeta::PontoDeColeta( string _rua, string _bairro, int _numero, string _complemento, string _id){
    rua = _rua;
    bairro = _bairro;
    numero = _numero;
    complemento = _complemento;
    id = _id;
};

string PontoDeColeta::getRua(){return rua;}
string PontoDeColeta::getBairro(){return bairro;}
int PontoDeColeta::getNumero(){return numero;}
string PontoDeColeta::getComplemento(){return complemento;}
string PontoDeColeta::getId(){return id;}

void PontoDeColeta::setRua(string _rua) { rua = _rua;}
void PontoDeColeta::setBairro(string _bairro) { bairro = _bairro;}
void PontoDeColeta::setNumero(int _numero) { numero = _numero;}
void PontoDeColeta::setComplemento(string _complemento) { complemento = _complemento;}
void PontoDeColeta::setId(string _id) { id = _id;}
