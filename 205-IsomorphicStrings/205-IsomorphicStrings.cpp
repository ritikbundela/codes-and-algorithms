// Last updated: 26/11/2025, 22:32:48
class Solution {
public:
    bool isIsomorphic(string s, string t) {
     if (s.length() != t.length()) return false;
    map<char, char> s_to_t, t_to_s;
    for (int i = 0; i < s.length(); i++) {
        char c1 = s[i], c2 = t[i];
        if (s_to_t.find(c1) != s_to_t.end()) {
            if (s_to_t[c1] != c2) return false;
        } else {
            s_to_t[c1] = c2;
        }
        if (t_to_s.find(c2) != t_to_s.end()) {
            if (t_to_s[c2] != c1) return false;
        } else {
            t_to_s[c2] = c1;
        }
    }

    return true;
    }
};