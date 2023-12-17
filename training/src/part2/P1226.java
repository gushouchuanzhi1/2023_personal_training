package part2;

import java.util.Scanner;

public class P1226 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextInt(),b=sc.nextInt(),p=sc.nextInt();
        long result = cnt(a,b,p);
        System.out.println(a+"^"+b+" mod "+p+"="+result);


    }
    public static long cnt(long a,long b, long p){
        if(b==0){
            return 1;
        }
        if(b%2==0){
            long temp = cnt(a,b/2,p)%p;
            return temp*temp%p;
        }
        if(b%2==1){
            return cnt(a,b-1,p)*a%p;
        }
        return 1;
    }

}
