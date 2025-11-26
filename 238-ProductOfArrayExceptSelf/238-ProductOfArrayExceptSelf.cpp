// Last updated: 26/11/2025, 22:32:29
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> res(size, 1); 

    int left = 1;
    for(int i=0; i<size; i++){
        res[i] *= left;
        left *= nums[i];
    }

    int right = 1;
    for(int i=size-1; i>=0; i--){
        res[i] *= right;
        right *= nums[i];
    }
    return res;
    }
};