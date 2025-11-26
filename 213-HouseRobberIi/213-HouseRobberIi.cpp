// Last updated: 26/11/2025, 22:32:47
class Solution {
public:
    int helper(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int prev1 = 0;
    int prev2 = 0;
    for (int num : nums) {
        int tmp = prev1;
        prev1 = max(prev2 + num, prev1);
        prev2 = tmp;
    }
    return prev1;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp1, temp2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1),helper(temp2));
    }
};