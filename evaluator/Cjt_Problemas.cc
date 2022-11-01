/** @file Cjt_Problemas.cc
    @brief Código de la clase Cjt_Problemas
*/

#include "Cjt_Problemas.hh"

bool sort_ratio(const pair<string,Problema>& a,const pair<string,Problema>& b) {
    if (a.second.consultar_ratio() != b.second.consultar_ratio()) return a.second.consultar_ratio() < b.second.consultar_ratio();
    return a.first < b.first;
}

Cjt_Problemas::Cjt_Problemas() {
}

bool Cjt_Problemas::buscar_problema(string p) const {
    map<string,Problema>::const_iterator it = Problemas.find(p);
    return it != Problemas.end();
}

int Cjt_Problemas::consultar_envios_tot(const string& p) const {
   map<string,Problema>::const_iterator it = Problemas.find(p);
   return it->second.consultar_envios_totales();
}

int Cjt_Problemas::consultar_envios_corr(const string& p) const {
   map<string,Problema>::const_iterator it = Problemas.find(p);
   return it->second.consultar_correctos();
}

int Cjt_Problemas::nuevo_problema(string p) {
    map<string,Problema>::iterator it = Problemas.find(p);
    if (it == Problemas.end()) {
        Problema P;
        Problemas.insert(make_pair(p,P));
        return Problemas.size();
    }
    return -1;
}

void Cjt_Problemas::modf_envios_corr(const string& p,int c) {
    map<string,Problema>::iterator it = Problemas.find(p);
    it->second.modificar_envios_corr(c);
}

void Cjt_Problemas::modf_envios_tot(const string& p,int c) {
    map<string,Problema>::iterator it = Problemas.find(p);
    it->second.modificar_envios_tot(c);
}

void Cjt_Problemas::leer_cjt_problemas(int n) {
    int i = 0;
    while (i < n) {
       Problema P;  
       string p;
       cin >> p;
       Problemas.insert(make_pair(p,P));
       ++i;
    } 
}

void Cjt_Problemas::listar_problemas() const {
    map<string,Problema>::const_iterator it;
    vector<pair<string,Problema> > vecprob;
    for (it = Problemas.begin();it != Problemas.end();++it) {
      vecprob.push_back(make_pair(it->first,it->second));
    }
    sort(vecprob.begin(),vecprob.end(),sort_ratio);
    int n = vecprob.size();
    for (int i = 0;i < n;++i) {
        cout << vecprob[i].first << "(" << vecprob[i].second.consultar_envios_totales() << ",";
        cout << vecprob[i].second.consultar_correctos() << ",";
        cout << vecprob[i].second.consultar_ratio() << ")" << endl;
    }
}



void Cjt_Problemas::escribir_problema(string p) const{
    map<string,Problema>::const_iterator it = Problemas.find(p);
    if (it != Problemas.end()) {
        cout << it->first << "(" << it->second.consultar_envios_totales() <<",";
        cout << it->second.consultar_correctos() << ",";
        cout << it->second.consultar_ratio() << ")" << endl;
    }
    else cout << "error: el problema no existe"  << endl;
}




