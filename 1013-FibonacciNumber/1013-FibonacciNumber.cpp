// Last updated: 26/11/2025, 22:31:22
class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int a = 0, b = 1;
        int sum = a+b;
        while(n>=2) {
            sum = a+b;
            a = b;
            b = sum ;
            n--;
        }
        return sum;
     }
};