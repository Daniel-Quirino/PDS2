#include "Ranking.h"
#include "Agendamento.h"
#include "pessoa.h"
#include "CadastroAgendamento.h"
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
///https://thispointer.com/how-to-sort-a-map-by-value-in-c/
using namespace std;
void Ranking::insereDoador(Pessoa p){
    map<string,int>::iterator it;
    it = rankingDeDoar.find(p.getNome());
    if(it == rankingDeDoar.end()){
          rankingDeDoar.insert(pair<string,int>(p.getNome(),1));
    }else{
        it->second ++;
    }
}//void
void Ranking::insereReceptor(Pessoa p){
    map<string,int>::iterator it;
    it = rankingDeReceptor.find(p.getNome());
    if(it == rankingDeReceptor.end()){
          rankingDeReceptor.insert(pair<string,int>(p.getNome(),1));
    }else{
        it->second ++;
    }
}//void
void Ranking::rankingDoar(CadastroAgendamento &cad){
    int tamanho = cad.listaDeAgendamentos.size();
    for(int i = 0 ; i<tamanho; i++){
        insereDoador(cad.listaDeAgendamentos.at(i)->getDoador());
    }
}//void
void Ranking::rankingReceptor(CadastroAgendamento &cad){
    int tamanho = cad.listaDeAgendamentos.size();
    for(int i = 0 ; i<tamanho; i++){
        insereReceptor(cad.listaDeAgendamentos.at(i)->getReceptor());
    }
}
Ranking::Ranking(CadastroAgendamento *cad){
    rankingDoar(*cad);
    rankingReceptor(*cad);
    ordena();
}
void Ranking::ordena(){
    map<string,int> ::iterator it;
    for(it = rankingDeDoar.begin(); it != rankingDeDoar.end() ; ++it){
        doador.push_back(it->first);
        _doador.push_back(it->second);
    }///for
    for(it = rankingDeReceptor.begin(); it!=rankingDeReceptor.end(); ++it){
        receptor.push_back(it->first);
        _receptor.push_back(it->second);
    }///for

    ///faço um bolha sort por ser mais facil msm
    unsigned int k,i,j;
    string a;
     for (k = 1; k < _doador.size(); k++) {
        for (j = 0; j < _doador.size() - 1; j++) {
            if (_doador.at(j) > _doador.at(j+1)) {
                i = _doador.at(j);
                _doador.at(j)     = _doador.at(j+1);
                _doador.at(j+1)= i;

                a=doador.at(j);
                doador.at(j)=doador.at(j+1);
                doador.at(j+1)=a;
            }//if
        }//for
    }//for
    for (k = 1; k < _receptor.size(); k++) {
        for (j = 0; j <_receptor.size() - 1; j++) {
            if (_receptor.at(j) > _receptor.at(j+1)) {
                i = _receptor.at(j);
                _receptor.at(j)     = _receptor.at(j+1);
                _receptor.at(j+1)= i;

                a=receptor.at(j);
                receptor.at(j)=receptor.at(j+1);
                receptor.at(j+1)=a;
            }//if
        }//for
    }//for
}///void
void Ranking::maiorDoadorImprime(){
    unsigned int a = doador.size() - 1;
    cout<<"Maior doador:"<<doador.at(a)<< " com "<<_doador.at(a)<<" doacoes agendadas"<<endl;
}
void Ranking::maiorReceptorImprime(){
    unsigned int a = receptor.size() - 1;
    cout<<"Maior receptor:"<<receptor.at(a)<< " com "<<_receptor.at(a)<<" recebimentos agendadas"<<endl;
}
void Ranking::rankingDoarLista(){
    int j = 1;
    for(unsigned int i = doador.size(); i>0;--i,j++){
        cout<<"Doador: "<<"#"<<j<<" "<<doador.at(i-1)<< " com "<<_doador.at(i-1)<<" doacoes agendadas"<<endl;
    }//for
}//void
void Ranking::rankingReceptorLista(){
    int j = 1;
    for(unsigned int i = receptor.size(); i>0;--i,j++){
        cout<<"Receptor : "<<"#"<<j<<" "<<receptor.at(i-1)<< " com "<<_receptor.at(i-1)<<" recebimento agendadas"<<endl;
    }//for
}
