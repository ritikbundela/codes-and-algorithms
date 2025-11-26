// Last updated: 26/11/2025, 22:29:16
class Solution {
    public long[] countStableSubarrays(int[] nums, int[][] queries) {
         int n = nums.length;
        int q = queries.length;
        long[] result = new long[q];

        int[] segEnd = new int[n];
        segEnd[n - 1] = n;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                segEnd[i] = segEnd[i + 1];
            } else {
                segEnd[i] = i + 1;
            }
        }

        int[] segStart = new int[n];
        segStart[0] = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                segStart[i] = segStart[i - 1];
            } else {
                segStart[i] = i;
            }
        }
        long[] dp = new long[n + 1];
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            long len = segEnd[i] - i;
            long h_i = f(len); 
            dp[i] = h_i + dp[segEnd[i]];
        }

        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1]; 
            
            long total = 0;
              int s = segStart[r];
            
            if (s <= l) {
                long len = r - l + 1;
                total = f(len);
                
            } else {
                long lenLast = r - s + 1;
                total = f(lenLast);
              
                total += (dp[l] - dp[s]);
            }
            
            result[i] = total;
        }
        
        return result;
    }
    private long f(long n) {
        return n * (n + 1) / 2;
    }
}