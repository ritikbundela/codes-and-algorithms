// Last updated: 26/11/2025, 22:34:08
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = nums.size()-1;
        while(one <= two){
            if(nums[one] == 2){
                swap(nums[one],nums[two--]);
            }
            else if(nums[one] == 0)
            swap(nums[one++],nums[zero++]);
            else 
            one++;
        }
    }
};