#include "Residuo.h"
#include <vector>
#include "cadastroResiduo.h"


using namespace std;


void cadastroResiduo::create(Residuo &r){
    listaDeResiduos.push_back(&r);
}//void

void cadastroResiduo::daleted(Residuo &r){

    if(find(listaDeResiduos.begin(), listaDeResiduos.end(), &r) != listaDeResiduos.end()){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); it++){
            if((*it)->getMaterial() == r.getMaterial()){
                delete *it;///libera a memoria alocada
                listaDeResiduos.erase(it);
                break;
            }//if
        }//for
    }//if
    else{
        cout<<"Residuo não cadastrado"<<endl;
    }
}//void
void cadastroResiduo::listaDeResiduo(){
    vector<Residuo*>::iterator it;
    for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {

        cout<< (*it)->getMaterial() <<endl;
    }//for
}//void

void cadastroResiduo::update(Residuo &r, string _descricao){
    if (find(listaDeResiduos.begin(), listaDeResiduos.end(), &r) != listaDeResiduos.end()){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {
            if((*it)->getMaterial() == r.getMaterial()){
                (*it)->setDescricao(_descricao);
            }//if
        }//for
    }//if
}//void

cadastroResiduo::cadastroResidou(){
    /*** cria um pré cadastro de materiais ***/
    Residuo *a= new Residuo(true, "papel","Guardar em local seco, sem amassar.");
    Residuo *b= new Residuo(true,"Vidro","O vidro nao deve ser descartado sem uma protecao adequada");
    Residuo *c= new Residuo(true, "Latas de refrigerante","Amassadas paar ocupar um volume menor.");
    Residuo *d= new Residuo(false,"Oleo","Em garrafas PET fechadas, para não vazar");
    Residuo *e= new Residuo(false,"tintas","Na propria embalagem original");
    create(*a);
    create(*b);
    create(*c);
    create(*d);
    create(*e);
}//construto
cadastroResiduo::~cadastroResidou(){
    vector<Residuo*>::iterator it;
        for(it= listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {
            delete *it;///libera a memoria alocada
        }//for
    listaDeResiduos.clear();
}//destrutor
string cadastroResidou::getDescricao(string _material){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); it++){
            if((*it)->getMaterial() == _material){
                return (*it)->getDescricao();
            }//if
        }//for
}///string
