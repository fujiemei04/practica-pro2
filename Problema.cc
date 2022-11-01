/** @file Problema.cc
    @brief Código de la clase Problema
*/


#include "Problema.hh"

Problema::Problema() {
    envios_correctos = 0;
    envios_totales = 0;
}


int Problema::consultar_envios_totales() const {
    return envios_totales;
}

int Problema::consultar_correctos() const {
    return envios_correctos;
}


double Problema::consultar_ratio() const {
    return double((envios_totales+1))/(envios_correctos+1);
}

void Problema::modificar_envios_corr(int c) {
    envios_correctos = c;
}
      
void Problema::modificar_envios_tot(int c) {
    envios_totales = c;
}





