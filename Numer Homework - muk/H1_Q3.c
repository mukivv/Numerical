#include<stdio.h>
#include<math.h>

int main(){
	int n,x;
	double xL =0 ,xR =1000000 ,xM ,xMOld =0 ,fxR ,fxM ,error;
	scanf("%d %d",&x,&n);
	if (2<=n && n<= x && x <= 2000000){
		do {
			xM = (xL + xR) / 2;
			fxR = pow(xR,n) - x;
			fxM = pow(xM,n) - x;
			if ( fxM * fxR < 0){
				xL = xM;
			} else {
				xR = xM;
			}
			error = fabs( (xM - xMOld) / xM);
			xMOld = xM;
			printf("%.7f %.11f\n",xM,error);
		} while (error > 0.000001);
		
		printf("%.4f",xM);
	}
}

