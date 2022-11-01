/** @file Usuario.cc
    @brief Código de la clase Usuario
*/


#include "Usuario.hh"

Usuario::Usuario() {
    resueltos = envios = curso_inscrito = envios_problemas = 0;
}

int Usuario::consultar_envios() const{
    return envios;
}

int Usuario::consultar_resueltos() const {
    return resueltos;
}

int Usuario::consultar_envios_problemas() const {
    return envios_problemas;
}

int Usuario::consultar_curso_inscrito() const {
    return curso_inscrito;
}

bool Usuario::prob_resolucio(const string& s) const {
  map<string,int>::const_iterator it = problemas_resueltos.find(s);
  if (it != problemas_resueltos.end()) return true;
  return false;
}

bool Usuario::envios_prob_aux(const string& p) const {
    set<string>::const_iterator it = envios_a_prob.find(p);
    if (it != envios_a_prob.end()) return true;
    return false;
}

int Usuario::consultar_tam_prob_env() const {
   return problemas_enviables.size();
}

void Usuario::modificar_curso(int c) {
   curso_inscrito = c;
}

void Usuario::modificar_envios(int c) {
   envios = c;
}

void Usuario::modificar_resueltos(int c) {
   resueltos = c;
}

void Usuario::modificar_envios_problemas(int c) {
   envios_problemas = c;
}

void Usuario::anadir_prob_env(const string& s) {
    problemas_enviables.insert(make_pair(s,0));
}

void Usuario::modificar_env_pe(const string& s) {
   map<string,int>::iterator it = problemas_enviables.find(s);
   it->second = it->second+1;
}


void Usuario::anadir_env_prob_aux(const string& p) {
    envios_a_prob.insert(p);
}

void Usuario::quitar_problema_env(const string& p) {
    problemas_enviables.erase(p);
}

void Usuario::anadir_pr(const string& p) {
  map<string,int>::const_iterator it = problemas_enviables.find(p);
    int n = it->second;
  problemas_resueltos.insert(make_pair(p,n));
}

void Usuario::escribir_pe() const {
    map<string,int>::const_iterator it;
    for (it = problemas_enviables.begin();it != problemas_enviables.end();++it) {
        cout << it->first << "(" << it->second << ")" <<endl;
    }
}

void Usuario::escribir_pr() const {
    map<string,int>::const_iterator it;
    for (it = problemas_resueltos.begin();it != problemas_resueltos.end();++it) {
        cout << it->first << "(" << it->second << ")" <<endl;
    }
}