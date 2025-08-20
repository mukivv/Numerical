#include<stdio.h>
#include<math.h>
int main(){
	int n,x;
	double xL =0 ,xR = 1000000 ,x1 ,xOld =0 ,fxL ,fxR ,fx1 ,error,fxr;
	scanf("%d %d",&x,&n);
	if (2<=n && n<= x && x <= 2000000){	
	
		for (;xL<xR;xL++){
			fxL = pow(xL,n) - x;
			fxr = pow(xL+1,n) - x;
			if (fxL * fxr < 0){
				xR = xL+1;
				break;
			}
		}
		
		do {
			fxL = pow(xL,n) - x;
			fxR = pow(xR,n) - x;
			
			x1 = (xL*fxR - xR*fxL) / (fxR - fxL);
			fx1 = pow(x1,n) - x;
			if ( fx1 * fxR < 0){
				xL = x1;
			} else {
				xR = x1;
			}
			error = fabs( (x1 - xOld) / x1);
			xOld = x1;
		} while (error > 0.000001);
		
		printf("%.4f",x1);
	}
}

