// Last updated: 26/11/2025, 22:31:27
class Solution {
public:

    bool possible(vector<int> piles, int h, int mid){
        int hours = 0;
        for(int i=0; i<piles.size(); i++)
        {
            hours += piles[i]/mid;
            if(piles[i]%mid != 0)
            hours++;
            if(hours > h)
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(possible(piles,h,mid)){
                ans = mid;
                high = mid-1;
            }
            else
            low = mid + 1;
        }
        return ans;
    }
};