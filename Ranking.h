#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED
#include "pessoa.h"
#include "Agendamento.h"
#include "CadastroAgendamento.h"
#include <vector>
#include <map>

using namespace std;
class Ranking{
public:
    Ranking(CadastroAgendamento *cad);///construtor
    void maiorDoadorImprime();
    void maiorReceptorImprime();
    void rankingDoarLista();
    void rankingReceptorLista();
protected:
    void insereDoador(Pessoa p);
    void insereReceptor(Pessoa p);
    void rankingDoar(CadastroAgendamento &cad);
    void rankingReceptor(CadastroAgendamento &cad);
    void ordena();

    map<string,int> rankingDeDoar;
    map<string,int> rankingDeReceptor;
    vector<string> doador;
    vector<int> _doador;
    vector<string> receptor;
    vector<int> _receptor;
    private:
};


#endif // RANKING_H_INCLUDED
