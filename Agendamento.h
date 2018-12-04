#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H
#include "pessoa.h"
#include "PontoDeColeta.h"
#include <string>

using namespace std;

class Agendamento {
    /*** Agendamento ***/

    public:
        Agendamento(string _data, PontoDeColeta &_local, Pessoa &_doador, Pessoa &_receptor, string _residuos);

        void setData(string _data);
        void setLocal(PontoDeColeta &_local);
        void setDoador(Pessoa &_doador);
        void setReceptor(Pessoa &_receptor);
        void setResiduos(string _residuos);

        string getData();
        PontoDeColeta getLocal();
        Pessoa getDoador();
        Pessoa getReceptor();
        string getResiduos();

    private:
        string data;
        PontoDeColeta *local;
        Pessoa *doador;
        Pessoa *receptor;
        string residuos;

};

#endif
