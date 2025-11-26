// Last updated: 26/11/2025, 22:34:46
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
        return {};
        vector<string> res;
        string mapp[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,"",mapp,res,digits);
        return res;
    }
    void solve(int idx,string output,string mapp[],vector<string>&res,string digits){
        if(idx >= digits.length())
        {
            res.push_back(output);
            return;
        }
        int num = digits[idx] - '0';
        string value = mapp[num];

        for(int i=0; i<value.length(); i++){
            output.push_back(value[i]);
            solve(idx+1,output,mapp,res,digits);
            output.pop_back();
        }
    }
};