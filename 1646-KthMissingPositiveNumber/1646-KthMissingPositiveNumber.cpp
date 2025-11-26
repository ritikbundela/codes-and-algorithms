// Last updated: 26/11/2025, 22:30:47
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    int size = arr.size();
    int low = 0, high = size - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        // Calculate how many numbers are missing up to arr[mid]
        int missing = arr[mid] - (mid + 1);
        
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    // If we've checked the whole array, the k-th missing number is beyond arr[high]
    return k + high + 1;
}

};