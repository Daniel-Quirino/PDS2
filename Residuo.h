#ifndef RESIDUO_H_INCLUDED
#define RESIDUO_H_INCLUDED
#include <string>

using namespace std;

class Residuo
{
    public:
        Residuo(bool _solido, string _material, string _descricao);

        void setSolido(bool _solido);
        void setMateria(string _material);
        void setDescricao(string _descricao);

        bool getSolido();
        string getMaterial();
        string getDescricao();

    protected:

    private:
        bool solido;
        string material;
        string descricao;
};

#endif // RESIDUO_H_INCLUDED
