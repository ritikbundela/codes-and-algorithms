// Last updated: 26/11/2025, 22:29:24
class Solution {
    private int[] getCellScoreAndCost(int cellValue) {
        if (cellValue == 1) {
            return new int[]{1, 1}; 
        } else if (cellValue == 2) {
            return new int[]{2, 1}; 
        } else {
            return new int[]{0, 0};
        }
    }

    public int maxPathScore(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        Map<Integer, Integer>[][] dp = new HashMap[m][n];

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                dp[r][c] = new HashMap<>();
            }
        }
        int[] initial = getCellScoreAndCost(grid[0][0]);
        int initialScore = initial[0];
        int initialCost = initial[1];

        if (initialCost <= k) {
            dp[0][0].put(initialCost, initialScore);
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                
                for (Map.Entry<Integer, Integer> entry : dp[r][c].entrySet()) {
                    int currentCost = entry.getKey();
                    int currentScore = entry.getValue();

                    if (r + 1 < m) {
                        int[] next = getCellScoreAndCost(grid[r + 1][c]);
                        int cellScore = next[0];
                        int cellCost = next[1];
                        
                        int newTotalCost = currentCost + cellCost;
                        
                        if (newTotalCost <= k) {
                            int newTotalScore = currentScore + cellScore;
                            Map<Integer, Integer> nextMap = dp[r + 1][c];
                            
                            int existingScore = nextMap.getOrDefault(newTotalCost, -1);
                            nextMap.put(newTotalCost, Math.max(newTotalScore, existingScore));
                        }
                    }

                    if (c + 1 < n) {
                        int[] next = getCellScoreAndCost(grid[r][c + 1]);
                        int cellScore = next[0];
                        int cellCost = next[1];

                        int newTotalCost = currentCost + cellCost;

                        if (newTotalCost <= k) {
                            int newTotalScore = currentScore + cellScore;
                            Map<Integer, Integer> nextMap = dp[r][c + 1];

                            int existingScore = nextMap.getOrDefault(newTotalCost, -1);
                            nextMap.put(newTotalCost, Math.max(newTotalScore, existingScore));
                        }
                    }
                }
            }
        }
        int maxScore = -1;
        Map<Integer, Integer> endCellMap = dp[m - 1][n - 1];
        
        if (endCellMap.isEmpty()) {
            return -1; 
        }
        
        for (int score : endCellMap.values()) {
            maxScore = Math.max(maxScore, score);
        }

        return maxScore;
    }
}