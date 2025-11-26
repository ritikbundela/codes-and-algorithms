// Last updated: 26/11/2025, 22:33:24
class Solution {
    public int singleNumber(int[] nums) {
        int single = 0;
        for(int num : nums)
        single = single ^ num;
        return single;
    }
}