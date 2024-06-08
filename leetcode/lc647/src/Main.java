class Solution {
    public int countSubstrings(String s) {
        int n = s.length(), ans = 0;
        for(int i = 0 ; i < 2 * n - 1; i++){
            int l = i/2, r = i/2 + (i % 2);//判断回文串中心的位置大小
            while(l>=0&&r<n&&s.charAt(l)==s.charAt(r)){//while来判断
                l--;
                r++;
                ans++;
            }
        }
        return ans;
    }
}
public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}
/*这个题目的关键在于我们使用中心扩展方法来计算回文串的数量
* 在回文串中心的情况是有两种的，一种是单个字符，另一种是有两个字符
* 我们通过情况分析得出，中心的范围为[l,r]这里的中心数量是字符串长度的2n-1
* 左边是当前是第i个回文串中心，i/2的位置，而r的取值则为l+imod2即可*/