// Last updated: 26/11/2025, 22:30:46
class Solution {
    public int minCost(String colors, int[] needed) {
        int total = 0;
        int n = colors.length();

        for(int i=1; i<n; i++){
            if(colors.charAt(i) == colors.charAt(i-1)){
                total += Math.min(needed[i], needed[i-1]);
                needed[i] = Math.max(needed[i], needed[i-1]);
            }
        }
        return total;
    }
}