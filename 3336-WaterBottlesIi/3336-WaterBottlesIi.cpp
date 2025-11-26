// Last updated: 26/11/2025, 22:30:04
class Solution {
public:
    int maxBottlesDrunk(int fullBottles, int numExchange) {
    int emptyBottles = fullBottles;
    int drunk = fullBottles;

    while (emptyBottles >= numExchange) {
        emptyBottles -= numExchange;  // spend empties
        drunk++;                      // drink the new bottle
        emptyBottles++;               // add its empty back
        numExchange++;                // exchange cost increases
    }

    return drunk;
    }
};