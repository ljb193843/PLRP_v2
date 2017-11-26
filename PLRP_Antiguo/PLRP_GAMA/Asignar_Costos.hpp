void Asignar_Costos(unordered_map<string,unordered_map<string,double> > &costos, unordered_map<string,Deposito*> depositos, unordered_map<string,Contenedor*> contenedores){
		
		double DX1,DY1,DX2,DY2,CX1,CY1,CX2,CY2,cost;
		unordered_map<string,Deposito*>::iterator map_D;
		unordered_map<string,Contenedor*>::iterator map_C;
		unordered_map<string,Contenedor*>::iterator map_C2;
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
