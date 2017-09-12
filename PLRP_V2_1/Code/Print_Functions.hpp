void Print_Contenedores(unmap_C C){

   for(unmap_C_it v=C.begin();v!=C.end();v++){

      cout << "Contenedor: " << v->first << endl;
      cout << "\t" << "\t" << v->second->get_tipo() << endl;
      unmap_st_db m = v->second->get_demand();
      for(unmap_st_db_it s=m.begin();s!=m.end();s++){
         cout << "\t" << "\t" << s->first << ": " << s->second << endl;
      }
   }
}

void Print_Depositos(unmap_D D){

   for(unmap_D_it d=D.begin();d!=D.end();d++){
      cout << "Deposito: " << d->first << endl;
      cout << "\t" << "Vehiculos: " << d->second->get_vehiculos().size() << endl;

   }
}

void Print_Ruta(unmap_R R){

   for(unmap_R_it r=R.begin();r!=R.end();r++){

      cout << "Ruta: " << r->first << "\t" << endl;
      cout << "\t" << "\t" << r->second->get_vehiculo()->get_id() << endl;
   }

}

void Print_Dias(unmap_set dias){

   unmap_set_it u_it;
   set_st_it s_it;


   for(u_it=dias.begin();u_it!=dias.end();u_it++){
      cout << u_it->first << " :" << "\n";
      for(s_it=u_it->second.begin();s_it!=u_it->second.end();s_it++){
         cout << "\t" << *s_it << "\n";
      }

   }
}
