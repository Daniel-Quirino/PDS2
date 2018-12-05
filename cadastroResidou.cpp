
#include "Residuo.h"
#include <vector>
#include "cadastroResidou.h"


using namespace std;

void cadastroResidou::create(Residuo &r){
    listaDeResiduos.push_back(&r);
}//void

void cadastroResidou::daleted(Residuo &r){
    if(find(listaDeResiduos.begin(), listaDeResiduos().end(), &r) != listaDeResiduos.end()){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); it++){
            if((*it)->getMaterial() == r.getMaterial()){
                listaDeResiduos.erase(it);
            }//if
        }//for
    }//if
    else{
        cout<<"Residou não cadastrado"<<endl;
    }
}//void
void cadastroResidou::listaDeResiduo(){
    vector<Residuo*>::iterator it;
    for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {

        cout<< (*it)->getMaterial() <<endl;
    }//for
}//void

void cadastroResidou::update(Residuo &r, string _descricao){
    if (find(listaDeResiduos.begin(), listaDeResiduos.end(), &r) != listaDeResiduos.end()){
        vector<Residuo*>::iterator it;
        for(it = listaDeResiduos.begin(); it != listaDeResiduos.end(); ++it) {
            if((*it)->getMaterial() == r.getMaterial()){
                (*it)->setDescricaos(_descricao);
            }//if
        }//for
    }//if
}//void

cadastroResidou::cadastroResidou(){
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
}//construtor*?
