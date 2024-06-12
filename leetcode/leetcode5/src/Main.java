class Solution {
    public String longestPalindrome(String s) {
        int length = s.length();
        int left=0,right=0,result = 0;
        int[][] dp = new int[length][length];
        for(int i = length - 1; i >= 0; i--){
            for(int j = i; j < length; j++){
                if(s.charAt(i) == s.charAt(j) && (j-i<=1 || dp[i+1][j-1]==1)){
                    dp[i][j] = 1;
                    if(j - i >= result){
                        result = j-i;
                        left = i;
                        right = j;
                    }
                }
            }
        }
        return s.substring(left,right+1);
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}