// Last updated: 26/11/2025, 22:29:39
class Solution {

    private int check(int[] nums, int n, int t, int m){
        long nL = n, tL = t;
        int l = lowerbound(nums,  nL);
        int h = upperbound(nums,  nL);
        int ll = lowerbound(nums,  nL - tL);
        int hh = upperbound(nums,  nL + tL);
        int res = (hh - h) + (l - ll);
        return Math.min(m, res) + (h - l);
    }

    private int lowerbound(int [] arr, long target){
        int l = 0, r = arr.length;
        while(l < r){
            int mid = (l+ r) / 2;
            if(arr[mid] < target) 
            l = mid + 1;
            else
            r = mid;
        }
        return l;
    }

    private int upperbound(int [] arr, long target){
        int l = 0, r = arr.length;
        while(l < r){
            int mid = (l+ r) / 2;
            if(arr[mid] <= target) 
            l = mid + 1;
            else
            r = mid;
        }
        return l;
    }

    public int maxFrequency(int[] nums, int k, int numOperations) {
        int m = numOperations; 
        Arrays.sort(nums);
        int ans = 1;
        for(int i = 0; i < nums.length - 1; i++){
            ans = Math.max(ans, check(nums, nums[i], k, m));
            ans = Math.max(ans, check(nums, nums[i]-k, k, m));
            ans = Math.max(ans, check(nums, nums[i]+k, k, m));

        }
        return ans;
    }
}