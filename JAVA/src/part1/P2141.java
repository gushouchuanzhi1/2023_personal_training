package part1;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * 多少个数等于其他2个数之和
 * 本题注意同一个结果只计算一次
 */
public class P2141 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {//读取数字
            list.add(sc.nextInt());
        }
        int cnt = 0;
        ArrayList<Integer> sum = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (list.contains(list.get(i) + list.get(j))) {
                    if(sum.contains(list.get(i) + list.get(j))){//如果已经有计算方法了
                        continue;
                    }else{
                        sum.add(list.get(i) + list.get(j));
                        cnt++;
                    }
                }
            }
        }
        System.out.println(cnt);

    }
}
