// Last updated: 26/11/2025, 22:30:11
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0,neg = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0)
            pos++;
            if(nums[i]<0)
            neg++;
        }
        return max(pos,neg);
    }
};