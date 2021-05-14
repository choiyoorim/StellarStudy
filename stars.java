import java.util.Scanner;

public class stars {
    public static void main(String[] args) {
        /*int n;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<=i;j++){
                System.out.print("*");
            }
            System.out.println();
        }*/
        
        int a,b;
        Scanner in = new Scanner(System.in);
        while(true){
            a = in.nextInt();
            b = in.nextInt();
            if(a==0 && b==0){
                break;
            }
            System.out.println(a+b);
        }

    }
}
