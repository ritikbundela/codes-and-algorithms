// Last updated: 26/11/2025, 22:33:12
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0,end = nums.size()-1,minel = nums[0];
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] < nums[end]){
                minel = min(nums[mid],minel);
                end = mid-1;
            } 
            else{
                minel = min(nums[mid],minel);
                start = mid+1;
            }
        }
        return minel;
    }
};