// Last updated: 26/11/2025, 22:30:16
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    int m = potions.size();
    vector<int> result;

    for (int s : spells) {
        long long need = (success + s - 1) / s; 
        auto it = lower_bound(potions.begin(), potions.end(), need);
        int count = potions.end() - it;
        result.push_back(count);
    }
    return result;
    }
};