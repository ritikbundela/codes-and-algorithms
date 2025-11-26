// Last updated: 26/11/2025, 22:32:09
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxcount=0;
        int result=0;
        map<char,int>count;
        int n=s.size();
        for(int right=0;right<n;right++){
            count[s[right]]++;
            maxcount=max(maxcount,count[s[right]]);
        if(right-left+1-maxcount>k){
            count[s[left]]--;
            left++;
        }
        
        result=max(result,right-left+1);
        }
        return result;
    }
};