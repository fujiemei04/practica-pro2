/** @file Cjt_Cursos.cc
    @brief Código de la clase Cjt_Cursos
*/

#include "Cjt_Cursos.hh"
#include "Cjt_Problemas.hh"

Cjt_Cursos::Cjt_Cursos() {

}

int Cjt_Cursos::consultar_inscripciones(int i) const{
    return Cursos[i-1].consultar_inscritos_actual();
} 

int Cjt_Cursos::consultar_tam() const {
    return Cursos.size();
}

int Cjt_Cursos::consultar_tam_curso_i(int i) const {
    return Cursos[i-1].consultar_tam_curso();
}

string Cjt_Cursos::consultar_nom_session(int i,int n) const {
    return Cursos[i-1].consultar_nombre_sesion(n);
}

void Cjt_Cursos::sesion_problema(int c, string p,Cjt_Problemas& P,string& s) {
    int tam = Cursos.size();
    if (c > tam or c == 0) cout << "error: el curso no existe" << endl;
    else if (not P.buscar_problema(p)) cout <<  "error: el problema no existe" << endl;
    else if (Cursos[c-1].hallar_problema(p,s)) cout << s <<endl;
    else cout << "error: el problema no pertenece al curso" << endl;
}

int Cjt_Cursos::nuevo_curso(Cjt_Sesiones& S,bool& interseccio) {
    int i;
    cin >> i;
    Curso c;
    c.nuevo_curso_aux(i,S,interseccio);
    if (not interseccio) {
        Cursos.push_back(c);
        return Cursos.size();
    }
    return -1;
}

void Cjt_Cursos::modf_num_insc(int c,int n) {
    Cursos[c-1].modificar_insc_actu(n);
}

void Cjt_Cursos::modf_num_completados(int c,int n) {
    Cursos[c-1].modificar_completados(n);
}

int Cjt_Cursos::inscribir_curso(int i,string u,Cjt_Sesiones& S,Cjt_Usuarios& U) {
   if (not U.buscar_usuario(u)) return -1; 
   else if (i > Cursos.size() or i == 0) return -2;
   else if (U.consultar_inscrito_curso(u) != 0) return -3;
   else {
      U.modificar_curso_inscrito(i,u);
      int n = Cursos[i-1].consultar_inscritos_actual();
      Cursos[i-1].modificar_insc_actu(n+1);
      int m = Cursos[i-1].consultar_tam_curso();
      for (int j = 0;j < m;++j) {
        //Si el problema prrerequisitos no fue resuelto, lo añadimos directamente, de lo contrario
        //necesitaremos actualizarlo
        if (U.prob_resolucions(u,S.escribir_raiz(Cursos[i-1].consultar_nombre_sesion(j)))) {
          S.actualizar_problemas_env(U,u,Cursos[i-1].consultar_nombre_sesion(j),S.escribir_raiz(Cursos[i-1].consultar_nombre_sesion(j)));
        }
        else S.inicializar_problemas_env(U,u,Cursos[i-1].consultar_nombre_sesion(j));
    }
    return Cursos[i-1].consultar_inscritos_actual();
   }
}

void Cjt_Cursos::envio(const string& u,const string& p,int r,Cjt_Sesiones& S,Cjt_Usuarios& U,Cjt_Problemas& P) {
    //Si no se ha intentado resolver el problema lo añadimos a los problemas que el usuario
    //ha intentado resolver
   if (not U.envios_a_prob(u,p)) U.modificar_envios_a_problemas_dif(U.consultar_env_prob(u)+1,u);
   U.anadir_envios_a_prob(p,u);
   U.modificar_envios_u(U.consultar_envios_u(u)+1,u);
   U.modf_env_pe(u,p);
   P.modf_envios_tot(p,P.consultar_envios_tot(p)+1);
   if (r == 1) {
      P.modf_envios_corr(p,P.consultar_envios_corr(p)+1);
      U.modificar_resueltos_u(U.consultar_resueltos_u(u)+1,u);
      U.anadir_prob_resuelto(p,u);
      S.actualizar_problemas_env(U,u,Cursos[U.consultar_inscrito_curso(u)-1].buscar_sesion_prob(p),p);
      U.quitar_prob_env(p,u);
      int n = U.consultar_inscrito_curso(u);
      if (U.consultar_prob_env_tam(u) == 0) {
          Cursos[n-1].modificar_completados(Cursos[n-1].consultar_completados()+1);
          Cursos[n-1].modificar_insc_actu(Cursos[n-1].consultar_inscritos_actual()-1);
          U.modificar_curso_u(u,0);
        }
    }
}

void Cjt_Cursos::leer_cursos(int n,Cjt_Sesiones& S) {
    for (int i = 0;i < n;++i) {
      Curso c;  
      int p;
      cin >> p;
      c.leer_curso(p,S);
      Cursos.push_back(c);
    }

}

void Cjt_Cursos::listar_cursos() const {
    int n = Cursos.size();
    for (int i = 0;i < n;++i) {
       cout << i+1 << " ";
       Cursos[i].imprimir_curso();
    }
}

void Cjt_Cursos::escribir_curso(int n) const {
    int tam = Cursos.size();
    if (n > tam or n == 0) cout << "error: el curso no existe" << endl;
    else  {
        cout << n << " ";
        Cursos[n-1].imprimir_curso();
    }
}







