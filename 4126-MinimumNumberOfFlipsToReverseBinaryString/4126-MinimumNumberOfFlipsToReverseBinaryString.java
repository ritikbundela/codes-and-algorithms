// Last updated: 26/11/2025, 22:29:09
class Solution {
    public int minimumFlips(int n) {
       int number = 10;
        String binary = Integer.toBinaryString(n); 
        int left = 0, right = binary.length()-1, count = 0;
        while(left <= right){
            if(binary.charAt(left) != binary.charAt(right))
                count += 2;
            left++;
            right--;
        }
        return count;
    }
}