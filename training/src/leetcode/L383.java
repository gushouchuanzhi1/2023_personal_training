package leetcode;
/**给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
   如果可以，返回 true ；否则返回 false 。
   magazine 中的每个字符只能在 ransomNote 中使用一次。
 * */
public class L383 {
    public static void main(String[] args) {
        String ransomNote = "aa";
        String magazine = "ab";
        boolean result = canConstruct(ransomNote,magazine);
        System.out.println(result);

    }
    public static boolean canConstruct(String ransomNote, String magazine) {
        int[] magazineLitter = new int[26];
        char cur = 'a';
        for(int i = 0; i<magazine.length();i++){
            int num = magazine.charAt(i) - 'a';
            magazineLitter[num]++;
        }
        for(int j = 0; j < ransomNote.length();j++){
            int num = ransomNote.charAt(j) - 'a';
            if(magazineLitter[num] > 0){
                magazineLitter[num]--;
                continue;
            }else {
                return false;
            }
        }
        return true;
    }

}
