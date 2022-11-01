/** @file Cjt_Usuarios.cc
    @brief Código de la clase Cjt_Usuarios
*/


#include "Cjt_Usuarios.hh"

Cjt_Usuarios::Cjt_Usuarios() {
}

int Cjt_Usuarios::consultar_inscrito_curso(const string& u) const {
  map<string,Usuario>::const_iterator it = U.find(u);
  return it->second.consultar_curso_inscrito();
}

bool Cjt_Usuarios::buscar_usuario(string p) const {
   map<string,Usuario>::const_iterator it = U.find(p);
   return it != U.end();
}

int Cjt_Usuarios::curso_usuario(const string& usuario) const {
   map<string,Usuario>::const_iterator it = U.find(usuario);
   if (it == U.end()) return -1;
   return it->second.consultar_curso_inscrito();
}

int Cjt_Usuarios::consultar_env_prob(const string& u) const {
   map<string,Usuario>::const_iterator it = U.find(u);
   return it->second.consultar_envios_problemas();
}

bool Cjt_Usuarios::envios_a_prob(const string& u,const string& p) const{
   map<string,Usuario>::const_iterator it = U.find(u);
   return it->second.envios_prob_aux(p);
}

bool Cjt_Usuarios::usuario_inscrito(const string& u) const {
   map<string,Usuario>::const_iterator it = U.find(u);
   if (it == U.end()) return false;
   return true;
}

bool Cjt_Usuarios::prob_resolucions(const string& u,const string& p) const {
   map<string,Usuario>::const_iterator it = U.find(u);
   return it->second.prob_resolucio(p);
}

int Cjt_Usuarios::consultar_envios_u(const string& u) const {
    map<string,Usuario>::const_iterator it = U.find(u);
   return it->second.consultar_envios();
}
      
int Cjt_Usuarios::consultar_resueltos_u(const string& u) const {
   map<string,Usuario>::const_iterator it = U.find(u);
   return it->second.consultar_resueltos();
}

int Cjt_Usuarios::consultar_prob_env_tam(const string& u) const {
   map<string,Usuario>::const_iterator it = U.find(u);
   return it->second.consultar_tam_prob_env();
}
 

int Cjt_Usuarios::alta_usuario(const string& u) {
   map<string,Usuario>::const_iterator it = U.find(u);
   if (it == U.end()) {
       Usuario user;
       U.insert(make_pair(u,user));
       return U.size();
   }
   else return -1;
}

int Cjt_Usuarios::baja_usuario(const string& u,int& n) {
    map<string,Usuario>::iterator it = U.find(u);
    if (it != U.end()) {
      n = it->second.consultar_curso_inscrito();
      U.erase(it);
      return U.size();
   }
   return -1;
}


void Cjt_Usuarios::modificar_curso_inscrito(int n,string p) {
   map<string,Usuario>::iterator it = U.find(p);
   it->second.modificar_curso(n);
}


void Cjt_Usuarios::anadir_prob_enviable(const string& p,const string& u) {
   map<string,Usuario>::iterator it = U.find(u);
   it->second.anadir_prob_env(p);
}

void Cjt_Usuarios::modificar_envios_a_problemas_dif(int c,const string& u) {
   map<string,Usuario>::iterator it = U.find(u);
   it->second.modificar_envios_problemas(c);
}

void Cjt_Usuarios::modificar_envios_u(int c,const string& u) {
   map<string,Usuario>::iterator it = U.find(u);
   it->second.modificar_envios(c);
}

void Cjt_Usuarios::modificar_resueltos_u(int c,const string& u) {
   map<string,Usuario>::iterator it = U.find(u);
   it->second.modificar_resueltos(c);
}

void Cjt_Usuarios::modificar_curso_u(const string& u,int i) {
   map<string,Usuario>::iterator it = U.find(u);
   it->second.modificar_curso(i);
}

void Cjt_Usuarios::quitar_prob_env(const string& p,const string& u) {
   map<string,Usuario>::iterator it = U.find(u);
   it->second.quitar_problema_env(p);
}

void Cjt_Usuarios::modf_env_pe(const string& s,const string& p) {
   map<string,Usuario>::iterator it = U.find(s);
   it->second.modificar_env_pe(p);
}

void Cjt_Usuarios::anadir_prob_resuelto(const string& p,const string& u) {
   map<string,Usuario>::iterator it = U.find(u);
   it->second.anadir_pr(p);
}

void Cjt_Usuarios::anadir_envios_a_prob(const string&p,const string&u) {
    map<string,Usuario>::iterator it = U.find(u);
    it->second.anadir_env_prob_aux(p);
}

void Cjt_Usuarios::leer_cjt_usuario(int n) {
   int i = 0;
   while (i < n) {
      Usuario User; 
      string s;
      cin >> s; 
      U.insert(make_pair(s,User));
      ++i;
   }
}
      
void Cjt_Usuarios::listar_usuarios() const {
   map<string,Usuario>::const_iterator it = U.begin();
   while (it != U.end()) {
      cout <<it->first << "(" << it->second.consultar_envios() << ",";
      cout << it->second.consultar_resueltos() << ",";
      cout << it->second.consultar_envios_problemas() << ",";
      cout << it->second.consultar_curso_inscrito() << ")";
      cout << endl;
      ++it;
   }
}
      
    
void Cjt_Usuarios::escribir_usuario(string p) const {
   map<string,Usuario>::const_iterator it = U.find(p);
   if (it != U.end()) {
      cout <<it->first << "(" << it->second.consultar_envios() << ",";
      cout << it->second.consultar_resueltos() << ",";
      cout << it->second.consultar_envios_problemas() << ",";
      cout << it->second.consultar_curso_inscrito() << ")" << endl;
   }
   else cout << "error: el usuario no existe" << endl;
}


void Cjt_Usuarios::imprimir_problemas_enviables(const string& u) const {
    map<string,Usuario>::const_iterator it = U.find(u);
    if (it == U.end()) cout << "error: el usuario no existe" << endl;
    else if (it->second.consultar_curso_inscrito() == 0) 
      cout  << "error: usuario no inscrito en ningun curso" << endl;
    else {
      it->second.escribir_pe();
   }

}

void Cjt_Usuarios::imprimir_problemas_resueltos(const string& u) const {
   map<string,Usuario>::const_iterator it = U.find(u);
   if (it == U.end()) cout << "error: el usuario no existe" << endl;
   else it->second.escribir_pr();
}



