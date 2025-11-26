// Last updated: 26/11/2025, 22:32:54
class Solution {
    public int reverseBits(int n) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result = result | (n & 1);
            n = n >>> 1;
        }
        return result;
    }
}