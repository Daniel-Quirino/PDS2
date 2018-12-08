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
    Pessoa *p2 = new Pessoa("Filipe Lauar", "Avenida Miguel Perrela", "20/02/1996", true, false , "13494658609");
    Pessoa *p3 = new Pessoa("Pedro Vieira", "Rua Fernando de Albuquerque", "08/09/1994", false, false , "13494658609");
    Pessoa *p4 = new Pessoa("Lucas Mello ", "Rua Boaventura", "16/04/1993", true, true , "13494658609");

    CadastroPessoa *cp = new CadastroPessoa();
    cp->create(*p1);
    cp->create(*p2);
    cp->create(*p3);
    cp->create(*p4);


    cp->listarUsuarios();
    cout << "----------------------------------------------------------- " << endl;

    cp->deleted(*p2);
    cp->update(*p1, "Daniel Pires", "Rua João Fernandes 107", "10/05/1997", false, false , "13494658609" );
    cp->listarUsuarios();
    cout << "----------------------------------------------------------- " << endl;

    PontoDeColeta *pontCol = new PontoDeColeta("Rua Alameda dos Anjos", "Liberdade", 129, "apt 107");

    Agendamento *ag1 = new Agendamento("18/11/2018", *pontCol, *p1, *p2, "Papelao");
    Agendamento *ag2 = new Agendamento("30/06/2009", *pontCol, *p3, *p4, "Vidro");

    CadastroAgendamento *cadAgen = new CadastroAgendamento();
    cadAgen->create(*ag1);
    cadAgen->create(*ag2);
    cadAgen->listarAgendamentos();
    cout << "----------------------------------------------------------- " << endl;

    Residuo *res = new Residuo(true, "vidro", "O vidro nao deve ser descartado sem uma protecao adequada");
    cout << "Descricao: " << res->getDescricao() << endl;


}
