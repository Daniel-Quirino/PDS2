#include "cadastroPessoa.h"
#include "pessoa.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void CadastroPessoa::create(Pessoa &p){
    if (find(listaDeUsuarios.begin(), listaDeUsuarios.end(), &p) == listaDeUsuarios.end()){
        listaDeUsuarios.push_back(&p);
    } else {
        cout << "Usuario: "+ p.getNome() + " ja Cadastrado" << endl;
    }
}

void CadastroPessoa::deleted(Pessoa &p) {
    if (find(listaDeUsuarios.begin(), listaDeUsuarios.end(), &p) != listaDeUsuarios.end()){

        vector<Pessoa*>::iterator itV;
        for(itV = listaDeUsuarios.begin(); itV != listaDeUsuarios.end(); ++itV) {
            if ((*itV)->getCpfCnpj() == p.getCpfCnpj()){
                listaDeUsuarios.erase(itV);
            }

        }
    } else {
        cout << "Usuario: " +p.getNome() + " nao Cadastrado" << endl;
    }
}

void CadastroPessoa::listarUsuarios() {
    vector<Pessoa*> :: iterator itV;
    for(itV = listaDeUsuarios.begin(); itV != listaDeUsuarios.end(); ++itV) {

        cout<< (*itV)->getNome() <<endl;
    }

}

void CadastroPessoa::update(Pessoa &p, string _nome, string _endereco, string _dataDeNascimento, bool _isDoador) {
    if (find(listaDeUsuarios.begin(), listaDeUsuarios.end(), &p) != listaDeUsuarios.end()){

        p.verficarData(_dataDeNascimento, _nome);

        vector<Pessoa*>::iterator itV;
        for(itV = listaDeUsuarios.begin(); itV != listaDeUsuarios.end(); ++itV) {
            if ((*itV)->getCpfCnpj() == p.getCpfCnpj()){
                (*itV)->setNome(_nome);
                (*itV)->setEndereco(_endereco);
                (*itV)->setDataDeNascimento(_dataDeNascimento);
                (*itV)->setIsDoador(_isDoador);
            }
        }
    } else {
        cout << "Usuario: " +p.getNome() + " nao Cadastrado" << endl;
    }
}
