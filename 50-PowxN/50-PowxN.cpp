// Last updated: 26/11/2025, 22:34:25
class Solution {
public:
    double myPow(double x, int n) {
       if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    long long N = n;  
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double current_product = x;
    while (N > 0) {
        if (N % 2 == 1) {
            ans *= current_product;
        }
        current_product *= current_product;
        N /= 2;
    }
    return ans;
    }
};