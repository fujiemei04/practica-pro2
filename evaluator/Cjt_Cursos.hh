/** @file Cjt_Cursos.hh
    @brief Especificación de la clase Cjt_Cursos
*/
#ifndef CJT_CURSOS_HH
#define CJT_CURSOS_HH
#include "Curso.hh"
#include "Cjt_Problemas.hh"


/** @class Cjt_Cursos
    @brief Representa la información y las operaciones asociadas a un conjunto de cursos
    
    Sus operaciones son las consultoras de inscripciones de un curso, el numero de cursos del 
    conjunto, el numero de sesiones de un curso,el nombre de una sesion de un curso, el nombre de una
    sesion de un problema. Las modificadores de inscritos y completados de un cursom
    la inscripcion de un usuario a un curso y nuevo curso. La lectura y escriptura de un conjunto de cursos
    o un curso.
*/


class Cjt_Cursos {
    
    private:
      
      /** @brief Un vector de cursos */
      vector<Curso> Cursos;

    
    public:
    
      //Constructoras

      /** @brief Constructora por defecto
      \pre Cierto
      \post El resultado es un conjunto de cursos vacio
      */
      Cjt_Cursos();

      //Consultores

      /** @brief Consulta el numero de inscritos total en curso
      \pre i >= 1
      \post Devuelve el numero de inscritos total en el curso del parametro implicito con identificador i
      */
      int consultar_inscripciones(int i) const;
       
      /** @brief Consulta cuantos cursos hay
      \pre Cierto
      \post Devuelve el numero de cursos del conjunto de cursos del parametro implicito
      */
      int consultar_tam() const;
      
      /** @brief Consulta cuantas sesiones hay en un curso 
      \pre i >= 1
      \post Devuelve el numero de sesiones en el curso del parametro implicito con identificador i
      */
      int consultar_tam_curso_i(int i) const;

      /** @brief Consulta el nombre de una sesion en un curso 
      \pre i >= 1
      \post Devuelve el nombre de la sesion a buscar en el curso i del parametro implicito
      */
      string consultar_nom_session(int i,int n) const;

       /** @brief Se consulta la sesion al cual pertence un problema
      \pre Cierto
      \post Si c es mayor que el numero de cursos o c = 0, el curso no existe y se imprime
      un mensaje de error. Si p no existe se imprime un mensaje de error. Si el problema
      pertenece al curso se imprime la sesion, si no se imprime un mensaje de error
      */
      void sesion_problema(int c,string p,Cjt_Problemas& P,string& s);

      
      //Modificadoras
      
      /** @brief Se modifica en un curso el numero de inscritos totales
      \pre Cierto
      \post El numero total de inscritos en el curso c del parametro implicito pasa a ser n
      */
      void modf_num_insc(int c,int n);
      
      /** @brief Se modifica en un curso el numero de completados
      \pre Cierto
      \post El numero total de inscritos en el curso c del parametro implicito pasa a ser n
      */
      void modf_num_completados(int c,int n);
      
      /** @brief Inscribe un usuario a un curso
      \pre Cierto
      \post Si el usuario u no existe devuelve un -1, si el identificador del curso no 
      es valido devuelve un -2, si el usuario u ya estaba inscrito en un curso devuelve un -3,
      de lo contrario se añade al usuario u al curso con indentificador i e imprime el numero 
      de inscritos despuesd de añadir a u
      */
      int inscribir_curso(int i,string u,Cjt_Sesiones& S,Cjt_Usuarios& U);
      
      /** @brief Se realiza un envio de un usuario a un problema
      \pre Cierto
      \post Se actualizan las estadisticas del usuario u, y si r = 1, se actualiza los problemas resueltos y enviables del usuario 
      y comprueba si con ello ha completado el curso en el que estaba inscrito y tambien se añade el problema
      a los problemas resueltos por dicho usuario. En caso de que lo haya completado,
      el usuario deja de estar inscrito en el curso
      */
      void envio(const string& u,const string& p,int r,Cjt_Sesiones& S,Cjt_Usuarios& U,Cjt_Problemas& P);

      
      /** @brief Se crea un nuevo curso
      \pre Cierto
      \post Si hay interseccion de problemas en la sesiones del nuevo curso,devuelve un -1,
      si no se imprime el nuevo numero de cursos despues de añadir el nuevo curso al parametro implicito
      */
      int nuevo_curso(Cjt_Sesiones& S,bool& interseccio);
     
      
      //Lectura y escritura

      /** @brief Lectura de un conjunto de cursos
      \pre n > 0
      \post El parámetro implícito contiene el conjunto de cursos leídos del
      canal estándar de entrada
      */
      void leer_cursos(int n,Cjt_Sesiones& S);
      
      /** @brief Escritura de un conjunto de cursos
      \pre Cierto
      \post Los cursos son listados ordenados crecientemente por su nombre y mostrando,
       para cada usuario, cuántos envíos en total ha realizado, 
       cuántos problemas ha resuelto satisfactoria- mente, 
       cuántos problemas ha intentado resolver (al menos ha hecho un envío), 
       y el identificador del curso en el que está inscrito o un cero si no está inscrito en ninguno
      */
      void listar_cursos() const;
      
      /** @brief Lista un curso
      \pre n >= 0
      \post Si existe un curso en el conjunto de cursos del parametro implicito y si lo esta imprime sus caracterisitcas, si no 
      se imprime un mensaje de error
      */
      void escribir_curso(int n) const;
};
#endif