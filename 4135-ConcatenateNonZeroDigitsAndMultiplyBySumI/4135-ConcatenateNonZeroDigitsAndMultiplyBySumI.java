// Last updated: 26/11/2025, 22:29:11
class Solution {
    public long sumAndMultiply(int n) {
    long mul = 1;
    long x = 0;
    long sum = 0;
    
    while (n > 0) {
        int digit = n % 10;
        if (digit != 0) {
            x = digit * mul + x;
            sum += digit;
            mul *= 10;
        }
        n /= 10;
    }
    
    if (x == 0) {
        return 0;
    }
    
    return x * sum;
}
}