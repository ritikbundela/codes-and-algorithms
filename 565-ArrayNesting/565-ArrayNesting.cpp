// Last updated: 26/11/2025, 22:31:52
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        for (int i : nums) {
            int cnt = 0;
            if (i == -1)
                continue;
            while (nums[i] != -1) {
                int prev = i;
                i = nums[i];
                nums[prev] = -1;
                cnt += 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};