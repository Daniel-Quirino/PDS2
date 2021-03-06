#ifndef PESSOA_H
#define PESSOA_H
#include <string>
#include <iostream>


using namespace std;

class Pessoa
{
    public:
        Pessoa(string _nome, string _endereco, string _dataDeNascimento, bool _isPessoaFisica, bool _isDoador, string _cpfCnpj);
        //virtual ~pessoa();

        void setNome(string _nome);
        void setEndereco(string _endereco);
        void setDataDeNascimento(string _dataDeNascimento);
        void setIsPessoaFisica(bool _isPessoaFisica);
        void setIsDoador(bool _isDoador);
        void setCpfCnpj(string _cpfCnpj);
        string getNome();
        string getEndereco();
        string getDataDeNascimento();
        bool getIsPessoaFisica();
        bool getIsDoador();
        string getCpfCnpj();
        void validarCpfCnpj(bool _isPessoaFisica, string _cpfCnpj, string _nome);
        void verficarData(string _dataDeNascimento, string _nome);

    protected:

    private:
        string nome;
        string endereco;
        string dataDeNascimento;
        bool isPessoaFisica;
        bool isDoador;
        string cpfCnpj;
};

#endif // PESSOA_H
