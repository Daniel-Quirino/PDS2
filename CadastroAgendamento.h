#ifndef CADASTROAGENDAMENTO_H_INCLUDED
#define CADASTROAGENDAMENTO_H_INCLUDED
#include <vector>
#include <iostream>
#include <stdio.h>
#include <iterator>
#include "pessoa.h"
#include "cadastro.h"
#include <algorithm>
#include "Agendamento.h"

using namespace std;

class CadastroAgendamento : Cadastro {

public:
    CadastroAgendamento(){}

    void create(Agendamento &p);
    void update(Agendamento &p, string _data, PontoDeColeta &_local, Pessoa &_doador, Pessoa &_receptor, string _residuos, string _id);
    void deleted(Agendamento &p);
    void listarAgendamentos();
    vector<Agendamento*> listaDeAgendamentos;


    protected:

    private:

};



#endif // CADASTROAGENDAMENTO_H_INCLUDED
