// Last updated: 26/11/2025, 22:31:23
class Solution {
public:
    void dfs(vector<vector<int>>& stones, vector<bool> &visited, int ind) {
    int n = stones.size();
    visited[ind] = true;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && (stones[i][0] == stones[ind][0] || stones[i][1] == stones[ind][1])) {
            dfs(stones, visited, i);  
        }
    }
}

int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();
    vector<bool> visited(n, false);
    int group = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(stones, visited, i);
            group++; 
        }
    }
    return n - group;  
}
};