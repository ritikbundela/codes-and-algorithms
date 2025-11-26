// Last updated: 26/11/2025, 22:33:26
class Solution {
    public int longestConsecutive(int[] nums) {
      Set<Integer> set = new HashSet<>();
    for (int num : nums) set.add(num);

    int longest = 0;
    for (int num : set) {
        if (!set.contains(num - 1)) {
            int curr = num;
            int streak = 1;
            while (set.contains(curr + 1)) {
                curr++;
                streak++;
            }
            longest = Math.max(longest, streak);
        }
    }
    return longest; 
    }
}