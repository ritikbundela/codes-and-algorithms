// Last updated: 26/11/2025, 22:31:44
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int idx = 0;
        while(idx < bits.length){
            if(bits[idx] == 1){
                idx += 2;
                if(idx>=bits.length)
                return false;
            }else
            idx++;
        }
        return true;
    }
}