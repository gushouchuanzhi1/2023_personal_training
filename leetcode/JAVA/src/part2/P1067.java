package part2;

import java.util.Scanner;

/**
 * 输出一元多项式，0为0
 */
public class P1067 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        int cur = sc.nextInt();
        sb.append(Integer.toString(cur) + ciShu(cnt, cur));//单独输出了第一项
        for (int i = 1; i <= cnt; i++) {
            int xishu = sc.nextInt();
            int cishu = cnt - i;
            sb.append(xiShu(xishu) + ciShu(cishu, xishu));
        }
        System.out.println(sb);
    }

    public static String xiShu(int xishu) {//对于每个单项式系数
        if (xishu == 1) {
            return "+";
        }
        if (xishu == 0) {
            return "";
        }
        if (xishu == -1) {
            return "-";
        }
        if (xishu > 0) {
            return "+" + Integer.toString(xishu);
        } else {
            return Integer.toString(xishu);
        }
    }

    public static String ciShu(int cishu, int xishu) {
        if (xishu != 0) {
            if (cishu == 0) {
                if(xishu != 1){
                    return "";
                }
                return "1";
            }
            if (cishu == 1) {
                return "x";
            }
            if (cishu >= 2) {
                return "x^" + Integer.toString(cishu);
            }
        }

        return "";

    }

}
