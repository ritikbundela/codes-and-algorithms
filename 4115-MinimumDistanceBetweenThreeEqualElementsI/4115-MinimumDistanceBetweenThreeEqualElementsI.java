// Last updated: 26/11/2025, 22:29:13
class Solution {
    public int minimumDistance(int[] nums) {
      Map<Integer, List<Integer>> map = new HashMap<>();
    
    for (int i = 0; i < nums.length; i++) {
        map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
    }
    int minDist = Integer.MAX_VALUE;
    boolean found = false;

    for (List<Integer> list : map.values()) {
        if (list.size() >= 3) {
            for (int i = 0; i + 2 < list.size(); i++) {
                int dist = 2 * (list.get(i + 2) - list.get(i));
                minDist = Math.min(minDist, dist);
                found = true;
            }
        }
    }

    return found ? minDist : -1;
    }
}