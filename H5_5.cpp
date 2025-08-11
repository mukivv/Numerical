#include <iostream>

using namespace std;

int main(){
	float b[] = {9,0,-4};
    float a[3][3] = {{-2,3,1},{3,4,-5},{1,-2,1}};
    float l[3][3] = {} , u[3][3] = {};
    float x[3] , y[3];
    for (int j=0;j<3;j++){
    	u[j][j] = 1;
    	// L Matrix
    	for (int i=j;i<3;i++){
    		l[i][j] = a[i][j];
			for (int k=0;k<j;k++){
				l[i][j] -= l[i][k]*u[k][j];
			}
		}
		
		//U Matrix
		for (int i=j+1;i<3;i++){
			u[j][i] = a[j][i];
			for (int k=0;k<j;k++){
				u[j][i] -= l[j][k]*u[k][i];
			}
			u[j][i] /= l[j][j];
		}
	}
	//forward
	 for (int i = 0;i<3;i++) {
        y[i] = b[i];
        for (int j=0;j<i;j++) {
            y[i] -= l[i][j] * y[j];
        }
        y[i] /= l[i][i];
    }
    //backward
    for (int i=2;i>= 0;i--) {
        x[i] = y[i];
        for (int j=i+1;j<3;j++) {
            x[i] -= u[i][j] * x[j];
        }
    }
    
    ////////////////////////////////////print
	for (int i=0;i<3;i++){
    	for (int j=0;j<3;j++){
			cout<<l[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for (int i=0;i<3;i++){
    	for (int j=0;j<3;j++){
			cout<<u[i][j]<<" ";
		}
		cout<<endl;
	}
	for (int i=0;i<3;i++){
    	cout<<x[i]<<" ";
	}
	cout<<endl;
}
