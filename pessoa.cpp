#include "pessoa.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

Pessoa::Pessoa(string _nome, string _endereco, string _dataDeNascimento, bool _isPessoaFisica, bool _isDoador, string _cpfCnpj){
    validarCpfCnpj(_isPessoaFisica, _cpfCnpj, _nome);
    verficarData(_dataDeNascimento, _nome);
    endereco = _endereco;
    dataDeNascimento = _dataDeNascimento;
    isPessoaFisica = _isPessoaFisica;
    isDoador = _isDoador;
    cpfCnpj = _cpfCnpj;
    nome = _nome;

}

void Pessoa::setNome(string _nome) { nome = _nome;}

void Pessoa::setEndereco(string _endereco) { endereco = _endereco;}

void Pessoa::setDataDeNascimento(string _dataDeNascimento) { dataDeNascimento = _dataDeNascimento;}

void Pessoa::setIsPessoaFisica(bool _isPessoaFisica) { isPessoaFisica = _isPessoaFisica;}

void Pessoa::setIsDoador(bool _isDoador) { isDoador = _isDoador;}

void Pessoa::setCpfCnpj(string _cpfCnpj) { cpfCnpj = _cpfCnpj;}

string Pessoa::getNome(){return nome;}

string Pessoa::getEndereco(){return endereco;}

string Pessoa::getDataDeNascimento(){return dataDeNascimento;}

bool Pessoa::getIsPessoaFisica(){return isPessoaFisica;}

bool Pessoa::getIsDoador(){return isDoador;}

string Pessoa::getCpfCnpj(){return cpfCnpj;}

void Pessoa::validarCpfCnpj(bool _isPessoaFisica, string _cpfCnpj, string _nome)
{
    if(_isPessoaFisica)
        {
            string cpf = _cpfCnpj;
            string mensagemErroCpf = "Erro: Cpf de " + _nome + " invalido.";

            if (cpf.size() != 11)
                throw mensagemErroCpf;

            int i, numero, resultado, soma = 0, base = 10;
            int digito1, digito2;
            string str_numero, str_nono, str_decimo;

            for (i = 0; i <= 8; i++)
            {
                str_numero = cpf[i];
                numero = atoi(str_numero.c_str());
                soma+= (numero * base);
                base--;
            }

            resultado = (soma % 11);

            if (resultado < 2)
            {
                digito1 = 0;
            }
            else
            {
                digito1 = (11 - resultado);
            }

            soma = (digito1 * 2);
            base = 11;

            for (i = 0; i <= 8; i++)
            {
                str_numero = cpf[i];
                numero = atoi(str_numero.c_str());
                soma+= (numero * base);
                base--;
            }

            resultado = (soma % 11);

            if (resultado < 2)
            {
                digito2 = 0;
            }
            else
            {
                digito2 = (11 - resultado);
            }

            str_nono = cpf[9];
            str_decimo = cpf[10];

            if (atoi(str_nono.c_str()) != digito1 ||
                atoi(str_decimo.c_str()) != digito2)
                throw mensagemErroCpf;
        }
        else
        {
            string cnpj = _cpfCnpj;
            string mensagemErroCnpj = "Erro: Cnpj de " + _nome + " invalido.";

            if (cnpj.size() != 14)
                throw mensagemErroCnpj;

            int i, numero, resultado, soma = 0, base = 5;
            int digito1, digito2;
            std::string str_numero, str_treze, str_catorze;

            for (i = 0; i <= 11; i++)
            {
                str_numero = cnpj[i];
                numero = atoi(str_numero.c_str());
                soma+= (numero * base);
                base--;

                if (base < 2)
                    base = 9;
            }

            resultado = (soma % 11);

            if (resultado < 2)
                digito1 = 0;
            else
                digito1 = (11 - resultado);

            soma = (digito1 * 2);
            base = 6;

            for (i= 0; i <= 11; i++)
            {
                str_numero = cnpj[i];
                numero = atoi(str_numero.c_str());
                soma+= (numero * base);
                base--;

                if (base < 2)
                    base = 9;
            }

            resultado= (soma % 11);

            if (resultado < 2)
                digito2 = 0;
            else
                digito2 = (11 - resultado);

            str_treze = cnpj[12];
            str_catorze = cnpj[13];

            if (atoi(str_treze.c_str()) != digito1 ||
                atoi(str_catorze.c_str()) != digito2)
                throw mensagemErroCnpj;
        }
}

void Pessoa::verficarData(string _data, string _nome)
{
    string data = _data;
    string mensagemErroData = "Erro: Data de nascimento de " + _nome + " invalida.";

    if(data.size() == 10 && ((data[2] == '/' && data[5] == '/') || (data[2] == '-' && data[5] == '-')))
        {
            string delimiter = "/";
            string dia = data.substr(0, 2);
            string mes = data.substr(3, 2);
            string ano = data.substr(6, 4);

            int _dia = atoi(dia.c_str());
            int _mes = atoi(mes.c_str());
            int _ano = atoi(ano.c_str());

            if(_ano < 1900 || _ano > 2018 || _mes < 1 || _mes > 12 || _dia > 31 || _dia < 1)
                throw mensagemErroData;
            else if(_dia > 28 && _mes == 2)
                throw mensagemErroData;
            else if(_dia > 30 && (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11))
                throw mensagemErroData;
        }
        else
            throw mensagemErroData;
}

