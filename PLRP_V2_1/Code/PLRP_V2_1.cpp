#include "Clases.hpp"
#include "Print_Functions.hpp"
#include "GML_generator.hpp"

int main(int argc, char *argv[]){


	ifstream conte(argv[1]);
	ifstream depto(argv[2]);

   ofstream GML(argv[3]);


   string lineC;
   string lineD;

   unmap_C Contenedores;
   unmap_C Cont_Pilas;
   unmap_C Cont_Vidrio;
   unmap_C Cont_Carton;
   unmap_C Cont_Plastico;
   unmap_D Depositos;
   unmap_R Rutas;
   unmap_R Ruta_Pilas;
   unmap_R Rutas_Vidrio;
   unmap_R Rutas_Carton;
   unmap_R Rutas_Plastico;

   unmap_set dias;

   vec_st dias_programados;
   dias_programados.push_back("Lunes");
   dias_programados.push_back("Martes");
   dias_programados.push_back("Miercoles");
   dias_programados.push_back("Jueves");
   dias_programados.push_back("Viernes");
   dias_programados.push_back("Sabado");
   dias_programados.push_back("Domingo");


   int contRow = 1;
   unmap_st_db map_C;


   //LECTURA CONTENEDORES
   while(getline(conte,lineC))
   {

      stringstream  lineStream(lineC);
      string cell;
      string id_C,type;//id, tipo
      double CX,CY,Cmax,demand;//X,Y,Cantidad maxima, demanda

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
                     dias["Lunes"].insert(type);
                  }
                  contCol = contCol + 1;
                  break;

               case 7:
                  if(cell==""){
                     //cout << "vacio" << endl;
                  }
                  else{
                     demand = stod(cell);
                     map_C["Martes"]=demand;
                     dias["Martes"].insert(type);
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
                     dias["Miercoles"].insert(type);
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
                     dias["Jueves"].insert(type);
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
                     dias["Viernes"].insert(type);
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
                     dias["Sabado"].insert(type);
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
                     dias["Domingo"].insert(type);
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
         C->set_X(CX);
         C->set_Y(CY);
         Contenedores[id_C] = C;
         if(type=="Plastico"){
            Cont_Plastico[id_C] = C;
         }
         else if(type=="Pilas"){
            Cont_Pilas[id_C] = C;
         }
         else if(type=="Carton y Papeles"){
            Cont_Carton[id_C] = C;
         }
         else if(type=="Vidrio"){
            Cont_Vidrio[id_C] = C;
         }
         map_C.clear();
      }
      contRow  = contRow + 1;


   }


   //LECTURA DEPOSITOS
   contRow = 1;
   while(getline(depto,lineD))
   {

      stringstream  lineStream(lineD);
      string cell;
      string id_D,type;//id, tipo
      unmap_V vehiculos;
      int contCol = 1;
      Deposito *D = new Deposito;
      double CX,CY,CA,CV,VS;//X,Y,Costo Apertura, Costo Vehiculo, Cantidad de Vehiculos

      while(getline(lineStream,cell,',')){

         if(contRow!=1){

            switch (contCol) {
               case 1:
                  id_D = "D"+cell;
                  D->set_id(id_D);
                  contCol = contCol + 1;
                  break;
               case 2:
                  CX = stod(cell);
                  D->set_X(CX);
                  contCol = contCol + 1;
                  break;
               case 3:
                  CY = stod(cell);
                  D->set_Y(CY);
                  contCol = contCol + 1;
                  break;
               case 4:
                  CA = stod(cell);
                  contCol = contCol + 1;
                  break;
               case 5:
                  CV = stod(cell);
                  contCol = contCol + 1;
                  break;
               case 6:
                  VS = stod(cell);
                  break;
            }
         }
      }

      if(contRow!=1){
         for(int i=1;i<(VS+1);i++){
            Vehiculo *V = new Vehiculo;
            string id_V = D->get_id()+"_V"+to_string(i);
            V->set_id(D->get_id()+"_V"+to_string(i));
            V->set_costoUso(CV);
            vehiculos[id_V]=V;
         }
         D->set_vehiculo(vehiculos);
         vehiculos.clear();
         Depositos[id_D] = D;
      }

      contRow = contRow + 1;

   }




   /*
   Print_Contenedores(Contenedores);

   Print_Depositos(Depositos);

   Generate_GML(Contenedores,Depositos,GML);

   Print_Dias(dias);
   */
   vec_st_it vec_it;

   for(vec_it=dias_programados.begin();vec_it!=dias_programados.end();vec_it++){

      string dia = *vec_it;

      cout << "Hoy se recoge : " << endl;
      set_st_it s_it;
      for(s_it=dias[dia].begin();s_it!=dias[dia].end();s_it++){
         cout << "\t" << *s_it << endl;
      }

   }


}
