void CrearRuta(Ruta *R,unmap_st_unmap costos,unmap_D Depositos,unmap_C Contenedores
               ,unmap_R Rutas,string dia,string idD,string idC,int ContR){

   //Set Id de la ruta
   R->set_id("R"+to_string(ContR));
   //Set el deposito con el idD
   R->set_deposito(Depositos[idD]);
   //Set el Vehiculo

}
