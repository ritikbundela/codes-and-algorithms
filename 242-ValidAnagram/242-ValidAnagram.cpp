// Last updated: 26/11/2025, 22:32:25
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
        return false;
        map<char,int>mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for(int i=0; i<t.length(); i++)
        {
            if (mp[t[i]] > 0)
            mp[t[i]]--;
            else 
            return false;  
        }
        return true;
    }
};