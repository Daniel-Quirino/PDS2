#ifndef CADATRORESIDOU_H_INCLUDED
#define CADATRORESIDOU_H_INCLUDED
#include "Residuo.h"
#include <vector>


using namespace std;

class cadastroResiduo{
    public:
        ~cadastroResiduo();
        void create(Residuo &r);
        void update(Residuo &r, string _descricao);
        void daleted(Residuo &r);
        void listaDeResiduo();
        string getDescricao(string _material);
        vector<Residuo*> listaDeResiduos;

    protected:
    private:
};
#endif // CADATRORESIDOU_H_INCLUDED
