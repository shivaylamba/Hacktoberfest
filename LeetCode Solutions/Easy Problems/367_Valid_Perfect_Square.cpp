/*
Given a positive integer num, return true if num is a perfect square or false otherwise.
A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
You must not use any built-in library function, such as sqrt.
Example 1:
Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.
Example 2:
Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.
Constraints:
1 <= num <= 231 - 1
*/
/*
    MOST OPTIMIZED APPROACH
Time Complexity O(1)
Space Complexity O(1)
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        return (ceil(sqrt(num))==floor(sqrt(num)));
    }
};
/*
     OPTIMIZED APPROACH
Time Complexity O(log(n))
Space Complexity O(1)
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0) return 0;
        int i =1, j =num;
        long long int mid = i+(j-i)/2;
        while(i<=j){
            if(pow(mid,2)==num) return 1;
            else if(pow(mid,2)>num) j=mid-1;
            else if(pow(mid,2)<num) i=mid+1;
            mid = i+(j-i)/2;
        }
    return 0;
    }
};
/*
    LEAST OPTIMIZED APPROACH
Time Complexity O(n)
Space Complexity O(1)
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long n=INT_MAX;
        for(long i=0;i<n/1000;i++){
            if((i*i) == num){
                return true;
            }
        }
        return false;
    }
};