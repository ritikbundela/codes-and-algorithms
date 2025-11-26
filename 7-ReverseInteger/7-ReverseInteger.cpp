// Last updated: 26/11/2025, 22:34:56
class Solution {
public:
    int reverse(int x) {
        long reverse = 0;
        while(x!=0)
    {
        int rem = x%10;
        reverse = reverse*10 + rem;
        x = x/10;
    }
        if(reverse>INT_MAX || reverse<INT_MIN) return 0;
        return int(reverse);
    }
};