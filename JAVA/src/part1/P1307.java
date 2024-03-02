package part1;
/**给定一个整数 N，请将该数各个位上数字反转得到一个新数。 新数也应满足整数的常见形式，即
 * 除非给定的原数为零， * 否则反转后得到的新数的最高位数字不应为零（参见样例 2）。*/
import java.util.Scanner;

public class P1307 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuffer sb = new StringBuffer(sc.next());
        StringBuffer reverse = new StringBuffer();
        if (sb.charAt(0) != '-') {
            int start = 0;//记录从后往前开始的位置
            for (int i = sb.length() - 1; i >= 0; i--) {
                if (sb.charAt(i) != '0') {
                    start = i;//找到不是0的就停止for
                    break;
                }
            }
            for (int i = start; i >= 0; i--) {
                reverse.append(sb.charAt(i));
            }
        } else {
            reverse.append('-');
            int start = 0;//记录从后往前开始的位置
            for (int i = sb.length() - 1; i > 0; i--) {
                if (sb.charAt(i) != '0') {
                    start = i;//找到不是0的就停止for
                    break;
                }
            }
            for (int i = start; i > 0; i--) {
                reverse.append(sb.charAt(i));
            }

        }
        System.out.println(reverse);
    }

}
