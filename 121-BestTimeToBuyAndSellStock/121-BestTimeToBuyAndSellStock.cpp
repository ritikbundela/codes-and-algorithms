// Last updated: 26/11/2025, 22:33:34
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size < 2)
        return 0; 
        int buy = prices[0];
        int sell = 0;
        for(int i=0; i<size; i++)
        {
            if(prices[i] < buy)
            buy = prices[i];
            else
            sell = max(sell , prices[i] - buy);
        }
        return sell;
    }
};