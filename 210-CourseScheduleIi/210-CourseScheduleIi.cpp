// Last updated: 26/11/2025, 22:32:45
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    // Step 1: Build graph
    for (auto& pre : prerequisites) {
        adj[pre[1]].push_back(pre[0]);
        indegree[pre[0]]++;
    }

    queue<int> q;
    vector<int> ans;

    // Step 2: Push courses with no prerequisites
    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Step 3: Kahn’s Algorithm (BFS for Topological Sort)
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        ans.push_back(course); // ✅ Add current course to answer

        for (int &neighbor : adj[course]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    // Step 4: Check for cycle
    if (ans.size() == numCourses)
        return ans;
        return {};

    }
};