#include <stdlib.h>
#include <climits>
#include <vector>
#include <cmath>
#include <map>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]){
	
	vector<string> TipoContenedor;
	TipoContenedor.push_back("Pilas");
	TipoContenedor.push_back("Carton y Papeles");
	TipoContenedor.push_back("Plastico");
	TipoContenedor.push_back("Vidrio");
	srand ( time(NULL) );
	
	vector<string> Dias;
	Dias.push_back("Lunes");
	Dias.push_back("Martes");
	Dias.push_back("Miercoles");
	Dias.push_back("Jueves");
	Dias.push_back("Viernes");
	Dias.push_back("Sabado");
	Dias.push_back("Domingo");
	
	
	ofstream datos(argv[1]);
	
	int clientes = atoi(argv[2]);
	
	datos << "Tipo" << "," << "Lunes" << "," << "Martes" << "," << "Miercoles" << "," << "Jueves" << "," << "Viernes" << ","
			<< "Sabado" << "," << "Domingo" << "\n";
	
	for (int i =0 ; i<clientes ; i++){
		int rm = rand()% 4;
		int rm2,rm3;
		if(TipoContenedor[rm]=="Pilas"){
			rm2 =rand()% 5000 + 100; 
			rm3 =rand()% 5000 + 100;
			datos << TipoContenedor[rm] << "," <<  rm2 << "," << rm3 << "," << "," << "," << "," << "," << "," << "\n";
		}
		else if(TipoContenedor[rm]=="Carton y Papeles"){
			rm2 = rand()% 5000 + 100;
			rm3 = rand()% 5000 + 100;
			datos << TipoContenedor[rm] << "," << "," << "," << rm2  << "," << rm3 << ","  << "," << "," << "," << "\n";
		}
		else if(TipoContenedor[rm]=="Plastico"){
			rm2 = rand()% 5000 + 100;
			rm3 = rand()% 5000 + 100; 
			datos << TipoContenedor[rm] << "," << "," << "," << "," << "," << rm2 << "," << rm3 << "," <<  "\n";
		}
		else{
			rm2 = rand()%5000 + 100;
			datos << TipoContenedor[rm] << "," << "," << "," << "," << "," << "," << "," << rm2 << "\n";
		}
		
	}
	
	sleep(2);
	
}
