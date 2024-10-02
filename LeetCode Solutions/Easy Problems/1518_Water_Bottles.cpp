/*
1518. Water Bottles
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
/*
    MOST OPTIMIZED APPROACH
Time Complexity O(1)
Space Complexity O(1)
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numExchange > numBottles){
            return numBottles;
        }
        return (numBottles - numExchange) / (numExchange - 1) + 1 + numBottles;
    }
};
/*
    OPTIMZED APPROACH
Time Complexity O(no of Bottles)
Space Complexity O(1)
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int td = 0;
        while(numBottles){
            td+=1;
            numBottles--;
            if(td%numExchange==0) td+=1;
        }
        return td;
    }
};
//-------------------------------------------------------------------------------------//
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        int x=numBottles;
        while(true){
            int y=x/numExchange;
            int z=x%numExchange;
            sum+=y;
            x=y+z;
            if(x<numExchange){
                break;
            }
        }
        return sum;
    }
};