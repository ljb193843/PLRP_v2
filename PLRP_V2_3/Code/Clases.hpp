#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <stdlib.h>
#include <string.h>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
#include <cfloat>


using namespace std;

typedef unordered_map<int,int> unmap_int;
typedef unordered_map<int,int>::iterator unmap_int_it;
typedef unordered_map<string,double> unmap_st_db;
typedef unordered_map<string,double>::iterator unmap_st_db_it;
typedef unordered_map<string,set<string> > unmap_set;
typedef unordered_map<string,set<string> >::iterator unmap_set_it;
typedef unordered_map<string,string> unmap_st_st;
typedef unordered_map<string,string>::iterator unmap_st_st_it;
typedef set<string> set_st;
typedef set<string>::iterator set_st_it;
typedef vector<string> vec_st;
typedef vector<string>::iterator vec_st_it;
typedef unordered_map<string,unordered_map<string,double> > unmap_st_unmap;
typedef unordered_map<string,unordered_map<string,double> >::iterator unmap_st_unmap_it;
typedef pair<double,double> Pdouble;
typedef unordered_map<string,Pdouble> unmap_st_Pdouble;
typedef unordered_map<string,Pdouble>::iterator unmap_st_Pdouble_it;

class Contenedor{
	string id;//ID DEL CONTENEDOR
	string tipo;//TIPO DEL CONTENEDOR
   double X,Y;//Ubicacion
   unmap_st_db demand;//DEMANDA POR DIA

public:
	//SETTERS
	void set_id(string id){
		this->id = id;
	};
	void set_tipo(string tipo){
		this->tipo = tipo;
	};
	void set_demand(unmap_st_db d){
		this->demand = d;
	};
   void set_X(double X){
      this->X = X;
   };
   void set_Y(double Y){
      this->Y = Y;
   };
	//GETTERS
	string get_id(){
		return this->id;
	};
	string get_tipo(){
		return this->tipo;
	};
	unmap_st_db get_demand(){
		return this->demand;
	};
   double get_X(){
      return this->X;
   };
   double get_Y(){
      return this->Y;
   }
};
typedef unordered_map<string,Contenedor*> unmap_C;
typedef unordered_map<string,Contenedor*>::iterator unmap_C_it;

class Vehiculo{

	string id;//IDENTIFICADOR
   unmap_st_Pdouble capacidad; //CAPACIDAD POR TIPO
	double costoUso;//COSTO DE USAR EL VEHICULO

	public:

			//SETTERS
			void set_id(string id){

				this->id = id;
			};
			void set_capacidad (string tipo,Pdouble oferta){

				this->capacidad[tipo] = oferta;
			};
			void set_costoUso(double costoUso){

				this->costoUso = costoUso;
			};
			//GETTERS
			string get_id(){

				return this->id;
			};
			Pdouble get_capacidad(string tipo){

				return this->capacidad[tipo];
			};
			double get_costoUso(){

				return this->costoUso;
			};

};

typedef unordered_map<string,Vehiculo*> unmap_V;
typedef unordered_map<string,Vehiculo*>::iterator unmap_V_it;

class Deposito{

		string id;//ID DEL DEPOSITO
		unmap_V vehiculos;//VEHICULOS
      double X,Y;//Ubicacion

	public:
		//SETTERS
		void set_id(string id){
			this->id = id;
		};
		void set_vehiculo(unmap_V v){

			this->vehiculos = v;
		};
      void set_X(double X){
         this->X = X;
      };
      void set_Y(double Y){
         this->Y = Y;
      };
		//GETTERS
		string get_id(){

			return this->id;
		};
		unmap_V get_vehiculos(){

			return this->vehiculos;
		};
      double get_X(){
         return this->X;
      };
      double get_Y(){
         return this->Y;
      };

};

typedef unordered_map<string,Deposito*> unmap_D;
typedef unordered_map<string,Deposito*>::iterator unmap_D_it;

class Ruta{

	string id;//IDENTIFICADOR
	Vehiculo* vehic;//VEHICULO ASOCIADO A LA RUTA
	Deposito* dept;//DEPOSTIO DE LA RUTA
	unmap_C contenedores;//CONTENEDORES DE LA RUTA
   int contV;//Contador de vehiculos usados

	public:
			//SETTERS
			void set_id(string id){
				this->id = id;
			};
			void set_vehiculo(Vehiculo* v){

				this->vehic = v;
			};
			void set_deposito(Deposito* d){

				this->dept = d;
			};
			void set_contenedor(unmap_C c){

				this->contenedores = c;
			};
         void set_contV(int contV){
            this->contV = contV;
         };
         //GETTERS
         string get_id(){

            return this->id;
         };
         Vehiculo* get_vehiculo(){

            return this->vehic;
         };
         Deposito* get_deposito(){

            return this->dept;
         };
         unmap_C get_contenedores(){

            return this->contenedores;
         };

};

typedef unordered_map<string,Ruta*> unmap_R;
typedef unordered_map<string,Ruta*>::iterator unmap_R_it;
