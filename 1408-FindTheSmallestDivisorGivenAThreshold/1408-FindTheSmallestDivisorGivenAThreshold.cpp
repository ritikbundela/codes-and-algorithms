// Last updated: 26/11/2025, 22:30:58
class Solution {
public:

    int check(vector<int>nums,int div){
        int size = nums.size();
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i]/div;
            if(nums[i]%div != 0)
            sum++;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int size = nums.size();
        if(size > threshold)
        return -1;
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(check(nums,mid) <= threshold)
            {
                high = mid - 1;
            }
            else
            low = mid + 1;

        }
        return low;
    }
};