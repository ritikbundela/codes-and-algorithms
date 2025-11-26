// Last updated: 26/11/2025, 22:30:09
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for(int n : nums){
            int rem = ((n % value) + value ) % value;
            mp[rem]++;
        }
        
        int res = 0;
        while(true){
            int r = res % value;
            if(mp[r] == 0)
            return res;
            mp[r]--;
            res++;
        }
    }
};