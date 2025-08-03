package linearsystem;
public class Q1edit{
    public static void main(String[] args) {
        int a[][] = {{-2,3,1},{3,4,-5},{1,-2,1}};
        int x[] = new int[3];
        int b[] = {9,0,-4};
        
        int a1[][] = {{b[0],3,1},{b[1],4,-5},{b[2],-2,1}};
        int a2[][] = {{-2,b[0],1},{3,b[1],-5},{1,b[2],1}};
        int a3[][] = {{-2,3,b[0]},{3,4,b[1]},{1,-2,b[2]}};
        
        int detA = det(a);
        
        x[0] = det(a1) / detA;
        x[1] = det(a2) / detA;
        x[2] = det(a3) / detA;

        System.out.println(x[0]+" "+x[1]+" "+x[2]);

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
