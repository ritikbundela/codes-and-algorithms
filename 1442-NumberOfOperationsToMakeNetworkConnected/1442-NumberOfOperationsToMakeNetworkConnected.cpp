// Last updated: 26/11/2025, 22:30:56
class Solution {
public:
    vector<int> parent, rank;
    
    int find(int x){
        if(x == parent[x])
        return x;
        return parent[x] = find(parent[x]);
    }

    void unionByRank(int x, int y){
        int par_x = find(x);
        int par_y = find(y);

        if(par_x == par_y)
        return;
        
        if(rank[par_x] > rank[par_y]){
            parent[par_y] = par_x;
        } else if(rank[par_x] < rank[par_y]){
            parent[par_x] = par_y;
        }else{
            parent[par_x] = par_y;
            rank[par_y]++;
        }

    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
        return -1;

        rank.resize(n,0);
        parent.resize(n);
        for(int i=0; i<n; i++)
        parent[i] = i;

        int components = n;
        for(auto &vec: connections){
            if(find(vec[0]) != find(vec[1])){
                unionByRank(vec[0], vec[1]);
                components--;
            }
        }
        return components-1;
    }
};