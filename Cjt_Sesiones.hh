/** @file Cjt_Sesiones.hh
    @brief Especificación de la clase Cjt_Sesiones
*/
#ifndef CJT_SESIONES_HH
#define CJT_SESIONES_HH
#include "Sesion.hh"
#ifndef NO_DIAGRAM
#include <map>
#endif




/** @class Cjt_Sesiones
    @brief Representa la información y las operaciones asociadas a un conjunto de sesiones.
   
    Sus operaciones son la consultora de un problema, el numero de problemas de una sesion,
    las modificadoras nueva sesion, inicializacion y actualizacion de los problemas enviables
    y la lectura y escritura de un conjunto de sesiones o escritura de una sesion o la escritura de 
    un problema prerrequisto de todos de una sesion.
*/


class Cjt_Sesiones {
    
    private:
    
     /** @brief Un map de sesion con un el identificador de la sesion como key */
     map<string,Sesion> Sesiones;


    public:
      
      //Constructoras
      
      /** @brief Constructora por defecto
      \pre Cierto
      \post Se ha creado un conjunto de sesiones vacia
      */
      Cjt_Sesiones();
       
      //Consultoras
      
      /** @brief Consulta el nombre de un problema de una sesion
      \pre Cierto
      \post El resultado es el nombre de un problema de la sesion s del parametro implicito
      */
      string consultar_problema(int i,const string& s) const;
      
      /** @brief Consulta el numero de problemas de una sesion
      \pre Cierto
      \post El resultado es el numero de problemas de la sesion s del parametro implicito
      */
      int consultar_tam_ses(const string& s) const;

      //Modificadoras

      /** @brief Añade una nueva sesion
      \pre Cierto
      \post Si existia la sesion anteriormente en el parametro implicito se imprime un mensaje de error, contrariamente imprime 
      el numero de sesiones despues de añadir s
      */
      int nueva_sesion(const string& s);

      /** @brief Inicializa los problemas enviables
      \pre Cierto
      \post Se han inicilializado los problemas enviables
      */
      void inicializar_problemas_env(Cjt_Usuarios& U,const string& u,const string& s);
      
      /** @brief Actualiza los problemas enviables de un usuario
      \pre Cierto
      \post Los problemas enviables del usuario u se han actualizado respecto a un problema p de la sesion s
      */
      void actualizar_problemas_env(Cjt_Usuarios& U,const string& u,const string& s,const string& p);

      //Lectura y escriptura

      /** @brief Lee un conjunto de sesiones
      \pre n > 0
      \post  El parámetro implícito contiene el conjunto de sesiones leídos del
      canal estándar de entrada
      */
      void leer_cjt_sesiones(int n);
      
      /** @brief Escritura de un conjunto de sesiones
      \pre Cierto
      \post Se ha imprimido en el canal estándar de salida el conjunto de sesiones
      */
      void listar_sesiones() const;

      /** @brief Imprime una sesion
      \pre Cierto
      \post Imprime por pantalla un los atributos de una sesion si existe en el conjunto,
      de lo contrario se imprime un mensaje de error
      */
      void escribir_sesion(const string& s) const;
      
      /** @brief Escribe el problema prerrequisito de una sesion
      \pre Cierto
      \post Imprime el problema prerrequisitos de todos de una sesion con identificador s
      */
      string escribir_raiz(const string& s) const;
};
#endif