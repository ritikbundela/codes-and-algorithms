// Last updated: 26/11/2025, 22:34:34
class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int x) {
         int start=0,end=arr.size()-1,first=-1,last=-1,mid;
	    while(start<=end){
	         mid = start + (end-start)/2;
	        if(arr[mid] == x){
	            first = mid;
	            end = mid-1;
	        }
	        else if(arr[mid]<x)
	        start = mid+1;
	        else
	        end = mid-1;
	    }
	    start=0,end=arr.size()-1;
	    while(start<=end){
	        mid = start + (end-start)/2;
	        if(arr[mid] == x){
	            last = mid;
	            start = mid+1;
	        }
	        else if(arr[mid]<x)
	        start = mid+1;
	        else
	        end = mid-1;
	    }
	    return {first,last};
    }
};