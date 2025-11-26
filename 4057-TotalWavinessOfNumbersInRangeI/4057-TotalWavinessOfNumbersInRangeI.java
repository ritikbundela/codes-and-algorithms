// Last updated: 26/11/2025, 22:29:22
class Solution {
   public int totalWaviness(int num1, int num2) {
    int total = 0;
    for (int num = num1; num <= num2; num++) {
        total += calculateWaviness(num);
    }
    return total;
}

private int calculateWaviness(int num) {
    String s = String.valueOf(num);
    int n = s.length();
    if (n < 3) return 0;
    
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        int curr = s.charAt(i) - '0';
        int prev = s.charAt(i - 1) - '0';
        int next = s.charAt(i + 1) - '0';
        
        if (curr > prev && curr > next) {
            count++;
        }
        else if (curr < prev && curr < next) {
            count++;
        }
    }
    return count;
}
}