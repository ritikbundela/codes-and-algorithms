// Last updated: 26/11/2025, 22:34:59
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int size = s.size();
       if(size == 0)
       return 0;
       if(size == 1)
       return 1;
       int length = 0, left = 0;
       unordered_set<char> str;
       str.insert(s[0]);
       for(int right=1; right<size; right++){
        while(str.find(s[right]) != str.end()){
            str.erase(s[left]);
            left++;
        }
        str.insert(s[right]);
        length = max(length, right-left+1);
       }
       return length;
    }
};