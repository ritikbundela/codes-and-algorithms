// Last updated: 26/11/2025, 22:30:36
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(),count=0;
        for(int i=0;i<n-1;i++){
            if(i==0 && nums[n-1]>nums[i]){
                count++;
            }
            if(nums[i]>nums[i+1]){
                count++;
            }
        }
        if(count>1){
            return false;
        }
        return true;
    }
};