// Last updated: 26/11/2025, 22:32:18
class Solution {
    public boolean isPowerOfThree(int n) {
         int maxPowerOf3 = 1162261467; 
        return n > 0 && maxPowerOf3 % n == 0;
    }
}