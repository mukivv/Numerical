#include <iostream>

using namespace std;

int main(){
	float b[] = {9,0,-4};
    float a[3][3] = {{-2,3,1},{3,4,-5},{1,-2,1}};
    float l[3][3] = {} , u[3][3] = {};
    float x[3] , y[3];
    for (int r=0;r<3;r++){
    	// L Matrix
    	for (int e=r;e<3;e++){
    		l[e][r] = a[e][r];
			for (int R=0;R<r;R++){
				l[e][r] -= l[e][R]*u[R][r];
			}
		}
		
		u[r][r] = 1;
		
		//U Matrix
		for (int e=r+1;e<3;e++){
			u[r][e] = a[r][e];
			for (int R=0;R<r;R++){
				u[r][e] -= l[r][R]*u[R][e];
			}
			u[r][e] /= l[r][r];
		}
	}
	//forward
	for (int i=0;i<3;i++) {
        y[i] = b[i];
        for (int j=0;j<i;j++) {
            y[i] -= l[i][j] * y[j];
        }
        y[i] /= l[i][i];
    }
    //backward
    for (int i=2;i>=0;i--) {
        x[i] = y[i];
        for (int j=i+1;j<3;j++) {
            x[i] -= u[i][j] * x[j];
        }
        x[i] /= u[i][i];
    }
    
	for (int i=0;i<3;i++){
    	cout<<x[i]<<" ";
	}
	cout<<endl;
}
