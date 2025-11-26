// Last updated: 26/11/2025, 22:34:19
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
    int count = 0;
    int i = n - 1;
    while(i >= 0 && s[i] == ' ') {
        i--;
    }
    while(i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
    }
};