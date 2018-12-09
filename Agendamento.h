#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H
#include "pessoa.h"
#include "PontoDeColeta.h"
#include "Residuo.h"

#include <string>

using namespace std;

class Agendamento {
    /*** Agendamento ***/

    public:
        Agendamento(string _data, PontoDeColeta &_local, Pessoa &_doador, Pessoa &_receptor, Residuo &_residuos, string _id);

        void setData(string _data);
        void setLocal(PontoDeColeta &_local);
        void setDoador(Pessoa &_doador);
        void setReceptor(Pessoa &_receptor);
        void setResiduos(Residuo &_residuos);
        void setId(string _id);
        void verficarData(string _data, string _nome);

        string getData();
        PontoDeColeta getLocal();
        Pessoa getDoador();
        Pessoa getReceptor();
        Residuo getResiduos();
        string getId();

    private:
        string data;
        PontoDeColeta *local;
        Pessoa *doador;
        Pessoa *receptor;
        Residuo *residuos;
        string id;

};

#endif
