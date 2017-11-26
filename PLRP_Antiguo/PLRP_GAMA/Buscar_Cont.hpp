unordered_map<string,double> BuscarContContMasCercano_True2(unordered_map<string,unordered_map<string,double> > Costos,map<string,string> &Rutas,string idC1){
	
	map<string,string>::iterator map_R;
	unordered_map<string,double> mapa;
	string idT,RT;
	double costo = DBL_MAX;
	
	for(map_R=Rutas.begin();map_R!=Rutas.end();map_R++){
		if(Costos[idC1][map_R->second]<costo){
			RT = map_R->first;
			idT = map_R->second;
			costo = Costos[idC1][map_R->second];
		}
	}
	Rutas.erase(RT);
 	mapa[idT]=costo;
 	return mapa;
}

unordered_map<string,double> BuscarContContMasCercano_False(unordered_map<string,unordered_map<string,double> > Costos,unordered_map<string,Contenedor*> contenedor,
                                                  string id,string dia){
	
	unordered_map<string,double>::iterator map_costos;
	
	unordered_map<string,double> map_func;
	
	string idT;
	double costo=DBL_MAX;
	
	for(map_costos=Costos[id].begin();map_costos!=Costos[id].end();map_costos++){
		if(map_costos->first[0]=='C' && map_costos->second < costo && contenedor[map_costos->first]->get_link()==false){
			idT = map_costos->first;
			costo = map_costos->second;
		}
	}
	
	map_func[idT] = costo;
	
	return map_func;
}

pair<string,double> BuscarContDeptMasCercano_Cont(unordered_map<string,unordered_map<string,double> > Costos, string id){
	
	unordered_map<string,double>::iterator map_cost;
	
	string id_CT,id_DT;
	double costo = DBL_MAX;
	
	for(map_cost=Costos[id].begin();map_cost!=Costos[id].end();map_cost++){
		if(map_cost->first[0]=='D' && map_cost->second < costo){
			//////cout << map_cont->first << " " << map_costos->first[0] << " " << map_costos->second << endl;
			id_DT = map_cost->first;
			costo = map_cost->second;
		}
	}
	
	return {id_DT,costo};
													
}

pair<string,string> BuscarContDeptMasCercano_Global(unordered_map<string,unordered_map<string,double> > Costos,unordered_map<string,Contenedor*> contenedores,
                                               string dia,double delimiter){
	
	double costo=INT_MAX;
	string id_CT,id_DT;
	unordered_map<string,Contenedor*>::iterator map_cont;
	unordered_map<string,double>::iterator map_costos;
	
	
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
	

	
	return {id_CT,id_DT};
}
