#include<stdio.h>
#include<math.h>

int main(){
	double xL =1.5 ,xR =2.0 ,xM ,xMOld,fxR ,fxM ,error,i=-1;
	do {
		i++;
		
		xM = (xL + xR) / 2;
		fxR = pow(xR,4) - 13;
		fxM = pow(xM,4) - 13;
		if ( fxM * fxR < 0){
			xL = xM;
		} else {
			xR = xM;
		}
		
		if (i>0){
			error = fabs( (xM - xMOld) / xM);
		}
		xMOld = xM;
	} while (i==0 || error > 0.000001);
	printf("%.6f",xM);
}
