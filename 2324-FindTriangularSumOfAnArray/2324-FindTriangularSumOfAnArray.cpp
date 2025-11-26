// Last updated: 26/11/2025, 22:30:17
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1) 
        return nums[0];
        int prev = 0;
        // for(int i = nums.size()-2; i >= 0; i--){
        //     for(int j=i; j>=0; j--){
        //         prev = nums[j];
        //         nums[j] = prev + nums[j+1];
        //         if(nums[j] > 9)
        //         nums[j] %= 10;
        //     }
        // }

        for(int i=0; i<nums.size()-1; i++){
            for(int j=0; j<nums.size()-(i+1); j++){
                nums[j] += nums[j+1];
                if(nums[j] > 9)
                nums[j] %= 10;
            }
        }
        return nums[0];
    }
};