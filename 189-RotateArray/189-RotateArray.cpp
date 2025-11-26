// Last updated: 26/11/2025, 22:32:55
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
     if(k == 0) 
     return;
     int size = nums.size();
     k = k % size;
     if(k == 0)
     return ;
     vector<int>temp;
     for(int i = nums.size()-k; i<nums.size(); i++)
     temp.push_back(nums[i]);   
     for(int i = 0; i<nums.size()-k; i++)
     temp.push_back(nums[i]);
     for(int i=0; i<nums.size(); i++)
     nums[i] = temp[i];
    }
};