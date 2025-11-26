// Last updated: 26/11/2025, 22:32:16
class Solution {
    public int[] countBits(int n) {
        int[] ans = new int[n + 1];
    ans[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    
    return ans; 
    }
}