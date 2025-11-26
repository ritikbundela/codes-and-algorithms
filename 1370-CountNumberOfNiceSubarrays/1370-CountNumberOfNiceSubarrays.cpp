// Last updated: 26/11/2025, 22:31:01
class Solution {
public:
    
    int numberOfSubarrays(vector<int>& nums, int k) {
    int result = 0;
    int runningCount = 0;
    int oddCount = 0;
    int l = 0;

    for (int r = 0; r < nums.size(); r++) {
        if (nums[r] % 2 != 0) {
            oddCount++;
            runningCount = 0;
        }

        while (oddCount == k) {
            runningCount++;
            if (nums[l] % 2 != 0) {
                oddCount--;
            }
            l++;
        }

        result += runningCount;
    }

    return result;
}

};