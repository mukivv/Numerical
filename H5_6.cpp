#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float b[] = {7, 5.5, 3.5};
    float a[3][3] = {{4, 2, 1}, {2, 3, 0.5}, {1, 0.5, 2}};
    float l[3][3] = {} , lt[3][3] = {};
    float x[3] , y[3];
    //L matrix
    for (int i=0;i<3;i++){
    	for (int j=0;j<=i;j++){
    		float sum = 0.0;
    		if (i==j){
    			for (int k=0;k<j;k++){
    				sum += l[i][k]*l[i][k];
				}
				l[i][i] = sqrt(a[i][i] - sum);
			} else {
				for (int k=0;k<j;k++){
    				sum += l[i][k] * l[j][k];
				}
				l[i][j] = (a[i][j] - sum) / l[j][j];
			}
		}
	}
	//Lt matrix
	for (int i=0;i<3;i++){
    	for (int j=0;j<3;j++){
    		lt[i][j] = l[j][i];
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
    for (int i=2;i>= 0;i--) {
        x[i] = y[i];
        for (int j=i+1;j<3;j++) {
            x[i] -= lt[i][j] * x[j];
        }
        x[i] /= lt[i][i];
    }
	for (int i=0;i<3;i++){
    	cout<<x[i]<<" ";
	}
	cout<<endl;
    
	
	
}
