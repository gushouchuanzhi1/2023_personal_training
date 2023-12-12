package part1;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * 输入一串数字，以0为结束，倒序输出数字
 */
public class P1427 {
    public static void main(String[] args) {
        ArrayList<Integer> input = new ArrayList<>();
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        while (number != 0) {
            input.add(number);
            number = sc.nextInt();
        }
        for (int i = 0; i <= input.size() - 1; i++) {
            System.out.print(input.get(input.size() - 1 - i)+" ");
        }

    }
}
