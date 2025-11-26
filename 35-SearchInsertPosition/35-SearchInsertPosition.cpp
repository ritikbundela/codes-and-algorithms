// Last updated: 26/11/2025, 22:34:32
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int start  = 0, end = arr.size()-1;
        int index = end + 1;;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(arr[mid] >= target){
                index = mid;
                end = mid - 1;
            }else {
                start = mid + 1;
            }
        }
        return index;
    }
};