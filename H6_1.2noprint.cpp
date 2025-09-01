#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double a[4][4] = {{5,2,0,0},{2,5,2,0},{0,2,5,2},{0,0,2,5}};
    double b[4] = {12,17,14,7};
    double x[4],error = 0.00001;
    double xOld[4] = {0,0,0,0};
    double err[4] = {0} , count=0 , check;
    do {
        check = 0;
        for (int i=0;i<4;i++){
            x[i] = b[i];
            for (int j=0;j<4;j++){
                if (i==j) continue;
                if (x[j] != xOld[j] ){
                    x[i] -= a[i][j]*x[j];
                } else {
                    x[i] -= a[i][j]*xOld[j];
                }
            }
            x[i] /= a[i][i];
        }

        for (int i=0;i<4;i++){
            err[i] = fabs((x[i]-xOld[i]) / x[i]);
            if (err[i] > error){
                check++;
            }
        }

        for (int i=0;i<4;i++){
            xOld[i] = x[i];
        }
        count++;
    } while(check != 0);
    cout << count << endl;
    for (int i=0;i<4;i++){
        cout << x[i] << " ";
    }
}
