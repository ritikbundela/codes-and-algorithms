// Last updated: 26/11/2025, 22:30:21
class Solution {
    public int findFinalValue(int[] nums, int original) {
            int j = 0;
            while (j < nums.length) {
                if (nums[j] == original) {
                    original *= 2;
                    j = 0;
                    continue;
                }
                j++;
            }
        return original;
    }
}