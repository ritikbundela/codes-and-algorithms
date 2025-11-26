// Last updated: 26/11/2025, 22:36:20
1class Solution {
2    public int findLHS(int[] nums) {
3        Arrays.sort(nums);
4        int j = 0;
5        int maxLength = 0;
6        
7        for (int i = 0; i < nums.length; i++) {
8            while (nums[i] - nums[j] > 1) {
9                j++;
10            }
11            if (nums[i] - nums[j] == 1) {
12                maxLength = Math.max(maxLength, i - j + 1);
13            }
14        }
15        return maxLength;
16    }
17}