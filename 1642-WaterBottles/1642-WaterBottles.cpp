// Last updated: 26/11/2025, 22:30:48
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
       int count = numBottles; // drink all initial bottles
    
    while (numBottles >= numExchange) {
        int newBottles = numBottles / numExchange; 
        count += newBottles;                      
        numBottles = newBottles + (numBottles % numExchange);
    }
    
    return count;
    }
};