#include<stdio.h>
#include<math.h>

int main(){
	double xi = 0 , xi1 , error;
	do{
		xi1 = (xi + 7) / (xi + 1);
		error = fabs( (xi1 - xi) / xi1);
		xi = xi1;
	} while(error > 0.000001);
	printf("%f",xi1);
}
