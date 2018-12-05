#ifndef CADATRORESIDOU_H_INCLUDED
#define CADATRORESIDOU_H_INCLUDED
#include "Residuo.h"

#include <vector>
using namespace std;

class cadastroResidou{
    public:

/*** asemelho a classe cadastropessoas ***/
        cadastroResidou();
        ~cadastroResidou();
        void create(Residuo &r);
        void update(Residuo &r, string _descricao);
        void daleted(Residuo &r);
        void listaDeResiduo();
        vector<Residuo*> listaDeResiduos;

    protected:
    private:
};



#endif // CADATRORESIDOU_H_INCLUDED
