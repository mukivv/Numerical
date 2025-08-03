/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package linearsystem;
public class Question2 {
    public static void main(String[] args){
        float b[] = {9,0,-4};
        float a[][] = {{-2,3,1,b[0]},{3,4,-5,b[1]},{1,-2,1,b[2]}};
        float x[] = new float[3];
        
        
        if (a[1][0] != 0) gauss(a,1,0);
        if (a[2][0] != 0) gauss(a,2,0);
        if (a[2][1] != 0) gauss(a,2,1);
        
        x[2] = a[2][3] / a[2][2];
        x[1] = (a[1][3] - a[1][2] * x[2]) / a[1][1];
        x[0] = (a[0][3] - a[0][1] * x[1] - a[0][2] * x[2]) / a[0][0];
        System.out.println(x[0]+" "+x[1]+" "+x[2]);

    }

    public static void gauss(float a[][] , int e , int r){
        float er = a[e][r];
        for (int i= 0;i<4;i++){
            a[e][i] = a[e][i] - (a[r][i] / a[r][r])*er;
        }
    }
   
}
