#ifndef CADASTROPESSOA_H_INCLUDED
#define CADASTROPESSOA_H_INCLUDED
#include <vector>
#include <iostream>
#include <stdio.h>
#include <iterator>
#include "pessoa.h"
#include "cadastro.h"
#include <algorithm>

using namespace std;

class CadastroPessoa : Cadastro {

public:
    CadastroPessoa(){}

    void create(Pessoa &p);
    void update(Pessoa &p, string _nome, string _endereco, string _dataDeNascimento, bool _isDoador);
    void deleted(Pessoa &p);
    void listarUsuarios();
    vector<Pessoa*> listaDeUsuarios;

    protected:

    private:

};

#endif // CADASTROPESSOA_H_INCLUDED
