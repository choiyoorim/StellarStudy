import java.util.Scanner;

public class test {
    public static void main(String[] args) {
        /*double w,h,area;
        Scanner in = new Scanner(System.in);
        System.out.print("직사각형의 가로 길이를 입력하세요 : ");
        w = in.nextDouble();
        System.out.print("직사각형의 세로 길이를 입력하세요 : ");
        h = in.nextDouble();
        area = w * h;
        System.out.println("직사각형의 넓이는 "+ area + "입니다.");


        int num;
        Scanner in = new Scanner(System.in);
        System.out.print("정수를 입력하세요 : ");
        num = in.nextInt();
        String s;
        s = (num%2==0) ? "짝수":"홀수";
        System.out.println(s);



        System.out.println("     *     ");
        System.out.println("    ***    ");
        System.out.println("   *****   ");
        System.out.println("  *******  ");
        System.out.println(" ********* ");
        System.out.println("***********");


        int r,h;
        double v;
        Scanner in = new Scanner(System.in);
        System.out.print("원기둥의 밑면 반지름은?");
        r = in.nextInt();
        System.out.print("원기둥의 높이는?");
        h = in.nextInt();
        v = 3.14 * r * r * h;
        System.out.println("원기둥의 부피는 "+ v);

        int num;
        Scanner in = new Scanner(System.in);
        System.out.println("0~999 사이의 숫자를 입력하세요 : ");
        num = in.nextInt();
        int sum = 0;
        while (num / 10 != 0) {
            sum += num % 10;
            num /= 10;
        }
        sum += num;
        System.out.println("각 자릿수의 합 = " + sum);
        */
        int num = 6;
        for(int i = 0; i<num;i++){
            for(int j = num-i; j>0;j--){
                System.out.print(" ");
            }

            for(int j = 0; j<2*i+1; j++){
                System.out.print("*");
            }

            System.out.println();
        }
    }
}
