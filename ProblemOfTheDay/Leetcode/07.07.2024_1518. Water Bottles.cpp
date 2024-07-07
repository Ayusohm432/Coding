/*
Problem Link :- https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2024-07-07
*/

/*1518. Water Bottles

There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

 

Example 1:


Input: numBottles = 9, numExchange = 3
Output: 13
Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
Number of water bottles you can drink: 9 + 3 + 1 = 13.
Example 2:


Input: numBottles = 15, numExchange = 4
Output: 19
Explanation: You can exchange 4 empty bottles to get 1 full water bottle. 
Number of water bottles you can drink: 15 + 3 + 1 = 19.
 

Constraints:

1 <= numBottles <= 100
2 <= numExchange <= 100

*/

//Approach-1
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinkable = numBottles;
        while(numBottles >= numExchange){

            int exchanged = numBottles / numExchange;
            int left = numBottles % numExchange;
            drinkable += exchanged;
            numBottles = exchanged + left ;

        }

        return drinkable;
    }
};

//Approach-2            T.C = O(n)      S.C = O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = 0;
        while(numBottles >= numExchange){
            consumed += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }
        return consumed+numBottles;
    }
};


//Approach-3            T.C = O((logn) base numExchanged)      S.C = O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int consumed = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange){
            int extraFullBottles  = emptyBottles / numExchange;

            int remainning = emptyBottles % numExchange;

            consumed += extraFullBottles;

            emptyBottles  = remainning + extraFullBottles;
        }
        return consumed;
    }
};

//Approach-4            T.C = O(1)      S.C = O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1) / (numExchange-1);
    }
};