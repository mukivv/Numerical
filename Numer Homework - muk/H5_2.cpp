#include <iostream>

using namespace std;

int main(){
	float b[] = {9,0,-4};
    float a[3][4] = {{-2,3,1,b[0]},{3,4,-5,b[1]},{1,-2,1,b[2]}};
    float x[3];
        
	for (int r=0;r<3;r++){ //column r = ref
        for (int e=r+1;e<3;e++){ //row e = edit
            if (a[e][r] == 0) continue;
            float er = a[e][r];
            for (int R=0;R<4;R++){
                a[e][R] = a[e][R] - (a[r][R] / a[r][r])*er;
            }        
        }
    }
    
    for (int i=2;i>= 0;i--) {
        x[i] = a[i][3];
        for (int j=i+1;j<3;j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
    
    for (int i=0;i<3;i++) {
		cout << x[i] << " ";
	}
}
