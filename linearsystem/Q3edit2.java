package linearsystem;
public class Q3edit2 {
    public static void main(String[] args){
        float b[] = {9,0,-4};
        float a[][] = {{-2,3,1,b[0]},{3,4,-5,b[1]},{1,-2,1,b[2]}};
        float x[] = new float[3];
        //forward
        for (int r=0;r<3;r++){ //column r = ref
            for (int e=r+1;e<3;e++){ //row e = edit
                if (a[e][r] == 0) continue;
                float er = a[e][r];
                for (int R=0;R<4;R++){
                    a[e][R] = a[e][R] - (a[r][R] / a[r][r])*er;
                }
            }
        }
        //backward
        for (int r=2;r>0;r--){ //column r = ref
            for (int e=r-1;e>=0;e--){ //row e = edit
                if (a[e][r] == 0) continue;
                float er = a[e][r];
                for (int R=0;R<4;R++){
                    a[e][R] = a[e][R] - (a[r][R] / a[r][r])*er;
                }
            }
        }
        //divide *Snot 0*
        for (int i = 0;i<3;i++){
            a[i][3] /= a[i][i];
            a[i][i] /= a[i][i];
        }
        
        x[0] = a[0][3];
        x[1] = a[1][3];
        x[2] = a[2][3];
        System.out.println(x[0]+" "+x[1]+" "+x[2]);

    }
   
}
