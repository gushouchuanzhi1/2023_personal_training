package part1;

import java.util.Scanner;

public class P5015 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        int num = 0;
        for(int i = 0; i<s.length();i++){
            if(s.charAt(i) != ' '){
                num++;
            }
            else continue;
        }
        System.out.println(num);
    }
}
