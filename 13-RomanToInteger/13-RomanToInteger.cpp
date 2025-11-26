// Last updated: 26/11/2025, 22:34:50
class Solution {
public:
    int getVal(char ch){
        switch(ch)
        {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: break;
        }
        return 0;
    }
    int romanToInt(string s) {
        int length = s.length();
        int sum = 0; 
        for(int i=0; i<length; i++){
        int currentVal = getVal(s[i]);
           if ((i + 1) < length && currentVal < getVal(s[i + 1])) {
            sum -= currentVal;
        } else {
            sum += currentVal;
        }
        }
        return sum;
    }
};