// Last updated: 26/11/2025, 22:33:15
class Solution {
public:
    string reverseWords(string s) {
        int i=0, j,size = s.size();
        string ans = "";
        
        while(i<size){
            string temp = "";
        while(s[i] == ' ' and i<size)
        i++;
        while(s[i] != ' ' and i<size){
            temp += s[i];
            i++;
        }
        if(temp.size() > 0)
        {
            if(ans.size() == 0)
            ans = temp;
            else
            ans = temp + " " + ans;
        }
        }
        return ans;
    }
};