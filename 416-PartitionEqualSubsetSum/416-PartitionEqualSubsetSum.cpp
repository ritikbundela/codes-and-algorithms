// Last updated: 26/11/2025, 22:32:11
class Solution {
public:

    vector<vector<int>> dp;
     bool rec(int i, int target, vector<int>& nums) {
        if (target == 0)
            return true;
        if (target < 0)
            return false;
        if (i == 0)
            return target == nums[i];
        if (dp[i][target] != -1)
            return dp[i][target];
        bool notTake = rec(i - 1, target, nums);
        bool take = rec(i - 1, target - nums[i], nums);
        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int x : nums)
            sum += x;

        if (sum % 2)
            return false;
        int target = sum / 2;

        // Memoization TC: O(n*sum+1) SC:O(n*sum+1)
        dp.resize(n, vector<int>(target + 1, -1));
        return rec(n - 1, target, nums);
    }
};