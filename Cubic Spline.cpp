#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n = 5, N = 16;
    double x[n] = {2, 4, 6, 8, 10};
    double y[n] = {9.5, 8.0, 10.5, 39.5, 72.5};
    double X = 4.5;

    double a[N][N+1] = {};
    //f(x)
    for (int i = 0; 4 * i < N; i++) {
        int j = 4 * i;
        for (int k = 3; k >= 0; k--){
            a[2 * i][j + (3 - k)] = pow(x[i], k);
            a[2 * i + 1][j + (3 - k)] = pow(x[i + 1], k);
        }
        a[2 * i][N] = y[i];
        a[2 * i + 1][N] = y[i+1];
    }
    //f'(x)
    for (int i = 1, r = 8; i < 4; i++, r++){
        int j = 4 * (i - 1);
        for (int k = 3; k >= 1; k--){
            a[r][j + (3-k)] = k*pow(x[i], k-1);
            a[r][j + (3-k) + 4] = k*-pow(x[i], k-1);
        }
    }
    //f''(x)
    for (int i = 0,r = 11; 4*i < N; i++,r++) {
        int j = 4 * i;
        int arr[2] = {2,6};
        for (int k = 1; k >= 0; k--){
            a[r][j + (1-k)] = arr[k] * -pow(x[i], k);
            a[r+1][j + (1-k)] = arr[k] * pow(x[i + 1], k);
            if (i==0) a[r][j + (1-k)] *= -1;
        }
    }
    
    //forward
    for (int r=0;r<N;r++){ 
        for (int e=r+1;e<N;e++){ //row e = edit
            if (a[e][r] == 0) continue;
            double er = a[e][r];
            for (int R=0;R<N+1;R++){
                a[e][R] = a[e][R] - (a[r][R] / a[r][r])*er;
            }
        }
    }
    
    //backward
    for (int r=N-1;r>0;r--){ //column r = ref
        for (int e=r-1;e>=0;e--){ //row e = edit
            if (a[e][r] == 0) continue;
            float er = a[e][r];
            for (int R=0;R<N+1;R++){
                a[e][R] = a[e][R] - (a[r][R] / a[r][r])*er;
            }
        }
    }
    //divide
    for (int i = 0;i<N;i++){
        float ii = a[i][i];
        for (int j = 0;j<N+1;j++){
            a[i][j] /= ii;
        }
    }
    
    for (int i = 0; i < N; i++){
        cout << "b[" << i << "] = " << a[i][N] << endl;
    }
    //find f(4.5)
	for (int i=0;i<n-1;i++){
		double sum = 0;
		if (2*(i+1) <= X && X <= 2+2*(i+1)){
			for (int j=3,r=i*4;j>=0;j--,r++){
				sum += a[r][N]*pow(X,j);
			}
			cout << sum;
		}
	}
        
    return 0;
}
