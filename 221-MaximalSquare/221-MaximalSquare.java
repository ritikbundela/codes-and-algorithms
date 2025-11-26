// Last updated: 26/11/2025, 22:32:43
class Solution {
    public int maximalSquare(char[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        int max = 0;
        int [] dp = new int[col+1];
        int prev = 0;
        for (int i = 1; i <= row; i++) {
        prev = 0; 
        for (int j = 1; j <= col; j++) {
            int temp = dp[j]; 
            if (matrix[i - 1][j - 1] == '1') {
                dp[j] = 1 + Math.min(Math.min(dp[j], dp[j - 1]), prev);
                max = Math.max(max, dp[j]);
            } else {
                dp[j] = 0;
            }
            prev = temp; 
        }
    }
        return max * max;
    }
}