#include "Clases.hpp"
#include "Distancias.hpp"
#include "Print_Functions.hpp"
#include "Asignar_Costos.hpp"
#include "Buscar_Cont.hpp"
#include "Crear_Ruta.hpp"
#include "Ruta_Greedy.hpp"




void Reboot(unordered_map<string,Contenedor*> &Cont,unordered_map<string,Deposito*> &Dept){
	
	unordered_map<string,Contenedor*>::iterator map_c;
	unordered_map<string,Deposito*>::iterator map_d;
	
	for(map_c=Cont.begin();map_c!=Cont.end();map_c++){
		
		map_c->second->set_Link(false);
	}
	
	for(map_d=Dept.begin();map_d!=Dept.end();map_d++){
		
		map_d->second->set_contV(1);
	}
}





int main(int argc, char *argv[]){
	
	
	unordered_map<string,Vehiculo*>  Vehiculos;
	unordered_map<string,Deposito*> Depositos;
	
	unordered_map<string,Contenedor*> Contenedores;
	unordered_map<string,Contenedor*> Cont_Pilas;
	unordered_map<string,Contenedor*> Cont_Plastico;
	unordered_map<string,Contenedor*> Cont_Carton_papeles;
	unordered_map<string,Contenedor*> Cont_Vidrio;
	
	unordered_map<string,Ruta*> Ruta_Pilas;
	unordered_map<string,Ruta*> Ruta_Carton_papel;
	unordered_map<string,Ruta*> Ruta_Plastico;
	unordered_map<string,Ruta*> Ruta_Vidrio;
	unordered_map<string,unordered_map<string,Ruta*> >Rutas;
	
	unordered_map<string,unordered_map<string,double> > Costos;
	map<string,vector<double> > datosC;
	map<string,vector<double> > datosD;
	map<string,double> combu;
	
	map<string,vector<string> > dias_Cont; 
	
	
	
	
	ifstream  data(argv[1]);//CONTENEDORES
	ifstream  data2(argv[2]);//DEPOSITOS
	
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
	ofstream data4(argv[3]);
	int contV2 = 0;
	for(vec_it=dias.begin();vec_it!=dias.end();vec_it++){
		for(vec_it2=dias_Cont[*vec_it].begin();vec_it2!=dias_Cont[*vec_it].end();vec_it2++){
			if(*vec_it2=="Pilas"){
				cout << "Rutas Pilas dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Pilas para el día "<<*vec_it << "\n";
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Pilas,Ruta_Pilas,*vec_it,20);
				Rutas[*vec_it]=Ruta_Pilas;
				cont = PrintRuta(Ruta_Pilas,data4,2,Costos,contV2) +  cont;
				Reboot(Cont_Pilas,Depositos);
				//contV = Ruta_Pilas.size() +  contV;
				Ruta_Pilas.clear();
			}
			if(*vec_it2=="Carton"){
				cout << "Rutas Carton dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Cartones y Papeles para el día "<<*vec_it << "\n"; 
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Carton_papeles,Ruta_Carton_papel,*vec_it,20);
				Rutas[*vec_it]=Ruta_Carton_papel;
				cont = PrintRuta(Ruta_Carton_papel,data4,2,Costos,contV2) + cont ;
				//contV = Ruta_Carton_papel.size() + contV;
				Reboot(Cont_Carton_papeles,Depositos);
				
				Ruta_Plastico.clear();
			}
			if(*vec_it2=="Plastico"){
				cout << "Rutas Plastico dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Plástico para el día "<<*vec_it << "\n"; 
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Plastico,Ruta_Plastico,*vec_it,20);
				Rutas[*vec_it]=Ruta_Plastico;
				cont = PrintRuta(Ruta_Plastico,data4,2,Costos,contV2) + cont ;
				Reboot(Cont_Plastico,Depositos);
				//contV = Ruta_Plastico.size() + contV;
				Ruta_Plastico.clear();
			}
			if(*vec_it2=="Vidrio"){
				cout << "Rutas Vidrio dia " << *vec_it << endl;
				data4 << "Rutas de Contenedores de Vidrio para el día "<<*vec_it << "\n"; 
				Ruta_Greedy(Costos,Depositos,Contenedores,Cont_Vidrio,Ruta_Vidrio,*vec_it,20);
				Rutas[*vec_it]=Ruta_Vidrio;
				cont = PrintRuta(Ruta_Vidrio,data4,2,Costos,contV2) + cont ;
				Reboot(Cont_Vidrio,Depositos);
				//contV =  Ruta_Vidrio.size() + contV;
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
 	cout << "Costo Total: " << cont+(contV2*500) << endl;
 	data4 << fixed;
 	data4 << "Costo Total: "<< cont+(contV2*500) << "\n";
	cout << "Vehiculos Involucrados: " << contV2 << endl;
	data4 << "Vehiculos Involucrados: " << contV2 << "\n";
}
