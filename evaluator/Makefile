OPCIONES = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Usuario.o Cjt_Usuarios.o Sesion.o Cjt_Sesiones.o Problema.o Cjt_Problemas.o Curso.o Cjt_Cursos.o 
	g++ -o program.exe program.o Usuario.o Cjt_Usuarios.o Sesion.o Cjt_Sesiones.o Problema.o Cjt_Problemas.o Curso.o Cjt_Cursos.o 
	rm *.o

Usuario.o: Usuario.cc Usuario.hh 
	g++ -c Usuario.cc $(OPCIONES) 

Cjt_Usuarios.o: Cjt_Usuarios.cc Cjt_Usuarios.hh Usuario.hh  
	g++ -c Cjt_Usuarios.cc $(OPCIONES)

Sesion.o: Sesion.cc Sesion.hh Cjt_Usuarios.hh BinTree.hh 
	g++ -c Sesion.cc $(OPCIONES)
  
Cjt_Sesiones.o: Cjt_Sesiones.cc Cjt_Sesiones.hh Sesion.hh 
	g++ -c Cjt_Sesiones.cc $(OPCIONES)
	
Problema.o: Problema.cc Problema.hh 
	g++ -c Problema.cc $(OPCIONES)

Cjt_Problemas.o: Cjt_Problemas.cc Cjt_Problemas.hh Problema.hh 
	g++ -c Cjt_Problemas.cc $(OPCIONES)
  
Curso.o: Curso.cc Curso.hh Cjt_Sesiones.hh 
	g++ -c Curso.cc $(OPCIONES)
  
Cjt_Cursos.o: Cjt_Cursos.cc Cjt_Cursos.hh Curso.hh Cjt_Problemas.hh 
	g++ -c Cjt_Cursos.cc $(OPCIONES)

program.o: program.cc  Cjt_Usuarios.hh Cjt_Sesiones.hh Cjt_Problemas.hh Cjt_Cursos.hh
	g++ -c program.cc $(OPCIONES)

clean:
	rm  *.o
	rm  *.exe

tar: 
	tar -cvf practica.tar *.hh *.cc Makefile html.zip jp_fujie_mei.zip


