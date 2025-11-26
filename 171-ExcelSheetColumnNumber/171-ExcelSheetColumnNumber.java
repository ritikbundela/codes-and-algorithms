// Last updated: 26/11/2025, 22:33:05
class Solution {
    public int titleToNumber(String s) {
        if(s == null)
        return -1;

        int sum = 0;
        for(char c : s.toUpperCase().toCharArray()){
            sum *= 26;
            sum += c - 'A' + 1;
        }
        return sum;
    }
}