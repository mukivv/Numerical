#include<stdio.h>
#include<math.h>

int main(){
	double xi = 2 , xi1 , error;
	do{
		xi1 = xi - ((pow(xi,2) - 7) / (2*xi));
		error = fabs( (xi1 - xi) / xi1);
		xi = xi1;
	} while(error > 0.000001);
	printf("%f",xi1);
}
