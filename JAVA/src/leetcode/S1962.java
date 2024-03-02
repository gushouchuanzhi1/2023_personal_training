package leetcode;

public class S1962 {
    public static void main(String[] args) {

    }
    public int minStoneSum(int[] piles, int k) {
        int result=0,note=0;
        while(k>0) {
            int max = piles[0];
            for (int i = 0; i < piles.length; i++) {//找到最大的
                if (max < piles[i]) {
                    max = piles[i];
                    note = i;
                }
            }
            piles[note] = piles[note] - floor(piles[note]/2);
            k--;
        }
        for(int i=0;i<piles.length;i++){
            result += piles[i];
        }
        return result;
        }



    public int floor(int x){
        if(x%2==0){
            return x/2;
        }
        else return (x-1)/2;

    }



}
