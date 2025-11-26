// Last updated: 26/11/2025, 22:29:12
class Solution {
    public int minimumDistance(int[] nums) {
         
    Map<Integer, List<Integer>> mp = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
        mp.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
    }

    int min_dist = Integer.MAX_VALUE;
    boolean found = false;

    for (List<Integer> list : mp.values()) {
        if (list.size() >= 3) {
            for (int i = 0; i + 2 < list.size(); i++) {
                int dist = 2 * (list.get(i + 2) - list.get(i));
                min_dist = Math.min(min_dist, dist);
                found = true;
            }
        }
    }

    return found ? min_dist : -1;
    }
}