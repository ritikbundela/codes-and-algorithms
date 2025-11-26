// Last updated: 26/11/2025, 22:32:28
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
    if (n == 0 || k == 0) return new int[0];
    
    int[] result = new int[n - k + 1];
    Deque<Integer> dq = new ArrayDeque<>();
    
    for (int i = 0; i < n; i++) {
        while (!dq.isEmpty() && dq.peek() <= i - k) {
            dq.poll();
        }
        
        while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) {
            dq.pollLast();
        }
        
        dq.offer(i);
        
        if (i >= k - 1) {
            result[i - k + 1] = nums[dq.peek()];
        }
    }
    
    return result;
    }
}