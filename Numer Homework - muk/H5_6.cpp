#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float b[] = {7, 5.5, 3.5};
    float a[3][3] = {{4, 2, 1}, {2, 3, 0.5}, {1, 0.5, 2}};
    float l[3][3] = {} , lt[3][3] = {};
    float x[3] , y[3];
    //L,Lt matrix
    for (int r=0;r<3;r++){
    	for (int e=0;e<=r;e++){
    		float sum = 0.0;
    		if (e==r){
    			for (int R=0;R<e;R++){
    				sum += l[r][R]*l[r][R];
				}
				l[r][r] = sqrt(a[r][r] - sum);
			} else {
				for (int R=0;R<e;R++){
    				sum += l[r][R] * l[e][R];
				}
				l[r][e] = (a[r][e] - sum) / l[e][e];
			}
			
			lt[e][r] = l[r][e];
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
    //print
	for (int i=0;i<3;i++){
    	cout<<x[i]<<" ";
	}
	cout<<endl;
}
