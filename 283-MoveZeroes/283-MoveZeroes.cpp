// Last updated: 26/11/2025, 22:32:22
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }
       
        while (n-1 >= pos) {
            nums[pos++] = 0;
        }
    }
};