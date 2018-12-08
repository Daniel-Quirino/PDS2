#include "Residuo.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

Residuo::Residuo(bool _solido, string _material, string _descricao) {
    solido = _solido;
    descricao = _descricao;
    material = _material;
}

void Residuo::setSolido(bool _solido) {solido = _solido;}
void Residuo::setMateria(string _material) {material = _material;}
void Residuo::setDescricao(string _descricao) {descricao = _descricao;}

bool Residuo::getSolido() {return solido;}
string Residuo::getMaterial() {return material;}
string Residuo::getDescricao() {return descricao;}
