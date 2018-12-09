#ifndef PONTODECOLETA_H_INCLUDED
#define PONTODECOLETA_H_INCLUDED
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class PontoDeColeta
{
    public:
        PontoDeColeta( string _rua, string _bairro, int _numero, string _complemento, string _id);
        string getRua();
        string getBairro();
        int getNumero();
        string getComplemento();
        string getId();

    void setRua(string _rua);
    void setBairro(string _bairro);
    void setNumero(int _numero);
    void setComplemento(string _complemento);
    void setId(string _id);

    protected:

    private:
        string rua;
        string bairro;
        int numero;
        string complemento;
        string id;

};

#endif // PONTODECOLETA_H_INCLUDED
