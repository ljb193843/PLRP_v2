double DistEuclidian(double X1, double Y1,double X2, double Y2){

	return sqrt(pow((X2-X1),2)+pow((Y2-Y1),2));
}

void Asignar_Costos(unmap_st_unmap &costos,unmap_C contenedores,unmap_D depositos){


   //Parametros para distancia euclidiana
   double DX1,DY1,DX2,DY2,CX1,CY1,CX2,CY2,coste;

   //Iteradores para contenedores y depositos
   unmap_D_it d_it;
   unmap_C_it c_it;
   unmap_C_it c_it_2;

   string idD,idC,idC2;

   //Depositos a Contenedores
   for(d_it=depositos.begin();d_it!=depositos.end();d_it++){

      idD = d_it->first;
      costos[idD];

      for(c_it=contenedores.begin();c_it!=contenedores.end();c_it++){

         idC = c_it->first;
         DX1 = d_it->second->get_X();
         DY1 = d_it->second->get_Y();
         CX2 = c_it->second->get_X();
         CY2 = c_it->second->get_Y();
         coste = DistEuclidian(DX1,DY1,CX2,CY2);
         costos[idC][idD] = coste;
         costos[idD][idC] = coste;

         //cout << "Dept :"+idD+" => "+idC+" " << coste << endl;;

      }
   }

   //Contenedores a Contenedores
   for(c_it=contenedores.begin();c_it!=contenedores.end();c_it++){

      idC = c_it->first;
      costos[idC];

      for(c_it_2=contenedores.begin();c_it_2!=contenedores.end();c_it_2++){

         idC2 = c_it_2->first;
         CX1 = c_it->second->get_X();
         CY1 = c_it->second->get_Y();
         CX2 = c_it_2->second->get_X();
         CY2 = c_it_2->second->get_Y();
         coste = DistEuclidian(CX1,CY1,CX2,CY2);
         costos[idC][idC2] = coste;

         //cout << "Cont "+idC+" => "+idC2+" " << coste << endl;

         }

      }

}
