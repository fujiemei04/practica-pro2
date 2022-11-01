/** @file Problema.hh
    @brief Especificación de la clase Usuario
*/
#ifndef PROBLEMA_HH
#define PROBLEMA_HH
#ifndef NO_DIAGRAM
#include <iostream> 
#endif
using namespace std;



/** @class Problema
    @brief Representa la información y las operaciones asociadas a un problema.
    
    Sus operaciones son las consultoras de cuantos envios se han a dicho problema y cuantos de estos han sido calificados
    como correctos, la consultora del ratio (envios totales+1)/(envios_correctos+1),  y las modificadoras de envio correcto 
    y totales.
*/

class Problema {

    private: 
      
      /** @brief Numero de envios de este problema */
      int envios_totales;

       /** @brief Numero de envios correctos a este problema */
      int envios_correctos;
      

    public:
      
      //Constructoras

      /** @brief Constructora por defecto
      \pre Cierto
      \post El resultado es una problema con envios totales y correctos inicializados a 0.
      */
      Problema();
      
      //Consultoras
      
      /** @brief Consulta los envios totales a un problema
      \pre Cierto
      \post El resultado es el atributo envios_totales del parametro implicito
      */
      int consultar_envios_totales() const;

      /** @brief Consulta los envios correctos a un problema
      \pre Cierto
      \post El resultado es el atributo envios_correctos del parametro implicito
      */
      int consultar_correctos() const;

      /** @brief Consulta el ratio 
      \pre Cierto
      \post El resultado es el ratio (envios_totales+1)/(envios_correctos+1)
      */
      double consultar_ratio() const;

      //Modificadoras
      
      /** @brief Modifica el numero de envios correctos del parametro implicito
      \pre Cierto
      \post El numero de envios correctos del parametro implicito pasa a ser c
      */
      void modificar_envios_corr(int c);
      
      /** @brief Modifica el numero de envios totales del parametro implicito
      \pre Cierto
      \post El numero de envios totales del parametro implicito pasa a ser c
      */
      void modificar_envios_tot(int c);

    
};

#endif