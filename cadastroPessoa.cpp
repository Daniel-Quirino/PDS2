#include "cadastroPessoa.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void CadastroPessoa::create(Pessoa &p){
    listaDeUsuarios.push_back(&p);
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
        cout << "Usuário nao Cadastrado" << endl;
    }
}

void CadastroPessoa::listarUsuarios() {
    vector<Pessoa*> :: iterator itV;
    for(itV = listaDeUsuarios.begin(); itV != listaDeUsuarios.end(); ++itV) {

        cout<< (*itV)->getNome() <<endl;
    }

}

void CadastroPessoa::update(Pessoa &p, string _nome, string _endereco, string _dataDeNascimento, bool _isPessoaFisica, bool _isDoador, double _cpfCnpj) {
    if (find(listaDeUsuarios.begin(), listaDeUsuarios.end(), &p) != listaDeUsuarios.end()){
        
        verficarData(_dataDeNascimento);
        validarCpfCnpj(_isPessoaFisica, _cpfCnpj);

        vector<Pessoa*>::iterator itV;
        for(itV = listaDeUsuarios.begin(); itV != listaDeUsuarios.end(); ++itV) {
            if ((*itV)->getCpfCnpj() == p.getCpfCnpj()){
                (*itV)->setNome(_nome);
                (*itV)->setEndereco(_endereco);
                (*itV)->setDataDeNascimento(_dataDeNascimento);
                (*itV)->setCpfCnpj(_cpfCnpj);
                (*itV)->setIsPessoaFisica(_isPessoaFisica);
                (*itV)->setIsDoador(_isDoador);
            }
        }
    }
}
