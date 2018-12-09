#ifndef CADASTROPONTODECOLETA_H_INCLUDED
#define CADASTROPONTODECOLETA_H_INCLUDED
#include <vector>
#include <iostream>
#include <stdio.h>
#include <iterator>
#include "PontoDeColeta.h"
#include "cadastro.h"
#include <algorithm>

using namespace std;

class CadastroPontoDeColeta : Cadastro {

public:

    void create(PontoDeColeta &p);
    void update(PontoDeColeta &p, string _rua, string _bairro, int _numero, string _complemento, string _id);
    void deleted(PontoDeColeta &p);
    void listarPontosDeColeta();
    vector<PontoDeColeta*> listaDePontosDeColeta;

    protected:

    private:

};


#endif // CADASTROPONTODECOLETA_H_INCLUDED
