#include<stdio.h>
#include<math.h>

int main(){
	float x,l,r,rr;
	for(x=0;x<10;x++){
		l = 43*x-180;
		r = 43*(x+1)-180;
		if ( l*r < 0 ){
			rr = x+1;
			break;
		}
	}
	for(;x<rr;x+=0.000001){
		l = 43*x-180;
		r = 43*(x+0.000001)-180;
		if ( l*r < 0 ){
			if (fabs(l) < fabs(r)){
				break;
			} 
			else {
				x+=0.000001;
				break;
			}
		}
		
	}
	printf("%f",x);
}
