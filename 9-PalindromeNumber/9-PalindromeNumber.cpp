// Last updated: 26/11/2025, 22:34:53
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        int num = x;
        long rev = 0;
        while(x != 0)
        {
            rev = (rev*10) + (x%10);
            x = x/10;
        }
        if(num == rev)
        return true;
        else
        return false;
    }
};