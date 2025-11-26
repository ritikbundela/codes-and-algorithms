// Last updated: 26/11/2025, 22:30:45
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
    int min_cost = 0;
    
    vector<bool> visited(n, false);
    
    // Min-Heap to store {cost, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, 0}); // {cost, point_index}

    int edges_used = 0;

    while (!pq.empty() && edges_used < n) {
        auto [cost, u] = pq.top();
        pq.pop();

        // Skip if already visited
        if (visited[u]) continue;

        visited[u] = true;
        min_cost += cost;
        edges_used++;

        // Explore all edges from point `u`
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                pq.push({dist, v});
            }
        }
    }

    return min_cost;
    }
};