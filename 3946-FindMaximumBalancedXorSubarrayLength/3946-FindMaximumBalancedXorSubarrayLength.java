// Last updated: 26/11/2025, 22:29:26
class Solution {
    public int maxBalancedSubarray(int[] nums) {
    int n = nums.length;
    int maxLen = 0;
    Map<String, Integer> firstOcc = new HashMap<>();
    
    int prefXOR = 0;
    int bal = 0; 
    
    firstOcc.put("0,0", -1);
    
    for (int i = 0; i < n; i++) {
        prefXOR ^= nums[i];

        if (nums[i] % 2 == 0) {
            bal++;
        } else {
            bal--;
        }
        
        String key = prefXOR + "," + bal;
        
        if (firstOcc.containsKey(key)) {
            int startIdx = firstOcc.get(key);
            maxLen = Math.max(maxLen, i - startIdx);
        } else {
            firstOcc.put(key, i);
        }
    }
    
    return maxLen;
}
}