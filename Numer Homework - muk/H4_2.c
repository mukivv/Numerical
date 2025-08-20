#include<stdio.h>
#include<math.h>

double f (double x){
	return pow(x,2) - 7;
}

int main(){
	double xi = 2,xi1,xi2,fxi,fxi1,error;
	fxi = f(xi);
	xi1 = xi+1;
	do{
		fxi1 = f(xi1);
		xi1++;
	} while(fxi * fxi1 > 0);
	xi1--;
	
	do{
		fxi = f(xi);
		fxi1 = f(xi1);
		xi2 = xi1 - ( (fxi1*(xi - xi1)) / (fxi - fxi1));
		error = fabs( (xi2 - xi1) / xi2);
		xi = xi1;
		xi1 = xi2;		
	}while(error > 0.000001);
	printf("%f",xi2);
}
