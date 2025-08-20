#include<iostream>

using namespace std;

int main(){
	float b[] = {9,0,-4};
    float a[3][3] = {{-2,3,1},{3,4,-5},{1,-2,1}};
    float i[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    float x[3];
    //forward
    for (int r=0;r<3;r++){ //column r = ref
        for (int e=r+1;e<3;e++){ //row e = edit
            if (a[e][r] == 0) continue;
            float er = a[e][r];
            for (int R=0;R<3;R++){
                a[e][R] = a[e][R] - (a[r][R] / a[r][r])*er;
                i[e][R] = i[e][R] - (i[r][R] / a[r][r])*er;
            }
        }
    }
    //backward
    for (int r=2;r>0;r--){ //column r = ref
        for (int e=r-1;e>=0;e--){ //row e = edit
            if (a[e][r] == 0) continue;
            float er = a[e][r];
            for (int R=0;R<3;R++){
                a[e][R] = a[e][R] - (a[r][R] / a[r][r])*er;
                i[e][R] = i[e][R] - (i[r][R] / a[r][r])*er;
            }
        }
    }
    //divide
    for (int c = 0;c<3;c++){
        float cc = a[c][c];
        for (int j = 0;j<3;j++){
            a[c][j] /= cc;
            i[c][j] /= cc;
        }
    }
    //X = Ainverse * B
    for (int c = 0;c<3;c++){
        for (int j = 0;j<3;j++){
        	x[c] += (i[c][j] * b[j]);
    	}
    	cout<<x[c]<<" ";
    }
}
