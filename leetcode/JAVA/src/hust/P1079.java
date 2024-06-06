package hust;

import java.sql.Array;
import java.util.Scanner;

public class P1079 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String key = sc.nextLine().toLowerCase();//转为小写

        int[] array = new int[1000];

        for (int i = 0; i < key.length(); i++) {
            array[i] = key.charAt(i) - 'a';
//            System.out.println(array[i]);
        }


        String oped = sc.nextLine();

//        System.out.println(key);
//        System.out.println(oped);

        char tempKey = 'a';
        int numKey = 0;
        String result = "";
        for (int j = 0; j < oped.length(); j++) {
            result = result + judge(oped.charAt(j),array[numKey]);
            numKey = (++numKey) % key.length();//下一轮使用的对应的
//            System.out.println(numKey);
        }
        System.out.println(result);

    }

    public static char judge(char oped, int numKey) {
        if (oped >= 'a' && oped <= 'z' && (oped - numKey) < 'a') {//假如处理后大小改变了
            return (char) (oped - numKey + 'z' - 'a' + 1);
        } else if (oped >= 'A' && oped <= 'Z' && (oped - numKey) < 'A') {//假如处理后大小改变了
            return (char) (oped - numKey + 'Z' - 'A' + 1);
        }
        else return (char) (oped - numKey);
    }

}