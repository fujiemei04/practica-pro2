/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/
#ifndef USUARIO_HH
#define USUARIO_HH
#ifndef NO_DIAGRAM
#include <map>
#endif
#ifndef NO_DIAGRAM
#include <set>
#endif
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;



/** @class Usuario
    @brief Representa la información y las operaciones asociadas a un usuario.
    
    Sus operaciones son la consultoras curso inscrito, los envios realizados, si un usuario ya ha intentado resolver
    un problema, si un usuario existe en la plataforma, el numero de envios correctos y totales de un usuario, si un problema y ha sido 
    intentado, si un problema ya ha sido resuelto y cuantos problemas hay en los problemas enviables. Las modificadoras del curso inscrito,
    envios y resueltos, el numero de problemas que se ha intentado resolver, la modificacion del numero de envios a un problema enviable, 
    quitar un problema de los problemas enviables y adicion de un problema a los problemas enviables o resueltos y añadir un problema si ha sido el primer intento. 
    La lectura y escritura de un conjunto de usuarios y la escritura de los problemas enviables y resueltos o de un usuario.
*/

class Usuario {
    private:
     
     /** @brief Mapa de problemas enviables ordenados por orden lexicografico, donde el
         key es el nombre del problema y la clave cuantos envios se han realizado 
      */
     map<string,int> problemas_enviables;
     
     /** @brief Mapa de problemas resueltos ordenados por orden lexicografico, donde el
        key es el nombre del problema y la clave cuantos envios se han realizado antes de ser
        resuelto
      */
     map<string,int> problemas_resueltos;
     
     /** @brief Set de problemas de los cuales el usuario ya ha hecho almenos un envio */
     set<string> envios_a_prob;

     /** @brief Cuantos problemas ha intentado resolver */
     int envios_problemas;
     
     /** @brief Envios realizados por un usuario */
     int envios;
     
     /** @brief Envios correctos por un usuario */
     int resueltos;
     
     /**  @brief curso inscrito por un usuario */ 
     int curso_inscrito;

     

    public:
      
      //Constructoras

      /** @brief Constructora por defecto
      \pre Cierto
      \post El resultado es una Usuario sin atributos
      */
      Usuario();
      
      //Consultoras
      
      /** @brief Consulta los envios totales
      \pre Cierto
      \post El resultado es el atributo envios del parametro implicito
      */
      int consultar_envios() const;

      /** @brief Consulta los problemas resueltos
      \pre Cierto
      \post El resultado es el atributo resueltos del parametro implicito
      */ 
      int consultar_resueltos() const;
      
      /** @brief Consulta cuantos problemas ha intentado resolver
      \pre Cierto
      \post El resultado es el atributo envios_problemas del parametro implicito
      */ 
      int consultar_envios_problemas() const;
      
      /** @brief Consulta en que curso esta inscrito
      \pre Cierto
      \post El resultado es el atributo curso_inscrito del parametro implicito
      */ 
      int consultar_curso_inscrito() const;
      
      /** @brief Consulta si un problema esta resuelto
      \pre Cierto
      \post El resultado es cierto si el problema ya ha sido resuelto,falso contrariamente
      */ 
       bool prob_resolucio(const string& s) const;
       
        /** @brief Consulta si un problema ya ha sido intentado anteriormente
      \pre Cierto
      \post El resultado es cierto si el problema ya ha sido intentado anteriormente,falso contrariamente
      */
       bool envios_prob_aux(const string& p) const;
       
       /** @brief Consulta cuantos problemas enviables hay
      \pre Cierto
      \post El resultado es el numero de problemas enviables
      */
       int consultar_tam_prob_env() const;

      
      //Modificadoras

      /** @brief Modifica el curso inscrito por el usuario
      \pre Cierto
      \post El curso inscrito por el usuario pasa a ser el entero c
      */  
      void modificar_curso(int c);
      
      /** @brief Modifica los envios hechos por el usuario
      \pre Cierto
      \post Los envios hechos por el usuario del parametro implicito  pasa a ser el entero c
      */
      void modificar_envios(int c);
      
      /** @brief Modifica el numero de problemas resueltos por el usuario
      \pre Cierto
      \post El numero de problemas resueltos por el usuario del parametro implicito pasa a ser el entero c
      */
      void modificar_resueltos(int c);
      
      /** @brief Modifica el numero de problemas diferentes que el usuario ha itentado resolver
      \pre Cierto
      \post El numero de problemas diferentes que el usuario del parametro implicito ha intentado resolver pasa ser el entero c
      */
      void modificar_envios_problemas(int c);

      /** @brief Añade un problema a los problemas enviables
      \pre El problema s existe
      \post Se ha añadido a los problemas enviables del parametro implicito el problema s 
      */ 
      void anadir_prob_env(const string& s);

      /** @brief Modifica los envios de los problemas enviables
      \pre El problema s existe
      \post Se le suma uno a los envios de un problema de los problemas enviables del parametro implicito
      */  
      void modificar_env_pe(const string& s);
      
      /** @brief Añade un problema a los problemas que el usuario ha intentado resolver 
        recientemente pero que no ha enviado ninguna vez anteriomente
      \pre El problema p existe
      \post El problema p es añadido a los problemos que el usuario ha intentado resolver 
        recientemente pero que no ha enviado ninguna vez anteriomente
      */  
      void anadir_env_prob_aux(const string& p);
      
      /** @brief Elimina un problema de los problemas enviables
      \pre El problema p existe
      \post El problema p es eliminado de los problemsa enviables del parametro implicito
      */ 
      void quitar_problema_env(const string& p);
      
       /** @brief Añade un problema a los problemas resueltos
      \pre El problema p existe
      \post El problema p es añadido a los problemas resueltos
      */ 
      void anadir_pr(const string& p);

      //escritura
      
      /** @brief Escritura de los problemas enviables
      \pre Cierto
      \post Se ha imprimido en el canal estándar de salida los problemas
      enviables
      */
      void escribir_pe() const;
      
      /** @brief Escritura de los problemas resueltos
      \pre Cierto
      \post Se ha imprimido en el canal estándar de salida los problemas
      resueltos
      */
      void escribir_pr() const;

};
#endif