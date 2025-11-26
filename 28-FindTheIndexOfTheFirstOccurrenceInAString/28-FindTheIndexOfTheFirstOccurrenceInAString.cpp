// Last updated: 26/11/2025, 22:34:36
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hsize = haystack.size(), nsize = needle.size();
        int ans = -1;
        for(int i=0; i<hsize; i++){
            int hidx = i, nidx = 0;
            while(nidx < nsize && haystack[hidx] == needle[nidx]){
                   nidx++;
                   hidx++;
            }
            if(nidx == nsize )
            return i;
         
            // for(int nidx = 0; nidx > nsize; nidx++ ){
            //     if(haystack[hidx] == needle[nidx])
            // }
        }
        return -1;
    }
};