#include "Clases.hpp"
#include "Print_Functions.hpp"

int main(int argc, char *argv[]){


	ifstream conte(argv[1]);
	ifstream depto(argv[2]);


   string line;

   unmap_C Contenedores;
   unmap_R Rutas;
   unmap_R Ruta_Pilas;
   unmap_R Rutas_Vidrio;
   unmpa_R Rutas_Carton;
   unmap_R Rutas_Plastico;

   int contRow = 1;
   unmap_st_db map_C;

   while(getline(conte,line))
   {

      stringstream  lineStream(line);
      string cell;
      string id_C,type;
      double CX,CY,Cmax,demand;

      int contCol = 1;
      Contenedor *C = new Contenedor;
      while(getline(lineStream,cell,',')){

         if(contRow!=1){

            switch (contCol) {
               case 1:
                  id_C = "C"+cell;
                  contCol = contCol + 1;
                  break;

               case 2:
                  CX = stod(cell);
                  contCol = contCol + 1;
                  break;

               case 3:
                  CY = stod(cell);
                  contCol = contCol + 1;
                  break;

               case 4:
                  type = cell;
                  contCol = contCol + 1;
                  break;

               case 5:
                  Cmax = stod(cell);
                  contCol = contCol + 1;
                  break;

               case 6:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Lunes"]= demand;
                  }
                  contCol = contCol + 1;
                  break;

               case 7:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Martes"]= demand;
                  }
                  contCol = contCol + 1;
                  break;

               case 8:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Miercoles"]= demand;
                  }
                  contCol = contCol + 1;
                  break;

               case 9:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Jueves"]= demand;
                  }
                  contCol = contCol + 1;
                  break;

               case 10:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Viernes"]= demand;
                  }
                  contCol = contCol + 1;
                  break;

               case 11:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Sabado"]= demand;
                  }
                  contCol = contCol + 1;
                  break;
               case 12:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Domingo"]= demand;
                  }
                  contCol = contCol + 1;
                  break;

            }
         }
      }
      if(contRow!=1){
         C->set_id(id_C);
         C->set_tipo(type);
         C->set_demand(map_C);
         Contenedores[id_C] = C;
         map_C.clear();
      }
      contRow  = contRow + 1;


   }

   /*Print_Contenedores(Contenedores);
   cout << "Filas: " << contRow << endl;
   cout << "Contenedores: " << Contenedores.size() << endl;
   */


}
