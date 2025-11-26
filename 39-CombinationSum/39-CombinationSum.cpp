// Last updated: 26/11/2025, 22:34:31
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> res;
       vector<int> sum;
       solve(target,0,0,candidates,sum,res);
       return res; 
    }

   void solve(int target, int index, int total, vector<int>& candidates,
   vector<int>& sum, vector<vector<int>>& res){
   
    if(total == target){
        res.push_back(sum);
        return ;
    }

    if(index > candidates.size()-1 || total > target)
    return ;

    sum.push_back(candidates[index]);
    solve(target,index,total+candidates[index],candidates,sum,res);

    sum.pop_back();
    solve(target,index+1,total,candidates,sum,res);
   }
};