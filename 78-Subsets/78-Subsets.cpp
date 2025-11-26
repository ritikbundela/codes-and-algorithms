// Last updated: 26/11/2025, 22:34:06
class Solution {
public:

    void createSub(vector<int>&nums, int index, vector<int>&sub, vector<vector<int>>&res){
        if(index == nums.size()){
            res.push_back(sub);
            return;
        }
        sub.push_back(nums[index]);
        createSub(nums,index+1,sub,res);

        sub.pop_back();
        createSub(nums,index+1,sub,res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>sub;
        createSub(nums,0,sub,res);
        return res;
    }
};