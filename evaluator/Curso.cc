/** @file Curso.cc
    @brief Código de la clase Curso
*/


#include "Curso.hh"

Curso::Curso() {
    completados = inscritos_actual = 0;
}

int Curso::consultar_tam_curso() const {
    return Subset_Sesion.size();
}

int Curso::consultar_inscritos_actual() const {
    return inscritos_actual;
}

int Curso::consultar_completados() const {
    return completados;
}

string Curso::consultar_nombre_sesion(int i) const {
    return Subset_Sesion[i];
}

bool Curso::hallar_problema(const string& p,string& s) const{
    map<string,string>::const_iterator it = prob_ses.find(p);
    if (it != prob_ses.end()) {
        s = it->second;
        return true;
    }
    return false;
}

string Curso::buscar_sesion_prob(const string& p) const {
    map<string,string>::const_iterator it = prob_ses.find(p);
    return it->second;
}

void Curso::modificar_completados(int c) {
    completados = c;
}

void Curso::nuevo_curso_aux(int n,Cjt_Sesiones& S,bool& interseccion) {
   interseccion = false;
    for (int i = 0;i < n;++i) {
        string s;
        cin >> s;
        int l = S.consultar_tam_ses(s);
        int j = 0;
        Subset_Sesion.push_back(s);
        while (j < l and not interseccion) {
            pair<map<string,string>::iterator,bool> p;
            p = prob_ses.insert(make_pair(S.consultar_problema(j,s),s));
            if (not p.second) interseccion = true;
            ++j;
        }
    }
}

void Curso::modificar_insc_actu(int c) {
    inscritos_actual = c;
}

void Curso::leer_curso(int n,Cjt_Sesiones& S) {
    for (int i = 0;i < n;++i) {
        string s;
        cin >> s; 
        Subset_Sesion.push_back(s);
        int n = S.consultar_tam_ses(s);
        for (int j = 0;j < n;++j) {
            prob_ses.insert(make_pair(S.consultar_problema(j,s),s));
        }
    }
}

void Curso::imprimir_curso() const {
    int n = Subset_Sesion.size();
    cout  << completados << " " << inscritos_actual << " ";
    cout << n << " ";
    cout << "(";
    bool parar = false;
    for (int i = 0;i < n;++i) {
        if (parar) cout << " ";
        else parar = true;
        cout << Subset_Sesion[i];
    }
    cout << ")" << endl;
}


