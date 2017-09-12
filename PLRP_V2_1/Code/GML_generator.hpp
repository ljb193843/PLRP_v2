void Generate_GML(unmap_C Contenedores, unmap_D Depositos,ofstream& output){

   unmap_C_it c_it;
   unmap_D_it d_it;

   output << "Creator	\"yFiles\"" << "\n";
   output << "Version	\"2.14\"" << "\n";
   output << "graph" << "\n";
   output << "[" << "\n";
   output << "\t" << "hierarchic	1" << " \n";
   output << "\t" << "label	\"\"" << "\n";
   output << "\t" << "directed	1" << "\n";

   int contC = 0;

   for(c_it=Contenedores.begin();c_it!=Contenedores.end();c_it++){

      string id = c_it->second->get_id();
      string id2 = id.erase(0,1);
      double X = c_it->second->get_X();
      double Y = c_it->second->get_Y();

      output << "\t" << "node" << "\n";
      output << "\t" << "[" << "\n";
      output << "\t" << "\t" << "id "+id2 << "\n";
      output << "\t" << "\t" << "label \""+id+"\"" << "\n";
      output << "\t" << "\t" << "graphics" << "\n";
      output << "\t" << "\t" << "[" << "\n";
      output << "\t" << "\t" << "\t" << "x" << "\t" << X << "\n";
      output << "\t" << "\t" << "\t" << "y" << "\t" << Y << "\n";
      output << "\t" << "\t" << "\t" << "w" << "\t" << "30.0" << "\n";
      output << "\t" << "\t" << "\t" << "h" << "\t" << "30.0" << "\n";
      output << "\t" << "\t" << "\t" << "type" << "\t" << "\"rectangle\"" << "\n";
      output << "\t" << "\t" << "\t" << "raisedBorder" << "\t" << "0" << "\n";
      output << "\t" << "\t" << "\t" << "fill" << "\t" << "\"#FFCC00\"" << "\n";
      output << "\t" << "\t" << "\t" << "outline" << "\t" << "\"#000000\"" << "\n";
      output << "\t" << "\t" << "]" << "\n";
      output << "\t" << "\t" << "LabelGraphics" << "\n";
      output << "\t" << "\t" << "[" << "\n";
      output << "\t" << "\t" << "text" << "\t" << "\""+id+"\"" << "\n";
      output << "\t" << "\t" << "fontSize" << "\t" << "12" << "\n";
      output << "\t" << "\t" << "fontName" << "\t" << "\"Dialog\"" << "\n";
      output << "\t" << "\t" << "model" << "\t" << "\"null\"" << "\n";
      output << "\t" << "\t" << "]" << "\n";
      output << "\t" << "]" << "\n";
      contC++;

   }

   int contD = 0;

   for(d_it=Depositos.begin();d_it!=Depositos.end();d_it++){

      string id = d_it->second->get_id();
      string id2 = id.erase(0,1);
      double X = d_it->second->get_X();
      double Y = d_it->second->get_Y();

      output << "\t" << "node" << "\n";
      output << "\t" << "[" << "\n";
      output << "\t" << "\t" << "id "+id2 << "\n";
      output << "\t" << "\t" << "label \""+id2+"\"" << "\n";
      output << "\t" << "\t" << "graphics" << "\n";
      output << "\t" << "\t" << "[" << "\n";
      output << "\t" << "\t" << "\t" << "x" << "\t" << X << "\n";
      output << "\t" << "\t" << "\t" << "y" << "\t" << Y << "\n";
      output << "\t" << "\t" << "\t" << "w" << "\t" << "30.0" << "\n";
      output << "\t" << "\t" << "\t" << "h" << "\t" << "30.0" << "\n";
      output << "\t" << "\t" << "\t" << "type" << "\t" << "\"circle\"" << "\n";
      output << "\t" << "\t" << "\t" << "raisedBorder" << "\t" << "0" << "\n";
      output << "\t" << "\t" << "\t" << "fill" << "\t" << "\"#0000FF\"" << "\n";
      output << "\t" << "\t" << "\t" << "outline" << "\t" << "\"#000000\"" << "\n";
      output << "\t" << "\t" << "]" << "\n";
      output << "\t" << "\t" << "LabelGraphics" << "\n";
      output << "\t" << "\t" << "[" << "\n";
      output << "\t" << "\t" << "text" << "\t" << "\""+id+"\"" << "\n";
      output << "\t" << "\t" << "fontSize" << "\t" << "12" << "\n";
      output << "\t" << "\t" << "fontName" << "\t" << "\"Dialog\"" << "\n";
      output << "\t" << "\t" << "model" << "\t" << "\"null\"" << "\n";
      output << "\t" << "\t" << "]" << "\n";
      output << "\t" << "]" << "\n";
      contD++;

   }

   cout << "Depositos: " << contD << endl;
   cout << "Contenedores: " << contC << endl;

}
