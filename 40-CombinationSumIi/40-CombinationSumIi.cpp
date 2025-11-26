// Last updated: 26/11/2025, 22:34:30
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        solve(0, 0, target, comb, res, candidates);
        return res;
    }

    void solve(int index, int total, int target, vector<int>& comb,
               vector<vector<int>>& res, vector<int>& candidates) {
        if (total == target) {
            res.push_back(comb);
            return;
        }

        if (total > target) {
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (total + candidates[i] > target)
                break;

            comb.push_back(candidates[i]);
            solve(i + 1, total + candidates[i], target, comb, res, candidates);
            comb.pop_back();
        }
    }
    };