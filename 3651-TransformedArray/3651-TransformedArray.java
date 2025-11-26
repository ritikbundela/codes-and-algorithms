// Last updated: 26/11/2025, 22:29:36
class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int n = nums.length;
        int result[] = new int[n];
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } 
            else {
                int targetIndex = (i + nums[i]) % n;
                if (targetIndex < 0) {
                    targetIndex += n;
                }
                result[i] = nums[targetIndex];
            }
        }
       return result;
    }
}