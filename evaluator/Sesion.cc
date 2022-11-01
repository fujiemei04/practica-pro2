/** @file Sesion.cc
    @brief Código de la clase Sesion
*/

#include "Sesion.hh"

Sesion::Sesion() {
   numero_problemas = 0;
}

int Sesion::consultar_tam_probs() const {
    return probs.size();
}

string Sesion::consultar_problema_iesimo(int i) const {
    return probs[i];
}

void Sesion::leer_sesion_problemas(BinTree<string>&t) {
    string p;
    cin >> p;
    if (p != "0") {
        probs.push_back(p);
        ++numero_problemas;
        BinTree<string> left;
        leer_sesion_problemas(left);
        BinTree<string> right;
        leer_sesion_problemas(right);
        t = BinTree<string>(p,left,right);
    }
}

void Sesion::leer_sesion() {
    leer_sesion_problemas(problemas);
}

BinTree<string> trobar_arbre_imm(const string& s,const BinTree<string>& t) {
    if (t.empty()) return BinTree<string>();
    if (t.value() == s) return t;
    BinTree<string> taux = trobar_arbre_imm(s,t.left());
    if (not taux.empty()) return taux;
    return trobar_arbre_imm(s,t.right());
}

BinTree<string> Sesion::trobar_arbre(const string& p) {
   return trobar_arbre_imm(p,problemas);
}

void Sesion::act_problemes_enviables_aux(Cjt_Usuarios& U,const string& p,const string& u) {
    BinTree<string> t = trobar_arbre(p);
    if (not t.left().empty()) {
        string s = t.left().value();
        bool esq = U.prob_resolucions(u,s);
        if (not esq) U.anadir_prob_enviable(s,u);
        else {
            act_problemes_enviables_aux(U,s,u);
        }
    }
    if (not t.right().empty()) {
        string ss = t.right().value();
        bool dre = U.prob_resolucions(u,ss);
        if (not dre) U.anadir_prob_enviable(ss,u);
        else {
            act_problemes_enviables_aux(U,ss,u);
        }
    }
}


void imprimir_preorden(const BinTree<string>& problemas) {
    if (not problemas.empty()) {
       cout << "(";
       imprimir_preorden(problemas.left());
       imprimir_preorden(problemas.right());
       cout << problemas.value();
       cout << ")";
    } 
}


void Sesion::imprimir_problemas() const{
    cout << numero_problemas << " ";
    imprimir_preorden(problemas);
}

string Sesion::escribir_problema() const {
   return problemas.value();
}




