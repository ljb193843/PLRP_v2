void Greedy_Rute(string dia,unmap_st_unmap costos,vector<unmap_C> &Conts_dias,unmap_R &Rutas,unmap_D &Depositos,int &contR){

   //cout << Conts_dias.size() << endl;

   unmap_C All_Conts;


   for(int i=0;i<Conts_dias.size();i++){

      unmap_C_it c_it;

      for(c_it=Conts_dias[i].begin();c_it!=Conts_dias[i].end();c_it++){

         All_Conts[c_it->first] = c_it->second;

      }

   }
   //Buscar los id's del contenedor y deposito mas cercanos entre si
   //asginarlos al par ids
   pair<string,string> ids = Cont_Dept_MasCercanos(costos,All_Conts,Depositos);

   string idD = ids.first;// id del deposito
   string idC1 = ids.second;//id del contenedor

   Ruta *R = new Ruta;











}
