#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]){


   vector<string> dias;
   vector<string> contenedores;

   map<string,int> c_d;

   dias.push_back("Lunes");
   dias.push_back("Martes");
   dias.push_back("Miercoles");
   dias.push_back("Jueves");
   dias.push_back("Viernes");
   dias.push_back("Sabado");
   dias.push_back("Domingo");

   srand(time(NULL));

   contenedores.push_back("Pilas");
   contenedores.push_back("Carton");
   contenedores.push_back("Plastico");
   contenedores.push_back("Vidiro");
   contenedores.push_back("RAEE");

   set<string> pilas;
   set<string> carton;
   set<string> plastico;
   set<string> vidrio;
   set<string> raee;


   vector<string>::iterator v_it;
   for(v_it=contenedores.begin();v_it!=contenedores.end();v_it++){

      int cant_dias = rand ()% dias.size();

      cout << *v_it << ": " << cant_dias << endl;

      c_d[*v_it] = cant_dias;
   }


   


}
