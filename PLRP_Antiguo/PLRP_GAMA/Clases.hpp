#include <stdlib.h>
#include <climits>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_map>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <cfloat>
#include <limits>
#include <ctime>
#include <chrono>

using namespace std;

class Ruta;

class Vehiculo{
	string id;
	double capacity;
	double MaxCapacity;
	double costoUso;
	public: 
		//SETTERS
		void set_Id(string id){
			this->id = id;
		};
		void set_capacity(double capacity){
			this->capacity = capacity;
		};
		void set_MaxCapacity(double MaxCapacity){
			this->MaxCapacity = MaxCapacity;
		};
		void set_costoUso(double costouso){
			this->costoUso = costouso;
		};
		//GETTERS
		string get_Id(){
			return this->id;
		};
		double get_capacity(){
			return this->capacity;
		};
		double get_MaxCapacity(){
			return this->MaxCapacity;
		};
		double get_costoUso(){
			return this->costoUso;
		};
};

class Contenedor{	
	string id;
	double MaxCapacity;
	double coordanateX;
	double coordanateY;
	bool Link;
	bool valido;
	string Tipo;
	Ruta *Rut;
	map<string,double> Combj;
	public:
		//SETTERS
		void set_ID(string ID){
			this->id = ID;
		};
		void set_MaxCapacity(double MaxCapacity){
			this->MaxCapacity = MaxCapacity;
		};
		void set_CoordanteX(double coordanateX){
			this->coordanateX = coordanateX;			
		};
		void set_CoordanteY(double coordanateY){
			this->coordanateY = coordanateY;
		};
		void set_Tipo(string tipo){
			this->Tipo = tipo;
		};
		void set_Combj(string dia,double cant){
			this->Combj[dia]=cant;
		};
		void set_Link(bool link){
			this->Link = link;
		};
		void set_Ruta(Ruta *Rut){
			this->Rut = Rut;
		};
		//GETTERS
		string get_Id(){
			return this->id;
		};
		double get_CoordanateX(){
			return this->coordanateX;
		};
		double get_CoordanateY(){
			return this->coordanateY;
		};
		string get_Tipo(){
			return this->Tipo;
		};
		double get_capacity(string id){
			return this->Combj[id];
		};
		double get_maxcapacity(){
			return this->MaxCapacity;
		};
		map<string,double> get_Combj(){
			return this->Combj;
		};
		bool get_link(){
			return this->Link;
		};
		Ruta *get_Ruta(){
			return this->Rut;
		};
}; 
		
class Deposito{
	string id;
	double capacity;
	double MaxCapacity;
	double coordanateX;
	double coordanateY;	
	double costoAp;
	unordered_map<string,Vehiculo*> vehiculos;
	int contV;
	public:
		//SETTERS
		void set_id(string id){
			this->id = id;
		};
		void set_capacity(double capacity){
			this->capacity = capacity;
		};
		void set_MaxCapacity(double MaxCapacity){
			this->MaxCapacity = MaxCapacity;
		};
		void set_coordanateX(double coordanateX){
			this->coordanateX = coordanateX;
		};
		void set_coordanateY(double coordanateY){
			this->coordanateY = coordanateY;
		};
		void set_Vehiculos(unordered_map<string,Vehiculo*> vehiculos){
			this->vehiculos = vehiculos;
		};
		void set_contV(int contV){
			this->contV = contV;
		};
		void set_costoAp(double costoAp){
			this->costoAp = costoAp;
		};
		//GETTERS
		unordered_map<string,Vehiculo*> getVehiculos(){
			return this->vehiculos;
		};
		Vehiculo* get_Vehiculo(string id){
			return this->vehiculos[id];
		};
		string get_Id(){
			return this->id;
		};
		double get_capacity(){
			return this->capacity;
		};
		double get_CoordanateX(){
			return this->coordanateX;
		};
		double get_CoordanateY(){
			return this->coordanateY;
		};
		int get_contV(){

			if(this->contV > this->vehiculos.size()){
				////cout << "no quedan vehiculos" << endl;
				
			}
			else{				
				return this->contV;
			}
		};
		double get_costoAp(){
			return this->costoAp;
		};
};

class Ruta{
	string id;
	unordered_map<string,Contenedor*> Contenedores;
	Deposito* Dept;
	double Costos;
	Vehiculo* Vehi;
	public:
		//SETTERS
		void set_Id(string id){
			this->id = id;
		};
	   void set_Contenedor(string id,Contenedor* &Cont){
			
			Cont->set_Link(true);
			this->Contenedores[id]=Cont;
		};
		void set_Deposito(Deposito* Dept){
			this->Dept = Dept;
		};
		void set_Costos(double Costos){
			this->Costos = Costos;
		};
		void set_Vehiculo(Vehiculo* V){
			this->Vehi = V;
		};
		//GETTERS
		string get_Id(){
			return this->id;
		};
		unordered_map<string,Contenedor*> get_Contenedores(){
			return this->Contenedores;
		};
		Deposito* get_Deposito(){
			return this->Dept;
		};
		double get_Costos(){
			return this->Costos;
		};
		Vehiculo* get_Vehiculo(){
			return this->Vehi;
		};

		
};
