// Last updated: 26/11/2025, 22:30:42
class Solution {
public:
    int maxDepth(string s) {
        int breacket = 0;
        int res = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
            breacket++;
            res = max(res,breacket);
            }
            else if(s[i] == ')'){
            if(breacket > 0)
            breacket--;
            else
            return -1;
        }
        }
        if(breacket != 0)
        return -1;
        return res;
    }
};