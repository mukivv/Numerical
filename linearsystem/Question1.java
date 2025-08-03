/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package linearsystem;
public class Question1{
    public static void main(String[] args) {
        int a[][] = {{-2,3,1},{3,4,-5},{1,-2,1}};
        int x[] = new int[3];
        int b[] = {9,0,-4};
        int detA = det(a);
        
        x[0] = det(Ai(a,b,0)) / detA;
        x[1] = det(Ai(a,b,1)) / detA;
        x[2] = det(Ai(a,b,2)) / detA;

        System.out.println(x[0]+" "+x[1]+" "+x[2]);

    }
    
    public static int[][] Ai(int a[][] , int b[] , int n){
        int c[][] = new int[3][3];
        for (int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if (j==n){
                    c[i][j] = b[i];
                }else{
                    c[i][j] = a[i][j];
                }
            }
        }
        return c;
    }

    public static int det(int c[][]){
        return c[0][0] * c[1][1] * c[2][2]
            + c[0][1] * c[1][2] * c[2][0]
            + c[0][2] * c[1][0] * c[2][1] 
            - c[2][0] * c[1][1] * c[0][2]
            - c[2][1] * c[1][2] *c[0][0]
            - c[2][2] * c[1][0] * c[0][1];
    }   
}
