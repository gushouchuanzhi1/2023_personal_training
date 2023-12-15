package part2;

import java.util.Scanner;

/**
 * 给定范围m到n求数字2在这个范围内出现的次数
 */
public class P1179 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //扫描起止
        int start = sc.nextInt(), end = sc.nextInt();
        int cnt = 0;
        for (int i = start; i <= end; i++) {
            cnt += Count(i);
        }
        System.out.println(cnt);

    }

    public static int Count(int number) {//统计2出现次数
        int cnt = 0;
        String s = Integer.toString(number);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '2') cnt++;
            continue;
        }
        return cnt;
    }


}
