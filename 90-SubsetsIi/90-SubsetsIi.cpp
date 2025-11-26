// Last updated: 26/11/2025, 22:33:58
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>sub;
        dfs(0,sub,res,nums);
        return res;
        
    }

    void dfs(int index, vector<int>& comb, vector<vector<int>>& res, vector<int>& candidates) {
        res.push_back(comb);

    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) 
            continue;

        comb.push_back(candidates[i]);
        dfs(i + 1, comb, res, candidates);
        comb.pop_back();
    }
}
};