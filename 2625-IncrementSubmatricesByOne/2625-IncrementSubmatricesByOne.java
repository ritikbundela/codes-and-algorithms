// Last updated: 26/11/2025, 22:30:07
class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int [][] mat = new int[n][n];
        for(int i=0; i<queries.length; i++){
            int []query = queries[i];
            int row1 = query[0];
            int col1 = query[1];
            int row2 = query[2];
            int col2 = query[3];

            for(int r=row1; r<=row2; r++){
                for(int c=col1; c<=col2; c++){
                    mat[r][c] += 1;
                }
            }
        }
        return mat;
    }
}