/** @file Curso.hh
    @brief Especificación de la clase Curso
*/
#ifndef CJT_CURSO_HH
#define CJT_CURSO_HH
#include "Cjt_Sesiones.hh"
#ifndef NO_DIAGRAM
#include <vector>
#endif



/** @class Curso
    @brief Representa la información y las operaciones asociadas a un curso.
    
    Sus operaciones son las consultoras del numero del numero de sesiones de un curso,
    los inscritos actuales y cuantos usuarios han completado el curso, el nombre de una  
    sesion del curso, la existencia de un problema y la busqueda del nombre de una sesion 
    a partir de un problema. Las modificadoras del numero de inscritos y completados,
    nuevo curso y la lectura y escritura de un curso
*/

class Curso {
    
    private:

      /** @brief Subconjunto de sesiones del curso */
      vector<string> Subset_Sesion;
       
      /** @brief Un map con el nombre de un problema como key asociado a su sesion */
      map<string,string> prob_ses;

      /** @brief Cuantos usuarios han completado el curso */
      int completados;
      
      /** @brief Usuarios inscritos actualmente en el curso */
      int inscritos_actual;

    public:

      //Constructoras

      /** @brief Constructora por defecto
      \pre Cierto
      \post El resultado es una Curso con atributos vacios
      */
      Curso();
      
      
      //Consultoras
      
      /** @brief Consulto el tamaño del curso
      \pre Cierto
      \post El resultado es el nombre de sesiones que tiene el curso del parametro implicito
      */
      int consultar_tam_curso() const ;
      
      /** @brief Consulto el numero de inscritos actualmente
      \pre Cierto
      \post El resultado es el atributo inscritos_actual del parametro implicito
      */
      int consultar_inscritos_actual() const;
      
      /** @brief Consulto el numero de inscritos en total
      \pre Cierto
      \post El resultado es el atributo inscritos_total del parametro implicito
      */
      int consultar_completados() const;

      
      /** @brief Consulto el nombre de una sesion 
      \pre i >= 0
      \post Devuelve el nombre de la sesion que se buscaba en el parametro implicito
      */
      string consultar_nombre_sesion(int i) const;
      
       /** @brief Consulto el nombre de una sesion al qual pertence un problema
      \pre Cierto
      \post Si el problema existe en el parametro implicigo devuelve true y el parametro s pasa a ser el de la sesion
      al cual pertence el problema, falso contrariamente
      */
      bool hallar_problema(const string& p,string& s) const;
      
      /** @brief Consulto el nombre de una sesion al qual pertence un problema
      \pre El problema existe
      \post Devuelve el nombre de la sesion al qual pertenecia el problema p del parametro implicito
      */
      string buscar_sesion_prob(const string& p) const;
   


     //Modificadoras
      
      /** @brief Modifica el numero de usuarios que han completado un curso
      \pre Cierto
      \post El parametro implicito completados pasa a ser c
      */
      void modificar_completados(int c);
      
      /** @brief Se crea un nuevo curso
      \pre n > 0
      \post Un nuevo curso es creado y en caso de que no haya interseccion de problemas,
      todos los problemas y sus sesiones son añadidos al parametro implicito e interseccion es falso,
      contrariamente interseccion es falso
      */
      void nuevo_curso_aux(int n,Cjt_Sesiones& S,bool& interseccion);
      
      /** @brief Modifica el numero de inscritos
      \pre c >= 0
      \post El numero de inscritos del parametro implicito pasa a ser el entero c
      */
      void modificar_insc_actu(int c);
         
      //Lectura y escritura

      /** @brief Lectura de un curso
      \pre n > 0
      \post El parámetro implícito pasa a tener los atributos leídos del canal
      estándar de entrada
      */
      void leer_curso(int n,Cjt_Sesiones& S);
      
      /** @brief Escritura de un curso
      \pre Cierto
      \post Se ha escrito en el canal estándar de salida los atributos del parámetro implícito
      */
      void imprimir_curso() const;
};

#endif
 
