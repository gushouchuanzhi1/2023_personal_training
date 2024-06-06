package hust;

import java.util.Scanner;

import static java.lang.Math.pow;

public class P6685 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(),m= sc.nextInt();
        //x的m次方小于等于n，即n的m次立方根大于等于x
        float result = (float) pow(n,1.0/m);
        System.out.println((int) result);

    }

}
