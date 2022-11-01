/** @file Sesion.hh
    @brief Especificación de la clase Usuario
*/
#ifndef SESION_HH
#define SESION_HH
#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif
#include "Cjt_Usuarios.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif
#ifndef NO_DIAGRAM
#include <vector>
#endif



/** @class Sesion
    @brief Representa la información y las operaciones asociadas a una sesión.
    
    Sus operaciones son las consultoras del identificador de un problema y el numero de problemas.
    Las modificadoras actualizar problemas enviables y la lectura y escritura de los problems 
    o el problema prerrequisito de todos.

    Hay declarada dos operaciones auxiliar como \em private
*/


class Sesion {
    
    private:
    
     /** @brief El numero de problemas que hay en la sesion */
     int numero_problemas;
    
     /** @brief Un arbol binario de problemas */
     BinTree<string> problemas;
     
     /** @brief Un vector de problemas */
     vector<string> probs;

    public:
      
      //Constructoras
     
      /** @brief Constructora por defecto
      \pre Cierto
      \post El resultado es una sesion con los atributos sin inicializar
      */
      Sesion();
      
      //Consultoras
      
      /** @brief Consulta el nombre de un problema de la sesion
      \pre Cierto
      \post El resultado es nombre de un problema del parametro implicito
      */
      string consultar_problema_iesimo(int i) const;
      
       /** @brief Consulta el numero de problemas de la sesion
      \pre Cierto
      \post El resultado es el numero de problemas del parametro implicito
      */
      int consultar_tam_probs() const;
      

      //Modificadoras
      
      /** @brief Actualiza los problemas enviables del usuario u respecto al problema p
      \pre Cierto
      \post Los problemas enviables del usuario u son actualizados
      */
      void act_problemes_enviables_aux(Cjt_Usuarios& U,const string& u,const string& p); 
      
      //Lectura i escritura
      
      /** @brief Lee una sesion
      \pre Cierto
      \post Se entrará su nombre y una secuencia de identificadores de problemas siguiendo 
      un recorrido en preorden de su estructura de prerequisitos
      */
      void leer_sesion();
      
      /** @brief imprime una sesion
      \pre Cierto
      \post Imprime por pantalla un subconjunto de problemas en preorden de requisitos
      */
      void imprimir_problemas() const;

      /** @brief Imprime el problema prerrequisitos de todos de la sesion
      \pre Cierto
      \post Retorna el problema prerrequisito de todos del parametro implicito
      */
      string escribir_problema() const;

    private:
     
     /** @brief Lee un arbol de problemas en su orden de prerrequisitos
      \pre Cierto
      \post El parámetro implícito contiene los problemas leídos del
      canal estándar de entrada 
      */
     void leer_sesion_problemas(BinTree<string>&t);
     
     /** @brief Encuentra un subarbol de un nodo
      \pre Cierto
      \post Devuelve el subarbol con un nodo con identificador s del parametro implicito, si el arbol de entrada es vacio devuelve un arbol vacio
      */
     BinTree<string> trobar_arbre(const string& s);  
};
#endif