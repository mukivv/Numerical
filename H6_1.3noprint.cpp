#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a[4][4] = {{5,2,0,0},{2,5,2,0},{0,2,5,2},{0,0,2,5}};
    double b[4] = {12,17,14,7};
    double x[4] = {0} ,error = 0.00001, err ,up,down;
    double r[4] = {0} , d[4] , ramda=0 , alpha=0 , count=0;
    
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            r[i] += a[i][j] * x[j];
        }
        r[i] -= b[i];
        d[i] = -r[i];
    }

    do {
    	if (count != 0) {
    		//ALPHA
			up=0,down=0;
        	for (int i=0;i<4;i++){
            	for (int j=0;j<4;j++){
                	up += r[j]*a[j][i]*d[i];
                	down += d[j]*a[j][i]*d[i];
            	}
        	}
        	alpha = up/down;
        	//D
        	for (int i=0;i<4;i++){
            	d[i] = alpha * d[i] - r[i];
        	}
    	}
    	//Ramda
        up=0,down=0;
        for (int i=0;i<4;i++){
            up += d[i]*r[i];
            for (int j=0;j<4;j++){
                down += d[j]*a[j][i]*d[i];
            }
        }
        ramda = -(up / down); 
        //X
        for (int i=0;i<4;i++){
        	x[i] += ramda*d[i];
    	}
    	//R
    	for (int i=0;i<4;i++){
    		up = 0;
            for (int j=0;j<4;j++){
                up += a[i][j] * x[j];
            }
            r[i] = up - b[i];
        }
        //Error
        err = 0;
        for (int i=0;i<4;i++){
    		err += r[i]*r[i];
        }
		err = sqrt(err);
		
		count++;
    }while(err > error);
    
    cout<<count<<endl;
    for (int i=0;i<4;i++){ 
		cout << x[i] << " "; 
	}
}
