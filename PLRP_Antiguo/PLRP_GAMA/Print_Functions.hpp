void PrintMap2(unordered_map<string,Contenedor*> mapa){
	
	unordered_map<string,Contenedor*>::iterator map_it;
	
	for(map_it=mapa.begin();map_it!=mapa.end();map_it++){
		////cout << map_it->first << " " << map_it->second->get_Id() << endl;
	}
	
}

void PrintMap(unordered_map<string,unordered_map<string,double> > mapa){
	
	unordered_map<string,unordered_map<string,double> >::iterator map_it;
	unordered_map<string,double>::iterator map2_it;
	
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

double PrintRuta(unordered_map<string,Ruta*> Rut,ofstream& data,int tipo_ruta,unordered_map<string,unordered_map<string,double> >Costos,int &contV){
	
	unordered_map<string,Ruta*>::iterator map_rut;
	unordered_map<string,Contenedor*>::iterator map_cont;
	unordered_map<string,Contenedor*> c_t;
	Deposito* Depot;
	string idCF;
	
	double cont = 0;
	for(map_rut=Rut.begin();map_rut!=Rut.end();map_rut++){
		cout << map_rut->first <<": "<<"\t" << endl;
		data << map_rut->first <<": "<<"\t" << "\n";
		Depot = map_rut->second->get_Deposito();
		cont =  map_rut->second->get_Costos()+ map_rut->second->get_Deposito()->get_costoAp() + cont;
		contV = contV + 1;
		//cout << map_rut->second->get_Contenedores().size() << endl;
		c_t = map_rut->second->get_Contenedores();
		for(map_cont=c_t.begin();map_cont!=c_t.end();map_cont++){
			idCF = map_cont->second->get_Id();
			cout << "\t"  << map_cont->second->get_Id() << endl;
			data << "\t" << map_cont->second->get_Id() << "\n";
		}
		cont = cont + tipo_ruta*Costos[idCF][Depot->get_Id()];
	}
	
	return cont;
}
