// Last updated: 26/11/2025, 22:31:29
class Solution {
public:
    bool rotateString(string s, string goal) {
        int len = s.length();
        for(int i=0; i<len; i++)
        {
            s += s[i];
            if(s.substr(i+1, len+1) == goal)
            return true;
        }
        return false;
    }
};