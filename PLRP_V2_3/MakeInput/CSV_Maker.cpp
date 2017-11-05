#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <vector>
#include <map>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]){

   ofstream  file(argv[2]);

   file << "id_C;" << "Tipo;" << "CX;" << "CY;" << "Lunes;" << "Martes;" << "Miercoles;"
   "Jueves;" << "Viernes;" << "Sabado;" << "Domingo" << "\n";


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

   map<string,set<string> > cont_dias;


   vector<string>::iterator v_it;
   for(v_it=contenedores.begin();v_it!=contenedores.end();v_it++){

      int cant_dias = rand ()% dias.size()+1;

      cout << *v_it << ": " << cant_dias << endl;

      c_d[*v_it] = cant_dias;

   }

   map<string,int>::iterator c_d_it;

   for(c_d_it=c_d.begin();c_d_it!=c_d.end();c_d_it++){

      string cont = c_d_it->first;
      int diaC = c_d_it->second;

      while (cont_dias[cont].size()<diaC) {

         int diaR = rand()% dias.size();

         cont_dias[cont].insert(dias[diaR]);

         //cout << "Se inserto en "+cont+" el dia "+dias[diaR] << endl;


      }

   }

   vector<int> c_dias;


   int iter = stoi(argv[1]);

   cout << iter << endl;

   for(int i=1; i<iter+1; i++){

      for(int j=0;j<7;j++){
         c_dias.push_back(0);
      }

      file << i << ";";

      int CX = rand()%10000+1000;
      int CY = rand()%10000+1000;

      string contR = contenedores[rand()% contenedores.size()];

      file << contR << ";";

      cout << contR << endl;

      file << CX << ";" << CY << ";";

      set<string>::iterator set_it;

      for(set_it=cont_dias[contR].begin();set_it!=cont_dias[contR].end();set_it++){

         if(*set_it=="Lunes"){
            cout << "Lunes" << endl;
            c_dias[0] = 1;
         }
         else if(*set_it=="Martes"){

            cout << "Martes" << endl;
            c_dias[1] = 1;
         }
         else if(*set_it=="Miercoles"){
            cout << "Miercoles" << endl;
            c_dias[2] = 1;
         }
         else if(*set_it=="Jueves"){
            cout << "Jueves" << endl;
            c_dias[3] = 1;
         }
         else if(*set_it=="Viernes"){
            cout << "Viernes" << endl;
            c_dias[4] = 1;
         }
         else if(*set_it=="Sabado"){
            cout << "Sabado" << endl;
            c_dias[5] = 1;
         }
         else if(*set_it=="Domingo"){
            cout << "Domingo" << endl;
            c_dias[6] = 1;
         }

      }

      for(int i=0;i<c_dias.size();i++){
         if(c_dias[i]==1){
            int ofertaR = rand()%5000+100;
            file << ofertaR << ";";
         }
         else{
            file << ";";
         }
      }

      c_dias.clear();

      file << "\n";

   }

   sleep(2);

   file.close();

}
