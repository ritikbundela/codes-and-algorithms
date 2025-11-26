// Last updated: 26/11/2025, 22:30:43
class Solution {
    public int minimumOneBitOperations(int n) {
       int ans = n;
    while (n > 0) {
        n >>= 1;
        ans ^= n;
    }
    return ans;  
    }
}