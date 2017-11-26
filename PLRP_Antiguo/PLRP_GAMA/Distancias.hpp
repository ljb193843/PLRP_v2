double DistManhattan(double X1,double Y1,double X2,double Y2){
	
	return abs(X1-Y1)+abs(X2-Y2);
	
}

double DistEuclidian(double X1, double Y1,double X2, double Y2){
	
	return sqrt(pow((X2-X1),2)+pow((Y2-Y1),2));
}
