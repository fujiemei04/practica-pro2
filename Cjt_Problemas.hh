/** @file Cjt_Problemas.hh
    @brief Especificación de la clase Cjt_Problemas
*/
#ifndef CJT_PROBLEMAS_HH
#define CJT_PROBLEMAS_HH
#include "Problema.hh"
#ifndef NO_DIAGRAM
#include <map>
#endif
#ifndef NO_DIAGRAM
#include <algorithm>
#endif
#ifndef NO_DIAGRAM
#include <vector>
#endif


/** @class Cjt_Problemas
    @brief Representa la información y las operaciones asociadas a un conjuto de problemas.
    
    Sus operaciones son las consultoras buscar problema el cual busca si existe un problema
    en el conjunto, consultar envios correctos y totales de un problema. Las modificadoras
    nuevo problema, modificar envios correctos y totales y la lectura y escriptura de un conjunto 
    de problemas o un problema en especifico.
*/

class Cjt_Problemas {

    private: 
     
      /** @brief Mapa de problemas donde el key es el nombre del problema */
      map<string,Problema> Problemas;
    
      
    public:
      
      //Constructoras

      /** @brief Constructora por defecto
      \pre Cierto
      \post Se ha creado un conjunto de problemas vacio 
      */
      Cjt_Problemas(); 

      //Consultoras
      
      /** @brief Busca un problema p
      \pre Cierto
      \post El resultado es true si el parámetro implícito contiene el problema p,
       falso contrariamente
      */
      bool buscar_problema(string p) const;
      
      /** @brief Consulta los envios totales del parametro implicito
      \pre Cierto
      \post El resultado es los envios totales del parametro implicito
      */
      int consultar_envios_tot(const string& p) const;
      
      /** @brief Consulta los envios correctos del parametro implicito
      \pre Cierto
      \post El resultado es los envios correctos del parametro implicito
      */
      int consultar_envios_corr(const string& p) const;

      //Modificadoras
      
      /** @brief Añade un nuevo problema
      \pre Cierto
      \post Si p ya existia, devuelve un -1, contrariamente imprime el número total de problemas
      despues de añadir p al parametro implicito
      */
      int nuevo_problema(string p);
      
      /** @brief Modifica el numero de envios correctos a un problema 
      \pre Cierto
      \post El numero de envios correctos del problema p del parametro implicito pasa a ser c
      */
      void modf_envios_corr(const string& p,int c);
      
      /** @brief Modifica el numero de envios correctos a un problema 
      \pre Cierto
      \post El numero de envios totales del problema p del parametro implicito pasa a ser c
      */
      void modf_envios_tot(const string& p,int c);
      
       
      //Lectura i escritura  

      /** @brief Lectura de un conjunto de problemas
      \pre n > 0
      \post El parámetro implícito pasa a tener los atributos leídos del canal
      estándar de entrada
      */
      void leer_cjt_problemas(int n);
      
      /** @brief Se listan los problemas de la coleccion
      \pre Cierto
      \post Se listan los problemas de la colección, 
        indicando para cada problema el número t de envíos totales y el número e de envíos 
        con éxito a dicho problema. Se escriben ordenados con el ratio (e+1)/(t+1),en caso de empate
        por orden lexicografico
      */
      void listar_problemas() const;


      /** @brief Se escribe un problema
      \pre Cierto
      \post Se imprime por pantalla los atributos de un problema si existe en el conjunto
      */
      void escribir_problema(string p) const;
};
#endif

