// Last updated: 26/11/2025, 22:30:01
class Solution {
public:
    int minOperations(vector<int>& arr) {
        int n = arr.size();
        int operations = 0;

        for (int ind = 0; ind <= n - 3; ind++) {
            if (arr[ind] == 0) {
                for (int i = ind; i < ind + 3; i++) {
                    if (arr[i] == 0) {
                        arr[i] = 1;
                    } else {
                        arr[i] = 0;
                    }
                }
                operations++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                return -1;
            }
        }

        return operations;
    }
};