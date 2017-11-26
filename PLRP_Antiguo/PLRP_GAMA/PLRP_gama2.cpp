#include <stdlib.h>
#include <climits>
#include <vector>
#include <cmath>
#include <map>
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
	map<string,Vehiculo*> vehiculos;
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
		void set_Vehiculos(map<string,Vehiculo*> vehiculos){
			this->vehiculos = vehiculos;
		};
		void set_contV(int contV){
			this->contV = contV;
		};
		void set_costoAp(double costoAp){
			this->costoAp = costoAp;
		};
		//GETTERS
		map<string,Vehiculo*> getVehiculos(){
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
	map<string,Contenedor*> Contenedores;
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
		map<string,Contenedor*> get_Contenedores(){
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

double DistManhattan(double X1,double Y1,double X2,double Y2){
	
	return abs(X1-Y1)+abs(X2-Y2);
	
}

double DistEuclidian(double X1, double Y1,double X2, double Y2){
	
	return sqrt(pow((X2-X1),2)+pow((Y2-Y1),2));
}

void Asignar_Costos(map<string,map<string,double> > &costos, map<string,Deposito*> depositos, map<string,Contenedor*> contenedores){
		
		double DX1,DY1,DX2,DY2,CX1,CY1,CX2,CY2,cost;
		map<string,Deposito*>::iterator map_D;
		map<string,Contenedor*>::iterator map_C;
		map<string,Contenedor*>::iterator map_C2;
		//DEPOSITOS
		for(map_D=depositos.begin();map_D!=depositos.end();map_D++){
			costos[map_D->second->get_Id()];
			//data << map_D->second->get_Id() << ": " << "\n";
			for(map_C=contenedores.begin();map_C!=contenedores.end();map_C++){
				DX1 = map_D->second->get_CoordanateX(); 
				DY1 = map_D->second->get_CoordanateY();
				CX2 = map_C->second->get_CoordanateX();
				CY2 = map_C->second->get_CoordanateY();
				cost = DistEuclidian(DX1,DY1,CX2,CY2);
				costos[map_D->second->get_Id()][map_C->second->get_Id()] = cost;
				//data << "\t" << map_C->second->get_Id() << "-" << cost << "\n";
				
			} 
		}
		//CONTENEDORES a CONTENEDORES
		for(map_C=contenedores.begin();map_C!=contenedores.end();map_C++){
			costos[map_C->first];
			//data << map_C->first << ": " << "\n" ;
			for(map_C2=contenedores.begin();map_C2!=contenedores.end();map_C2++){
				string C1 = map_C->second->get_Tipo();
				string C2 = map_C2->second->get_Tipo();
				if(C1==C2){
					//////cout << C1 << " " << C2 << endl;
					CX1 = map_C->second->get_CoordanateX();
					CY1 = map_C->second->get_CoordanateY();
					CX2 = map_C2->second->get_CoordanateX();
					CY2 = map_C2->second->get_CoordanateY();
					cost = DistEuclidian(CX1,CY1,CX2,CY2);
					costos[map_C->first][map_C2->second->get_Id()] = cost;
					//data << map_C2->second->get_Id() << "-" << cost << "\n";
				}
				
			}
			//CONTENEDORES a DEPOSITOS
			for(map_D=depositos.begin();map_D!=depositos.end();map_D++){
				CX1 = map_C->second->get_CoordanateX();
				CY1 = map_C->second->get_CoordanateY();
				DX2 = map_D->second->get_CoordanateX();
				DY2 = map_D->second->get_CoordanateY();
				cost = DistEuclidian(CX1,CY1,DX2,DY2);
				costos[map_C->first][map_D->second->get_Id()]=cost;
				//data << map_D->second->get_Id() << "-" << cost << "\n";
			}
		}
}

void PrintMap2(map<string,Contenedor*> mapa){
	
	map<string,Contenedor*>::iterator map_it;
	
	for(map_it=mapa.begin();map_it!=mapa.end();map_it++){
		////cout << map_it->first << " " << map_it->second->get_Id() << endl;
	}
	
}

void PrintMap(map<string,map<string,double> > mapa){
	
	map <string,map<string,double> >::iterator map_it;
	map<string,double>::iterator map2_it;
	
	for(map_it=mapa.begin();map_it!=mapa.end();map_it++){
		if(map_it->first[0]=='C'){
			////cout << "Nodo: " << map_it->first << endl;
			if(map_it->first=="C80"){
				////cout << map_it->second.size() << endl;
				//sleep(2);
			}
			for(map2_it=map_it->second.begin();map2_it!=map_it->second.end();map2_it++){
				////cout << "\t" << map2_it->first << " " << map2_it->second << endl;
			}
		}
	}
}



map<string,double> BuscarContContMasCercano_True(map<string,map<string,double> > Costos,map<string,Contenedor*> contenedor,
												string id){
	
	map<string,double>::iterator map_costos;
	
	map<string,double> map_func;
	
	string idT;
	double costo=DBL_MAX;
	
	for(map_costos=Costos[id].begin();map_costos!=Costos[id].end();map_costos++){
		if(map_costos->first[0]=='C' && map_costos->second < costo && contenedor[map_costos->first]->get_link()==true){
			idT = map_costos->first;
			costo = map_costos->second;
		}
	}
	
	map_func[idT] = costo;
	
	return map_func;
}

map<string,double> BuscarContContMasCercano_False(map<string,map<string,double> > Costos,map<string,Contenedor*> contenedor,
                                                  string id,double delimiter,string dia){
	
	map<string,double>::iterator map_costos;
	
	map<string,double> map_func;
	
	string idT;
	double costo=DBL_MAX;
	
	for(map_costos=Costos[id].begin();map_costos!=Costos[id].end();map_costos++){
		if(map_costos->first[0]=='C' && map_costos->second < costo && contenedor[map_costos->first]->get_link()==false
		&& (contenedor[map_costos->first]->get_capacity(dia)/contenedor[map_costos->first]->get_maxcapacity())*100 > delimiter){
			idT = map_costos->first;
			costo = map_costos->second;
		}
	}
	
	map_func[idT] = costo;
	
	return map_func;
}

map<string,double> BuscarContDeptMasCercano_Cont(map<string,map<string,double> > Costos, string id){
	
	map<string,double>::iterator map_cost;
	map<string,double> mapa;
	
	string id_CT,id_DT;
	double costo = DBL_MAX;
	
	for(map_cost=Costos[id].begin();map_cost!=Costos[id].end();map_cost++){
		if(map_cost->first[0]=='D' && map_cost->second < costo){
			//////cout << map_cont->first << " " << map_costos->first[0] << " " << map_costos->second << endl;
			id_DT = map_cost->first;
			costo = map_cost->second;
		}
	}
	
	mapa[id_DT] = costo;
	
	return mapa;
													
}

vector<string> BuscarContDeptMasCercano_Global(map<string,map<string,double> > Costos,map<string,Contenedor*> contenedores,
                                               string dia,double delimiter){
	
	double costo=INT_MAX;
	string id_CT,id_DT;
	map<string,Contenedor*>::iterator map_cont;
	map<string,double>::iterator map_costos;
	
	vector<string> vect;
	
	//BUSCAR EL CONTENEDOR CON EL DEPOSITO MAS CERCANO
	for(map_cont=contenedores.begin();map_cont!=contenedores.end();map_cont++){
		double uso = (map_cont->second->get_capacity(dia)/map_cont->second->get_maxcapacity())*100;
		if(uso>delimiter){
			for(map_costos=Costos[map_cont->first].begin();map_costos!=Costos[map_cont->first].end();map_costos++){
			
				if(map_costos->first[0]=='D' && map_costos->second < costo){
					//////cout << map_cont->first << " " << map_costos->first[0] << " " << map_costos->second << endl;
					id_CT = map_cont->first;
					id_DT = map_costos->first;
					costo = map_costos->second;
				}
			}
		}		
	}
	
	vect.push_back(id_CT);
	vect.push_back(id_DT);
	
	return vect;
}

void CrearRuta(Ruta *R,map<string,map<string,double> > Costos,map<string,Deposito*> &depositos,map<string,Contenedor*> &Cont,
			   map<string,Ruta*> &Ruta_C,map<string,string> &Rutas,int &contId,string dia,string idC1,string idD){
				   
	R->set_Id("R"+to_string(contId));//Set Id de Ruta
	contId = contId + 1;//AUmentar el contador de Id
	R->set_Deposito(depositos[idD]);//Set el deposito de la ruta
	R->set_Vehiculo(depositos[idD]->get_Vehiculo(idD+"_V"+to_string(depositos[idD]->get_contV())));//
	depositos[idD]->set_contV(depositos[idD]->get_contV() + 1);
	R->set_Contenedor(idC1,Cont[idC1]);
	R->get_Vehiculo()->set_capacity(Cont[idC1]->get_capacity(dia));
	R->set_Costos(Costos[idC1][idD]);
	Cont[idC1]->set_Ruta(R);
	Cont[idC1]->set_Link(true);
	Rutas[R->get_Id()]=idC1;
	Ruta_C[R->get_Id()]=R;
}

void AsignarRuta(map<string,map<string,double> > Costos,map<string,Contenedor*> &Cont,
				string dia,string idC1,string idC2,double capV){
	
	Cont[idC2]->get_Ruta()->get_Vehiculo()->set_capacity(capV+Cont[idC1]->get_capacity(dia));//aumentar capacidad del vehiculo
	Cont[idC2]->get_Ruta()->set_Contenedor(idC1,Cont[idC1]);//asiganar el contenedor idC1 a la ruta de idC2
	Cont[idC1]->set_Ruta(Cont[idC2]->get_Ruta());//asignar la ruta a idC1
	Cont[idC1]->set_Link(true);//cambiar de disponible a ocupado
	Cont[idC2]->get_Ruta()->set_Costos(Cont[idC2]->get_Ruta()->get_Costos()+Costos[idC1][idC2]);//aumentar el costo total de la Ruta
}


void Ruta_Greedy(map<string,map<string,double> > Costos,map<string,Deposito*> &depositos,map<string,Contenedor*> &contenedores, 
				 map<string,Contenedor*> &Cont, map<string,Ruta*> &Ruta_C,string dia,double delimiter){
	
	string idC1,idC2;
	string idD;
	double costoC,costoD;
	map<string,string> Rutas;
	map<string,string> RutasT;
	map<string,Contenedor*> map_Cont;
	map<string,Ruta*>::iterator map_ruta;

	int contC = Cont.size();
	//RUTA_PILAS
	//Iniciar Ruta
	idC1 = BuscarContDeptMasCercano_Global(Costos,Cont,dia,delimiter)[0];//[0]=idC 
	idD = BuscarContDeptMasCercano_Global(Costos,Cont,dia,delimiter)[1];//[1]=idD 
	
	Cont[idC1]->set_Link(true);
	
	map<string,Contenedor*> m_cont;
	map<string,Contenedor*>::iterator map_cont2;
	
	for(map_cont2=Cont.begin();map_cont2!=Cont.end();map_cont2++){
		double cant = map_cont2->second->get_capacity(dia)/map_cont2->second->get_maxcapacity();
		if(cant*100<delimiter){
			contC = contC - 1;
		}
	}
	
	
	int contId = 1;
	string depot;
	double capV,maxCapV;
	Ruta *R = new Ruta;
	CrearRuta(R,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
	contC = contC - 1;
	
	while(contC!=0){
		if(contC!=1){
			idC1 = BuscarContContMasCercano_False(Costos,Cont,idC1,delimiter,dia).begin()->first;//Buscar el ID del contenedor NO linkeado mas cercano		
			costoD = BuscarContDeptMasCercano_Cont(Costos,idC1).begin()->second;// Buscar el costo del deposito NO linkeado mas cercano
			idD = BuscarContDeptMasCercano_Cont(Costos,idC1).begin()->first;//Buscar el deposito mas cercano
			idC2 = BuscarContContMasCercano_True(Costos,Cont,idC1).begin()->first;//Buscar el cont mas cercano a idC1
			costoC = BuscarContContMasCercano_True(Costos,Cont,idC1).begin()->second;//Costo del cont
		
			if(costoD<costoC){
				//CREAR RUTA
				Ruta *R1 = new Ruta;
				CrearRuta(R1,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
				contC = contC -1;
			}
			if(costoD>costoC){
				
				capV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_capacity();
				maxCapV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_MaxCapacity();
				
				if(capV+Cont[idC1]->get_capacity(dia)<=maxCapV){

					AsignarRuta(Costos,Cont,dia,idC1,idC2,capV);
					contC = contC -1;
				}
				else{

					Ruta *R1 = new Ruta;
					CrearRuta(R1,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
					contC = contC -1;
					}	
			}
		}
		else if(contC==1){
			idC2 = BuscarContContMasCercano_True(Costos,Cont,idC1).begin()->first;//Buscar el cont mas cercano a idC1
			costoC = BuscarContContMasCercano_True(Costos,Cont,idC1).begin()->second;//Buscar el cont mas cercano a idC1
			idD = BuscarContDeptMasCercano_Cont(Costos,idC1).begin()->first;//Buscar el deposito mas cercano
			costoD = BuscarContDeptMasCercano_Cont(Costos,idC1).begin()->second;//Buscar el deposito mas cercano
			
			if(costoD<costoC){
				//CREAR RUTA
				Ruta *R1 = new Ruta;
				CrearRuta(R1,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
				contC = contC -1;		
			}
			if(costoD>costoC){
				
				capV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_capacity();
				maxCapV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_MaxCapacity();
				if(capV+Cont[idC1]->get_capacity(dia)<=maxCapV){
					AsignarRuta(Costos,Cont,dia,idC1,idC2,capV);
					contC = contC -1;
				}
				else{
					Ruta *R1 = new Ruta;
					CrearRuta(R1,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
					contC = contC -1;
					
				}	
			}
			
		}
		
	}
	
	
		
}

void Reboot(map<string,Contenedor*> &Cont,map<string,Deposito*> &Dept){
	
	map<string,Contenedor*>::iterator map_c;
	map<string,Deposito*>::iterator map_d;
	
	for(map_c=Cont.begin();map_c!=Cont.end();map_c++){
		
		map_c->second->set_Link(false);
	}
	
	for(map_d=Dept.begin();map_d!=Dept.end();map_d++){
		
		map_d->second->set_contV(1);
	}
}


double PrintRuta(map<string,Ruta*> Rut,ofstream& data,int tipo_ruta){
	
	map<string,Ruta*>::iterator map_rut;
	map<string,Contenedor*>::iterator map_cont;
	
	double cont = 0;
	for(map_rut=Rut.begin();map_rut!=Rut.end();map_rut++){
		cout << map_rut->first <<": "<<"\t" << endl;
		data << map_rut->first <<": "<<"\t" << "\n";
		cont =  tipo_ruta*map_rut->second->get_Costos() + cont;
		//cout << map_rut->second->get_Contenedores().size() << endl;
		for(map_cont=map_rut->second->get_Contenedores().begin();map_cont!=map_rut->second->get_Contenedores().end();map_cont++){
			
			cout << "\t"  << map_cont->second->get_Id() << endl;
			data << "\t" << map_cont->second->get_Id() << "\n";
		}
	}
	return cont;
}


int main(int argc, char *argv[]){
	
	
	map<string,Vehiculo*>  Vehiculos;
	map<string,Deposito*> Depositos;
	
	map<string,Contenedor*> Contenedores;
	map<string,Contenedor*> Cont_Pilas;
	map<string,Contenedor*> Cont_Plastico;
	map<string,Contenedor*> Cont_Carton_papeles;
	map<string,Contenedor*> Cont_Vidrio;
	
	map<string,Ruta*> Ruta_Pilas;
	map<string,Ruta*> Ruta_Carton_papel;
	map<string,Ruta*> Ruta_Plastico;
	map<string,Ruta*> Ruta_Vidrio;
	
	map<string,map<string,double> > Costos;
	map<string,vector<double> > datosC;
	map<string,vector<double> > datosD;
	map<string,double> combu;
	
	map<string,vector<string> > dias_Cont; 
	
	
	
	
	ifstream  data("Entradas/datosC1.csv");//CONTENEDORES
	ifstream  data2("Entradas/datosD.csv");//DEPOSITOS
	
	if(data.fail()){
		////cout << "Error al abrir el archivo" << endl;
	}
	
	if(data2.fail()){
		////cout << "Error al abrir el archivo" << endl;
	}
	
	int col = 1;
	int contV=0;
	double costoAp,costoV;
	
	//leer Contenedores
    string line;
    while(std::getline(data,line))
    {
		
        stringstream  lineStream(line);
        string        cell;
        string idT;
        double CXT,CYT,MC;
        Contenedor *C = new Contenedor;
        while(std::getline(lineStream,cell,',')){
			if(cell!="id_C" && cell!="CX" && cell!="CY" && cell!="Tipo" && cell!="CapacidadM" && cell!="Dias" && 
			cell!="Capacidad_Actual" && cell!="Lunes" && cell!="Martes" && cell!="Miercoles" && cell!="Jueves"
			&& cell!= "Viernes" && cell!="Sabado" && cell!="Domingo" ){
			    switch(col){
				    case 1://ID
						C->set_ID("C"+cell);
						col = col + 1;
						//////cout << "C"+cell <<": ";
						break;
				    case 2://CX
						CXT = stod(cell);
						C->set_CoordanteX(CXT);
						col = col + 1;
						//////cout << CXT << " ";
						break;
				    case 3://CY	
						CYT = stod(cell);
						C->set_CoordanteY(CYT);
						col = col + 1;
						//////cout << CYT << " ";
						break;	
					case 4://TIPO
						C->set_Tipo(cell);
						col = col + 1;
						//////cout << C.get_Tipo() << " ";
						break;
					case 5://MAxC
						C->set_MaxCapacity(stod(cell));
						//////cout << cell << endl;
						col = col + 1;
						break;
					case 6://Lunes
						if(cell==""){
						//////cout << "blanco" << " ";
						}
						else{
							MC = stod(cell);
							combu["Lunes"]=MC;

						}
						col = col + 1;
						break;
					case 7://martes
						if(cell==""){
						//////cout << "blanco" << " ";
						}
						else{
							MC = stod(cell);
							combu["Martes"]=MC;

						}
						col = col + 1;
						break;
					case 8://miercoles
					if(cell==""){
						//////cout << "blanco" << " ";
						}
						else{
							MC = stod(cell);
							combu["Miercoles"]=MC;

						}
						col = col + 1;
						break;
					case 9://jueves
						if(cell==""){
						//////cout << "blanco" << " ";
						}
						else{
							MC = stod(cell);
							combu["Jueves"]=MC;

						}
						col = col + 1;
						break;
					case 10://viernes
						if(cell==""){
						//////cout << "blanco" << " ";
						}
						else{
							MC = stod(cell);
							combu["Viernes"]=MC;

						}
						col = col + 1;
						break;
					case 11://sabado
						if(cell==""){
						//////cout << "blanco" << " ";
						}
						else{
							MC = stod(cell);
							combu["Sabado"]=MC;

						}
						col = col + 1;
						break;
					case 12://domingo
						if(cell==""){
						//////cout << "blanco" << " ";
						}
						else{
							MC = stod(cell);
							combu["Domingo"]=MC;
						}
						break;
				}
						  
			}
		}
		//GUARDAR SEGUN TIPO
		idT = C->get_Tipo();
		C->set_Link(false);
		map<string,double>::iterator map_it;
		for(map_it=combu.begin();map_it!=combu.end();map_it++){
			C->set_Combj(map_it->first,map_it->second);
		}
		combu.clear();
		if(idT=="Pilas"){
			Cont_Pilas[C->get_Id()]=C;
		}
		else if(idT=="Plastico"){
			Cont_Plastico[C->get_Id()]=C;
		}
		else if(idT=="Carton y Papeles"){
			Cont_Carton_papeles[C->get_Id()]=C;
			////cout << C->get_Combj()["Jueves"] << endl;
			////sleep(1);	
		}
		else if(idT=="Vidrio"){
			Cont_Vidrio[C->get_Id()]=C;
		}
		//GUARDAR TODOS JUNTOS
		Contenedores[C->get_Id()]=C;
				
        col = 1;
        
    }
    
    Contenedores.erase(Contenedores.begin());
    col = 1;
    map<string,double>::iterator Conte;
    
    for(Conte=Cont_Pilas.begin()->second->get_Combj().begin();Conte!=Cont_Pilas.begin()->second->get_Combj().end();Conte++){
		dias_Cont[Conte->first].push_back("Pilas");
		//cout << "se registro: " << Conte->first << endl;
	}
	for(Conte=Cont_Vidrio.begin()->second->get_Combj().begin();Conte!=Cont_Vidrio.begin()->second->get_Combj().end();Conte++){
		dias_Cont[Conte->first].push_back("Vidrio");
		//cout << "se registro: " << Conte->first << endl;
	}
	for(Conte=Cont_Carton_papeles.begin()->second->get_Combj().begin();Conte!=Cont_Carton_papeles.begin()->second->get_Combj().end();Conte++){
		//cout << "se registro: " << Conte->first << endl;
		dias_Cont[Conte->first].push_back("Carton");
	}
	for(Conte=Cont_Plastico.begin()->second->get_Combj().begin();Conte!=Cont_Plastico.begin()->second->get_Combj().end();Conte++){
		dias_Cont[Conte->first].push_back("Plastico");
		//cout << "se registro: " << Conte->first << endl;
	}
    
    
    
    //DEPOSITOS
    while(std::getline(data2,line))
    {
		
        stringstream  lineStream(line);
        string        cell;
        string idT;
        double CXT,CYT;
        Deposito *D =new Deposito;
        while(std::getline(lineStream,cell,',')){
			if(cell!="id_D" && cell!="CX" && cell!="CY" && cell!="V" && cell!="CostoApertura" && cell!="CostoVehiculo"){
			    switch(col){
				    case 1://ID
						D->set_id("D"+cell);
						col = col + 1;
						//////cout << "D"+cell <<": ";
						break;
				    case 2://CX
						CXT = stod(cell);
						D->set_coordanateX(CXT);
						col = col + 1;
						//////cout << CXT << " ";
						break;
				    case 3://CY	
						CYT = stod(cell);
						D->set_coordanateY(CYT);
						col = col + 1;
						//////cout << CYT << endl;
						break;
					case 4://CostoApertura
						costoAp = stod(cell);
						D->set_costoAp(costoAp);
						col = col +1;
						break;
					case 5://costoVehiculo
						costoV = stod(cell);
						col = col + 1;
						break;	
					case 6://VEHICULOS
						contV = stoi(cell);
						for(int i = 1;i<contV+1;i++){
							Vehiculo *V = new Vehiculo;
							V->set_Id(D->get_Id()+"_V"+to_string(i));
							V->set_MaxCapacity(15000);
							V->set_capacity(0);
							V->set_costoUso(costoV);
							Vehiculos[V->get_Id()]=V;
							
						}
						break;

				}			  
			}
		}
		D->set_Vehiculos(Vehiculos);
		Vehiculos.clear();
		D->set_capacity(DBL_MAX);
		D->set_contV(1);
		Depositos[D->get_Id()]=D;  
        col = 1;
        
    }
    Depositos.erase(Depositos.begin());
    
	
	vector<string> dias;
	
	dias.push_back("Lunes");
	dias.push_back("Martes");
	dias.push_back("Miercoles");
	dias.push_back("Jueves");
	dias.push_back("Viernes");
	dias.push_back("Sabado");
	dias.push_back("Domingo");
	
	vector<string>::iterator vec_it;
	vector<string>::iterator vec_it2;
	map<string,vector<string> >::iterator map_dias;
	Asignar_Costos(Costos,Depositos,Contenedores);
	double cont;
	int start_s=clock();
	
	// the code you wish to time goes here

	//PrintMap2(Cont_Pilas);
	ofstream data4("Salidas/matriz_gama.txt",ofstream::trunc);
	
	for(vec_it=dias.begin();vec_it!=dias.end();vec_it++){
		for(vec_it2=dias_Cont[*vec_it].begin();vec_it2!=dias_Cont[*vec_it].end();vec_it2++){
			if(*vec_it2=="Pilas"){
				cout << "Rutas Pilas dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Pilas para el día "<<*vec_it << "\n";
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Pilas,Ruta_Pilas,*vec_it,20);
				cont = PrintRuta(Ruta_Pilas,data4,2) +  cont;
				Reboot(Cont_Pilas,Depositos);
				contV = Ruta_Pilas.size() +  contV;
				Ruta_Pilas.clear();
			}
			if(*vec_it2=="Carton"){
				cout << "Rutas Carton dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Cartones y Papeles para el día "<<*vec_it << "\n"; 
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Carton_papeles,Ruta_Carton_papel,*vec_it,20);
				cont = PrintRuta(Ruta_Carton_papel,data4,2) + cont ;
				contV = Ruta_Carton_papel.size() + contV;
				Reboot(Cont_Carton_papeles,Depositos);
				
				Ruta_Plastico.clear();
			}
			if(*vec_it2=="Plastico"){
				cout << "Rutas Plastico dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Plástico para el día "<<*vec_it << "\n"; 
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Plastico,Ruta_Plastico,*vec_it,20);
				cont = PrintRuta(Ruta_Plastico,data4,2) + cont ;
				Reboot(Cont_Plastico,Depositos);
				contV = Ruta_Plastico.size() + contV;
				Ruta_Plastico.clear();
			}
			if(*vec_it2=="Vidrio"){
				cout << "Rutas Vidrio dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Vidrio para el día "<<*vec_it << "\n"; 
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Vidrio,Ruta_Vidrio,*vec_it,20);
				cont = PrintRuta(Ruta_Vidrio,data4,2) + cont ;
				Reboot(Cont_Vidrio,Depositos);
				contV =  Ruta_Vidrio.size() + contV;
				Ruta_Vidrio.clear();
			}
		}
	}
	
	int stop_s=clock();
	cout << "Modo Alta Congestion" << endl;
	data4 << "Modo Alta Congestion" << "\n";
	cout << "Tiempo de la Simulacion: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) <<" segundos" << endl;
	data4 << "Tiempo de la Simulacion: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) <<" segundos" << "\n";
	cout << fixed;
 	cout << "Costo Total: " << cont+(contV*500) << endl;
 	data4 << fixed;
 	data4 << "Costo Total: "<< cont+(contV*500) << "\n";
	cout << "Vehiculos Involucrados: " << contV << endl;
	data4 << "Vehiculos Involucrados: " << contV << "\n";
}
