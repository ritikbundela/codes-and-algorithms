// Last updated: 26/11/2025, 22:32:53
class Solution {
     public int hammingWeight(int n) {
        int ans=0;
        while(n!=0){
            if((n&1)==1){
                ans++;
            }
			n = n>>>1;
        }
        return ans;
    }
}