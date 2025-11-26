// Last updated: 26/11/2025, 22:30:53
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int dist = 0, idx = 0;
        for(int j = 0; j<nums.length; j++){
            if(nums[j] == 1){
            idx = j;
            break;
            }

        }
        for( int i = idx+1; i<nums.length; i++){
            if(nums[i] == 1 ){
                if(dist >= k)
                dist = 0;
                else
                return false;
            }else
            dist++;   
        }
        return true;
    }
}