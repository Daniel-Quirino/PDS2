#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "CadastroPontoDeColeta.h"
#include "PontoDeColeta.h"

using namespace std;

void CadastroPontoDeColeta::create(PontoDeColeta &p){
    listaDePontosDeColeta.push_back(&p);
}

void CadastroPontoDeColeta::deleted(PontoDeColeta &p) {
    if (find(listaDePontosDeColeta.begin(), listaDePontosDeColeta.end(), &p) != listaDePontosDeColeta.end()){

        vector<PontoDeColeta*>::iterator itV;
        for(itV = listaDePontosDeColeta.begin(); itV != listaDePontosDeColeta.end(); ++itV) {
            if ((*itV)->getId() == p.getId()){
                listaDePontosDeColeta.erase(itV);
            }

        }
    } else {
        cout << "Ponto de Coleta nao Cadastrado" << endl;
    }
}

void CadastroPontoDeColeta::listarPontosDeColeta() {
    vector<PontoDeColeta*> :: iterator itV;
    for(itV = listaDePontosDeColeta.begin(); itV != listaDePontosDeColeta.end(); ++itV) {

        cout<< (*itV)->getRua() << " - " << (*itV)->getNumero() << " - "<< (*itV)->getComplemento() << endl;
    }

}

void CadastroPontoDeColeta::update(PontoDeColeta &p, string _rua, string _bairro, int _numero, string _complemento, string _id) {
    if (find(listaDePontosDeColeta.begin(), listaDePontosDeColeta.end(), &p) != listaDePontosDeColeta.end()){

        vector<PontoDeColeta*>::iterator itV;
        for(itV = listaDePontosDeColeta.begin(); itV != listaDePontosDeColeta.end(); ++itV) {
            if ((*itV)->getId() == p.getId()){
                (*itV)->setRua(_rua);
                (*itV)->setBairro(_bairro);
                (*itV)->setNumero(_numero);
                (*itV)->setComplemento(_complemento);
            }
        }
    }
}
