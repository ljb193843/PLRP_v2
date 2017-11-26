void CrearRuta(Ruta *R,unordered_map<string,unordered_map<string,double> > Costos,unordered_map<string,Deposito*> &depositos,unordered_map<string,Contenedor*> &Cont,
			   unordered_map<string,Ruta*> &Ruta_C,map<string,string> &Rutas,int &contId,string dia,string idC1,string idD){
				   
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

void AsignarRuta(unordered_map<string,unordered_map<string,double> > Costos,unordered_map<string,Contenedor*> &Cont,map<string,string> &Rutas,
				string dia,string idC1,string idC2,double capV){
	
	Cont[idC2]->get_Ruta()->get_Vehiculo()->set_capacity(capV+Cont[idC1]->get_capacity(dia));//aumentar capacidad del vehiculo
	Cont[idC2]->get_Ruta()->set_Contenedor(idC1,Cont[idC1]);//asiganar el contenedor idC1 a la ruta de idC2
	Cont[idC1]->set_Ruta(Cont[idC2]->get_Ruta());//asignar la ruta a idC1
	Cont[idC1]->set_Link(true);//cambiar de disponible a ocupado
	Cont[idC2]->get_Ruta()->set_Costos(Cont[idC2]->get_Ruta()->get_Costos()+Costos[idC1][idC2]);//aumentar el costo total de la Ruta
	Rutas[Cont[idC2]->get_Ruta()->get_Id()]=idC1;
}
