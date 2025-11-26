// Last updated: 26/11/2025, 22:33:07
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
    }
};