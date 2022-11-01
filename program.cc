/** @mainpage Práctica de PRO2 (Primavera 2021): Evaluator. Documentación

    El programa principal se encuentra en el módulo program.cc. 
    Atendiendo a los tipos de datos sugeridos en el enunciado para cada módulo
    tendremos un conjunto de este tipo a asociados a sus respectivos módulos. Estos módulos y sus asociaciones
    son las siguientes: a Usuario se le asocia Cjt_Usuarios los cuales representan cada usuario y sus atributos;
    a Problema se le asocia Cjt_Problemas los cuales representan cada usuario y sus atributos, a Sesion se le asocia 
    Cjt_Sesiones los cuales representan cada sesion y sus atributos y finalmente a Curso se le asocia Cjt_Cursos los cuales representan 
    cada curso y sus atributos.    
*/

/** @file program.cc

    @brief Programa principal

    Estamos suponiendo que todos los datos de entrada cumplen el formato decidido
    en el enunciado de la práctica y, por lo tanto, son válidos, por lo que no se
    hace ninguna comprobación sobre estos.

*/
#include "Cjt_Usuarios.hh"
#include "Cjt_Cursos.hh"
#include "Cjt_Sesiones.hh"
#include "Cjt_Problemas.hh"


int main() {
    int P,Q,N,M;
    cin >> P;
    Cjt_Problemas problemas;
    problemas.leer_cjt_problemas(P);
    cin >> Q;
    Cjt_Sesiones Sesiones;
    Sesiones.leer_cjt_sesiones(Q);
    cin >> N;
    Cjt_Cursos Cursos;
    Cursos.leer_cursos(N,Sesiones);
    cin >> M;
    Cjt_Usuarios Usuarios;
    Usuarios.leer_cjt_usuario(M);
    string command;
    cin >> command;
    while (command != "fin") {
        if (command == "nuevo_problema" or command == "np") {
            string p;
            cin >> p;
            cout << "#" << command << " ";
            cout << p << endl;
            int c = problemas.nuevo_problema(p);
            if (c == -1) cout << "error: el problema ya existe" << endl;
            else cout << c << endl;
        }
        else if (command == "nueva_sesion" or command == "ns") {
            string s;
            cin >> s;
            int c = Sesiones.nueva_sesion(s);
            cout << "#" << command << " ";
            cout << s << endl; 
            if (c == -1) cout << "error: la sesion ya existe" << endl;
            else cout << c << endl;
        }
        else if (command == "nuevo_curso" or command == "nc") {
            bool interseccio;
            cout << "#" << command << endl;
            int i = Cursos.nuevo_curso(Sesiones,interseccio);
            if (i == -1) cout << "error: curso mal formado" << endl;
            else cout << i << endl;
        }
        else if (command == "baja_usuario" or command == "b") {
            string u;
            cin >> u;
            cout << "#" << command << " ";
            cout << u << endl;
            int x;
            int c = Usuarios.baja_usuario(u,x);
            if (c == -1)  cout << "error: el usuario no existe" << endl;
            else {
                cout << c << endl;
                //Si el usuario estaba inscrito en algun curso modificamos el numero
                //de inscritos de ese curso
                if (x != 0) {
                  int n = Cursos.consultar_inscripciones(x);
                  Cursos.modf_num_insc(x,n-1);
                }
            }
        }
        else if (command == "alta_usuario" or command == "a") {
            string u;
            cin >> u;
            cout << "#" << command << " ";
            cout << u << endl;
            int c = Usuarios.alta_usuario(u);
            if (c == -1) cout << "error: el usuario ya existe" << endl;
            else cout << c << endl;
        }
        else if (command == "inscribir_curso" or command == "i") {
            string u;
            cin >> u;
            int c;
            cin >> c;
            cout << "#" << command << " ";
            cout << u << " " << c << endl;
            int n = Cursos.inscribir_curso(c,u,Sesiones,Usuarios);
            if (n == -1) cout << "error: el usuario no existe" << endl;
            else if (n == -2) cout << "error: el curso no existe" << endl;
            else if (n == -3) cout << "error: usuario inscrito en otro curso" << endl;
            else cout << n << endl;
        }
        else if (command == "curso_usuario" or command == "cu") {
            string u;
            cin >> u;
            cout << "#" << command << " " << u << endl;
            int c = Usuarios.curso_usuario(u);
            if (c == -1) cout << "error: el usuario no existe" << endl;
            else cout << c << endl;
        }
        else if (command == "sesion_problema" or command == "sp") {
            int c;
            cin >> c;
            string p;
            cin >> p;
            cout << "#" << command << " ";
            cout << c << " " << p << endl;
            string s;
            Cursos.sesion_problema(c,p,problemas,s);
        }
        else if (command == "problemas_resueltos" or command == "pr") {
            string u;
            cin >> u;
            cout << "#" << command << " " <<  u <<endl;
            Usuarios.imprimir_problemas_resueltos(u);
        }
        else if (command == "problemas_enviables" or command == "pe") {
            string u;
            cin >> u;
            cout << "#" << command << " " << u << endl;
            Usuarios.imprimir_problemas_enviables(u);
        }
         else if (command == "envio" or command == "e") {
            string u,p;
            cin >> u >> p;
            int n;
            cin >> n;
            cout << "#" << command << " " << u << " " << p << " " << n << endl;
            Cursos.envio(u,p,n,Sesiones,Usuarios,problemas);
        }
        else if (command == "listar_problemas" or command == "lp") {
            cout << "#" << command << endl;
            problemas.listar_problemas();
        }
        else if (command == "escribir_problema" or command == "ep") { 
            string p;
            cin >> p;
            cout << "#" << command << " " << p << endl;
            problemas.escribir_problema(p);
        }
        else if (command == "listar_sesiones" or  command == "ls") {
            cout << "#" << command << endl;
            Sesiones.listar_sesiones();
        }
        else if (command == "escribir_sesion" or command == "es") {
            string s;
            cin >> s;
            cout << "#" << command << " " << s << endl;
            Sesiones.escribir_sesion(s);
        }
        else if (command == "listar_cursos" or command == "lc") {
            cout << "#" << command << endl;
            Cursos.listar_cursos();
        }
        else if (command == "escribir_curso" or command == "ec") {
            int c;
            cin >> c;
            cout << "#" << command << " " << c << endl;
            Cursos.escribir_curso(c);
        }
        else if (command == "listar_usuarios" or command == "lu") {
            cout << "#" << command << endl;
            Usuarios.listar_usuarios();
        }
        else if (command == "escribir_usuario" or command == "eu") {
            string u;
            cin >> u;
            cout << "#" << command << " " << u << endl;
            Usuarios.escribir_usuario(u);
        }
        cin >> command;
    }
}

