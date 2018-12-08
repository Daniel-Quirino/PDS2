#include <stdio.h>
#include <time.h>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>
#include "Agendamento.h"
#include "pessoa.h"
#include "pessoa.cpp"
#include "cadastro.h"
#include "cadastroPessoa.h"
#include "cadastroPessoa.cpp"
#include "PontoDeColeta.h"
#include "pontoDeColeta.cpp"
#include "Agendamento.h"
#include "agendamento.cpp"
#include "CadastroAgendamento.h"
#include "cadastroAgendamento.cpp"
#include "Residuo.h"
#include "residuo.cpp"
#include "cadastroResiduo.h"
#include "cadastroResiduo.cpp"
//#include "Ranking.h"
//#include "Ranking.cpp"

using namespace std;

int main() {

    try
    {
        //Criando objetos Pessoas
        Pessoa *p1 = new Pessoa("Daniel Quirino", "Rua João Fernandes", "11/11/1997", true, true , "13494658609");
        Pessoa *p2 = new Pessoa("Filipe Lauar", "Avenida Miguel Perrela", "20/02/1996", true, false , "36559173097");
        Pessoa *p3 = new Pessoa("Pedro Vieira", "Rua Fernando de Albuquerque", "08/09/1994", false, false , "68884897000105");
        Pessoa *p4 = new Pessoa("Lucas Mello ", "Rua Boaventura", "16/04/1993", true, true , "56493783046");
        Pessoa *p5 = new Pessoa("Augusto da Silva ", "Rua Paramarinbo", "11/03/1969", false, true , "64330859000141");

        //Cadastrando as Pessoas
        CadastroPessoa *cp = new CadastroPessoa();
        cp->create(*p1);
        cp->create(*p2);
        cp->create(*p3);
        cp->create(*p4);
        cp->create(*p5);

        //CRUD de pessoas
        cout << "-------------- Listar as pessoas cadastradas: -------------" << endl;
        cp->listarUsuarios();
        cout << endl << endl;

        cp->deleted(*p2);
        cp->deleted(*p4);
        cp->update(*p1, "Daniel Pires", "Rua João Fernandes 107", "10/05/1997", false);

        cout << "-------- Lista atualizada de pessoas cadastradas: --------" << endl;
        cp->listarUsuarios();
        cout << endl << endl;




        //Criando Objetos do tipo Ponto de Coleta
        PontoDeColeta *pontCol = new PontoDeColeta("Rua Alameda dos Anjos", "Liberdade", 129, "apt 107");
        PontoDeColeta *pontCol2 = new PontoDeColeta("Praca da Savassi", "Savassi", 10, "Perto do BK");
        PontoDeColeta *pontCol3 = new PontoDeColeta("Augusto de Lima", "Centro", 160, "Em frente ao Maleta");

        //Criando Objetos do tipo Residuo
        Residuo *a= new Residuo(true, "papel","Guardar em local seco, sem amassar.");
        Residuo *b= new Residuo(true,"Vidro","O vidro nao deve ser descartado sem uma protecao adequada");
        Residuo *c= new Residuo(true, "Latas de refrigerante","Amassadas paar ocupar um volume menor.");
        Residuo *d= new Residuo(false,"Oleo","Em garrafas PET fechadas, para não vazar");
        Residuo *e= new Residuo(false,"tintas","Na propria embalagem original");

        //Cadastrando os resíduos
        cadastroResiduo *cadres= new cadastroResiduo();
        cadres->create(*a);
        cadres->create(*b);
        cadres->create(*c);
        cadres->create(*d);
        cadres->create(*e);

        //CRUD com os resíduos
        cadres->daleted(*e);
        cadres->update(*b, "O vidro deve ser descartado coberto com papel");

        cout << "-------- Lista de residuos cadastrados: --------" << endl;
        cadres->listaDeResiduo();
        cout << endl << endl;



        //Criando Objjetos de Agendamentos
        Agendamento *ag1 = new Agendamento("18/12/2018", *pontCol, *p1, *p3, *a, "1");
        Agendamento *ag2 = new Agendamento("30/06/2019", *pontCol2, *p4, *p5, *b, "2");
        Agendamento *ag3 = new Agendamento("14/02/2019", *pontCol3, *p1, *p5, *c, "3");

        //Cadastrando os Agendamentos
        CadastroAgendamento *cadAgen = new CadastroAgendamento();
        cadAgen->create(*ag1);
        cadAgen->create(*ag2);
        cadAgen->create(*ag3);

        //CRUD com os agendamentos
        cadAgen->deleted(*ag2);
        cadAgen->update(*ag1, "20/12/2018", *pontCol, *p1, *p3, *d, "1");

        cout << "----------------- Lista de Agendamentos: -----------------" << endl;
        cadAgen->listarAgendamentos();
        cout << endl << endl;



        /*
        Residuo *res = new Residuo(true, "Organico", "Deve estar guardado em sacos pretos");
        cadres->create(*res);
        cout<<cadres->getDescricao("Organico")<<endl;
        cadres->update(*res,"Deve estar em sacos claros");
        cout<<cadres->getDescricao("Organico")<<endl;
        cadres->daleted(*res);
        cadres->~cadastroResiduo();
        
        Ranking *rak= new Ranking(cadAgen);
        rak->maiorDoadorImprime();
        rak->maiorReceptorImprime();
        rak->rankingDoarLista();
        rak->rankingReceptorLista();
        */

        /*casos de erros

            Pessoa *p6 = new Pessoa("Daniel Quirino", "Rua João Fernandes", "30/02/1997", true, true , "13642091601"); //erro data de nascimento
            Pessoa *p7 = new Pessoa("Filipe Lauar", "Avenida Miguel Perrela", "20/02/1996", true, false , "13494658678"); //erro cpf
            Pessoa *p8 = new Pessoa("Pedro Vieira", "Rua Fernando de Albuquerque", "08/09/1994", false, false , "6888489700010"); //erro cnpj

            cp->update(*p1, "Daniel Pires", "Rua João Fernandes 107", "10/05/2019", false); //erro de data de nascimento no update


        */

    }
    catch(string s)
    {
        cerr << s << endl;
    }
}
