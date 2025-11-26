// Last updated: 26/11/2025, 22:29:18
class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        Set<Integer> presentNumbers = new HashSet<>();
        int min = 112,max = 0, n = nums.length;
        for (int num : nums) {
            presentNumbers.add(num);
            min = Math.min(min, num);
            max = Math.max(max,num);
        }
        List<Integer> missingNumbers = new ArrayList<>();
        for (int i = min; i <= max; i++) {
            if (!presentNumbers.contains(i)) {
                missingNumbers.add(i);
            }
        }
        
        return missingNumbers;
    }
}