/*
1552. Magnetic Force Between Two Balls
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.

 

Example 1:


Input: position = [1,2,3,4,7], m = 3
Output: 3
Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
Example 2:

Input: position = [5,4,3,2,1,1000000000], m = 2
Output: 999999999
Explanation: We can use baskets 1 and 1000000000.

Constraints:
n == position.length
2 <= n <= 105
1 <= position[i] <= 109
All integers in position are distinct.
2 <= m <= position.length
*/
/*
    =>Approach
=>Sorting:
First, we sort the array of basket positions. This helps us to efficiently check the possible placement of balls in increasing order of positions.

=>Binary Search:
We perform binary search on the possible values of the minimum distance (dist) between two balls.
The lower bound (lo) of our search range is 1 (the smallest possible distance).
The upper bound (hi) is (position[n-1] - position[0]) / (m-1), which is the maximum possible minimum distance when placing m balls in n baskets.

=>Placement Check:
For each mid value in our binary search, we check if it is possible to place m balls such that the minimum distance between any two balls is at least mid.
We start by placing the first ball in the first basket and then attempt to place each subsequent ball in the next available basket that is at least mid distance away from the last placed ball.
If we successfully place all m balls, it means mid is a feasible distance, and we try for a larger distance. If not, we try a smaller distance.

    =>Complexity
=>Time Complexity:
Sorting the position array takes (O(n \log n)).
Binary search involves (O(\log((position[n-1] - position[0]) / (m-1)))) iterations.
Each iteration of binary search involves a linear scan through the baskets to check the feasibility, which takes (O(n)).
Combining these, the overall time complexity is (O(n \log n + n \log ((position[n-1] - position[0]) / (m-1)))).
=>Space Complexity:
The space complexity is (O(1)) as we are only using a few extra variables for binary search and placement check.
*/
class Solution {
private:
    bool canPlace(vector<int>arr, int mid , int m ){
        int countBalls = 1;
        int lastPlaced = arr[0];
        for(int i = 1 ; i<arr.size();i++){
            if(arr[i] - lastPlaced >=mid){
                countBalls++;
                lastPlaced = arr[i];
            }
            if(countBalls>=m) return 1;
        }
        return 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int i = 1  , j = (position[position.size()-1] - position[0])/(m-1) , ans = 1;
        while(i<=j){
            int mid = i + ( j - i )/2;
            if(canPlace(position,mid,m)){
                ans = mid;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return ans;
    }
};