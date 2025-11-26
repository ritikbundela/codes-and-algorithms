// Last updated: 26/11/2025, 22:32:06
class Solution {
public:
    string frequencySort(string s) {
        if (s.empty())
            return "";

        if (s.length() == 1)
            return s;

        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> maxHP;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            maxHP.push(make_pair(it->second, it->first));
        }

        string ans = "";
        while (!maxHP.empty()) {
            pair<int, char> temp = maxHP.top();
            maxHP.pop();

            int count = temp.first;
            char ch = temp.second;

            while (count) {
                ans += ch;
                count--;
            }
        }

        return ans;
    }
};