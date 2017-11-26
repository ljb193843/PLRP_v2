void Ruta_Greedy(unordered_map<string,unordered_map<string,double> > Costos,unordered_map<string,Deposito*> &depositos,unordered_map<string,Contenedor*> &contenedores, 
				 unordered_map<string,Contenedor*> &Cont, unordered_map<string,Ruta*> &Ruta_C,string dia,double delimiter){
	
	string idC1,idC2;
	string idD;
	double costoC,costoD;
	map<string,string> Rutas;
	map<string,string> RutasT;
	unordered_map<string,double> map_t;

	int contC = Cont.size();
	cout << contC << endl;
	//RUTA_PILAS
	//Iniciar Ruta
	pair<string,string> CtDG = BuscarContDeptMasCercano_Global(Costos,Cont,dia,delimiter);
	idC1 = CtDG.first;
	idD = CtDG.second;
	
	
	unordered_map<string,Contenedor*> m_cont;
	unordered_map<string,Contenedor*>::iterator map_cont2;
	
	
	int contId = 1;
	int contE;
	int contR;
	string depot;
	double capV,maxCapV;
	Ruta *R = new Ruta;
	CrearRuta(R,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
	contC = contC - 1;
	
	
	while(contC!=0){
		RutasT = Rutas;
		contR = Rutas.size();
		contE = 0;
		if(contC!=1){
			pair<string,double> CtD;
			CtD = BuscarContDeptMasCercano_Cont(Costos,idC1);
			idC1 = BuscarContContMasCercano_False(Costos,Cont,idC1,dia).begin()->first;//Buscar el ID del contenedor NO linkeado mas cercano		
			costoD = CtD.second;
			idD = CtD.first;

			while(contE!=1 && contR!=0){	
				
				map_t = BuscarContContMasCercano_True2(Costos,RutasT,idC1);
				idC2 = map_t.begin()->first;//Buscar el cont mas cercano a idC1
				costoC = map_t.begin()->second;//Costo del cont
				capV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_capacity();
				maxCapV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_MaxCapacity();

				if(capV+Cont[idC1]->get_capacity(dia)<=maxCapV){

					AsignarRuta(Costos,Cont,Rutas,dia,idC1,idC2,capV);
					contC = contC -1;
					contE = 1;
				}
				else{
					contR = contR - 1;
				}
			}		
			if(contR==0){
				Ruta *R1 = new Ruta;
				CrearRuta(R1,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
				contC = contC -1;
			}
		}
		else if(contC==1){
			
			while(contE!=1 && contR!=0){
				pair<string,double> CtD;
				CtD = BuscarContDeptMasCercano_Cont(Costos,idC1);
				map_t = BuscarContContMasCercano_True2(Costos,RutasT,idC1);
				idC2 = map_t.begin()->first;//Buscar el cont mas cercano a idC1
				costoC = map_t.begin()->second;//Buscar el cont mas cercano a idC1
				idD = CtD.first;//Buscar el deposito mas cercano
				costoD = CtD.second;//Buscar el deposito mas cercano	
				capV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_capacity();
				maxCapV = Cont[idC2]->get_Ruta()->get_Vehiculo()->get_MaxCapacity();
				if(capV+Cont[idC1]->get_capacity(dia)<=maxCapV){
					AsignarRuta(Costos,Cont,Rutas,dia,idC1,idC2,capV);
					contC = contC -1;
					contE = 1;
				}
				else{
					contR = contR -1;
				
				}
			}	
			if(contR==0){
				Ruta *R1 = new Ruta;
				CrearRuta(R1,Costos,depositos,Cont,Ruta_C,Rutas,contId,dia,idC1,idD);
				contC = contC -1;
			}
			
		}
		
	}
		
}
