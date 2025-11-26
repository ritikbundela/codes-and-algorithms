// Last updated: 26/11/2025, 22:29:35
class Solution {
    public int smallestNumber(int n) {
         int result = 0;
        int i = 0;
        while (result < n) {
            result += Math.pow(2, i);
            i++;
        }
        return result;
    }
}