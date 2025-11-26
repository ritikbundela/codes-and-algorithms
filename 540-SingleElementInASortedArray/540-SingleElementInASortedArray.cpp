// Last updated: 26/11/2025, 22:31:58
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 1,end = nums.size()-1,target;
        if(nums.size() == 1)
        return nums[0];
        if(nums[0] != nums[1])
        return nums[0];
        if(nums[end] != nums[end-1])
        return nums[end];
        end--;
        while(start <= end){
            int mid = start+(end-start)/2;
            if(nums[mid] < nums[mid+1] && nums[mid] > nums[mid-1])
            target = nums[mid];
            if(mid%2 != 0){
                if(nums[mid-1] == nums[mid])
                start = mid+1;
                else
                end = mid-1;
            }
            else{
                if(nums[mid+1] == nums[mid])
                start = mid+1;
                else
                end = mid-1;
            }
        }
        return target;
    }
};