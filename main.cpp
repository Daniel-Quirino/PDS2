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

using namespace std;

int main() {

    Pessoa *p1 = new Pessoa("Daniel Quirino", "Rua João Fernandes", "11/11/1997", true, true , "13494658609");
    Pessoa *p2 = new Pessoa("Filipe Lauar", "Avenida Miguel Perrela", "20/02/1996", true, false , "36559173097");
    Pessoa *p3 = new Pessoa("Pedro Vieira", "Rua Fernando de Albuquerque", "08/09/1994", false, false , "47994400043");
    Pessoa *p4 = new Pessoa("Lucas Mello ", "Rua Boaventura", "16/04/1993", true, true , "56493783046");
    Pessoa *p5 = new Pessoa("Augusto da Silva ", "Rua Paramarinbo", "11/03/1969", false, true , "01156079004");

    CadastroPessoa *cp = new CadastroPessoa();
    cp->create(*p1);
    cp->create(*p2);
    cp->create(*p3);
    cp->create(*p4);
    cp->create(*p5);

    cout << "-------------- Listar as pessoas cadastradas: -------------" << endl;
    cp->listarUsuarios();
    cout << endl << endl;



    cp->deleted(*p2);
    cp->deleted(*p4);
    cp->update(*p1, "Daniel Pires", "Rua João Fernandes 107", "10/05/1997", false, false , "78879349074" );

    cout << "-------- Lista atualizada de pessoas cadastradas: --------" << endl;
    cp->listarUsuarios();
    cout << endl << endl;



    PontoDeColeta *pontCol = new PontoDeColeta("Rua Alameda dos Anjos", "Liberdade", 129, "apt 107");
    PontoDeColeta *pontCol2 = new PontoDeColeta("Praça da Savassi", "Savassi", 10, "perto do BK");

    Agendamento *ag1 = new Agendamento("18/11/2018", *pontCol, *p1, *p3, "Papelao");
    Agendamento *ag2 = new Agendamento("30/06/2009", *pontCol2, *p4, *p5, "Vidro");

    CadastroAgendamento *cadAgen = new CadastroAgendamento();
    cadAgen->create(*ag1);
    cadAgen->create(*ag2);

    cout << "----------------- Lista de Agendamentos: -----------------" << endl;
    cadAgen->listarAgendamentos();
    cout << endl << endl;

    Residuo *res = new Residuo(true, "vidro", "O vidro nao deve ser descartado sem uma protecao adequada");
    cout << "Descricao: " << res->getDescricao() << endl;


}
