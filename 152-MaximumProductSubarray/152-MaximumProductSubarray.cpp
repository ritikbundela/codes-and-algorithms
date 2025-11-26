// Last updated: 26/11/2025, 22:33:14
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = 1; 
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            prod*=nums[i];
            res = max(prod, res);
            if(prod == 0)
            prod = 1;
        }
        prod = 1;
        for(int i=nums.size()-1; i>=0; i--){
            prod*=nums[i];
            res = max(prod, res);
            if(prod == 0)
            prod = 1;
        }
        return res;
    }
};