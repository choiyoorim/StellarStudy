import java.util.Scanner;

public class ex4 {
    public static void main(String[] args) {
        int n = 0;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int array[] = new int[n];
        for(int i = 0; i<n; i++){
            array[i] = in.nextInt();
        }
        long sum = sum(array);
        System.out.println(sum);
    }
    public static long sum(int[] a){
        long sum = 0;
        for(int i = 0; i<a.length;i++){
            sum += a[i];
        }
        return sum;
    }
}
