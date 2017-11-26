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
#include <cfloat>
#include <limits>

using namespace std;

int main(){
	
	
	ifstream data("datosC3.csv");
	
	int col = 1;
	string line;
    while(std::getline(data,line))
    {
		
        stringstream  lineStream(line);
        string        cell;
        string idT;
        double CXT,CYT,MC;
        while(std::getline(lineStream,cell,',')){
			if(cell!="id_C" && cell!="CX" && cell!="CY" && cell!="Tipo" && cell!="CapacidadM" && cell!="Dias" && 
			cell!="Capacidad_Actual" && cell!="Lunes" && cell!="Martes" && cell!="Miercoles" && cell!="Jueves" && cell!="Sabado"
			&& cell!="Domingo"){
			    switch(col){
				    case 1://ID
						col = col + 1;
						cout << "C"+cell <<": ";
						break;
				    case 2://CX
						CXT = stod(cell);
						col = col + 1;
						cout << CXT << " ";
						break;
				    case 3://CY	
						CYT = stod(cell);
						col = col + 1;
						cout << CYT << " ";
						break;	
					case 4://TIPO
						col = col + 1;
						cout << cell << " ";
						break;
					case 5://COMBJ
						cout << cell << " ";
						col = col + 1;
						break;
					case 6://MAXCAPACITY
						MC = stod(cell);
						col = col + 1;
						cout << cell << " ";
						break;
					case 7://Lunes
						if(cell==""){
						cout << "blanco" << " ";
						}
						else{
							cout << cell << " ";
						}
						col = col + 1;
						break;
					case 8:
						if(cell==""){
						cout << "blanco" << " ";
						}
						else{
							cout << cell << " ";
						}
						col = col + 1;
						break;
					case 9:
					if(cell==""){
						cout << "blanco" << " ";
						}
						else{
							cout << cell << " ";
						}
						col = col + 1;
						break;
					case 10:
						if(cell==""){
						cout << "blanco" << " ";
						}
						else{
							cout << cell << " ";
						}
						col = col + 1;
						break;
					case 11:
						if(cell==""){
						cout << "blanco" << " ";
						}
						else{
							cout << cell << " ";
						}
						col = col + 1;
						break;
					case 12:
						if(cell==""){
						cout << "blanco" << " ";
						}
						else{
							cout << cell << " ";
						}
						col = col + 1;
						break;
					case 13:
						if(cell==""){
						cout << "blanco" << " ";
						}
						else{
							cout << cell << " ";
						}
						break;
						
						
				}
				cout << endl;
				sleep(2);
						  
			}
		}
		col = 1;
	}
	
}
