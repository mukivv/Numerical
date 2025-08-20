#include<stdio.h>
#include<math.h>

int main(){
	double xL =1.5 ,xR =2.0 ,x1 ,xOld =0 ,fxL ,fxR ,fx1 ,error;
	do {
		fxL = pow(xL,4) - 13;
		fxR = pow(xR,4) - 13;
		x1 = (xL*fxR - xR*fxL) / (fxR - fxL);
		fx1 = pow(x1,4) - 13;
		if ( fx1 * fxR < 0){
			xL = x1;
		} else {
			xR = x1;
		}
		error = fabs( (x1 - xOld) / x1);
		xOld = x1;
		
	} while (error > 0.000001);
	printf("%.6f",x1);
}

