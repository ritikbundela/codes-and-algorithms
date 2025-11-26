// Last updated: 26/11/2025, 22:31:53
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int size = nums.size();
       int prefix [size];
       prefix[0] = nums[0];
       
       for(int i=1; i<size; i++)
       prefix[i] = nums[i] + prefix[i-1];

       unordered_map<int,int> mp;
       int result = 0;
       for(int i=0; i<size; i++){
        if(prefix[i] == k)
        result++;
        if(mp.find(prefix[i] - k) != mp.end())
            result += mp[prefix[i]-k];

             mp[prefix[i]]++;
       }
       return result;
    }
};