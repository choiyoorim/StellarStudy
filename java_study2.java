import java.util.Scanner;

public class java_study2 {
    public static void main(String[] args) {
        /*
        int age;
        System.out.println("나이를 입력하세요");
        Scanner in = new Scanner(System.in);
        age = in.nextInt();
        if(age>=19) System.out.println("성년");
        else System.out.println("미성년");


        int score;
        System.out.print("성적을 입력하세요 : ");
        Scanner in = new Scanner(System.in);
        score = in.nextInt();

        if(score>=90 && score<=100) System.out.println("A");
        else if(score>=80) System.out.println("B");
        else if(score>=70) System.out.println("C");
        else if(score>=60) System.out.println("D");
        else System.out.println("F");


        int year;
        Scanner in = new Scanner(System.in);
        year = in.nextInt();
        if((year % 4 == 0&&year %100 != 0) || year%400==0 ){
            System.out.println("1");
        }
        else System.out.println("0");*/

        int h,m;
        Scanner in = new Scanner(System.in);
        h = in.nextInt();
        m = in.nextInt();

        if((m-45)<0){
            h--;
            if(h<0) h = (h+24)%24;
            m = (m - 45 + 60) % 60;
        }
        else{
            m -= 45;
        }

        System.out.printf("%d %d",h,m);
    }
}
