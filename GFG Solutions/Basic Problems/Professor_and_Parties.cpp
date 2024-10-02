/*
Professor and Parties
A professor went to a party. Being an erudite person, he classified the party into two categories. He proposed that if all the persons in the party are wearing different colored robes, then that is a girl’s only party. If we even get one duplicate color, it must be a boy’s party. The colors of the robes are represented by positive integers.
Example 1:
Input
N = 5
A[] = {1, 2, 3, 4, 7}
Output
GIRLS
Explanation:
All the colors are unique so it's a GIRLS party.
Example 2:
Input
N = 6
A[] = {1, 3, 2, 4, 5, 1}
Output
BOYS
Explanation:
There are two colors 1. So it's a BOYS party.
Your task:
You don't need to print the answer, printing is done by the driver code itself. You have to complete the function PartyType() which takes the array A[] and its size N as inputs and returns  “BOYS” (without quotes) if it’s a boy’s party, else returns “GIRLS”.
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/
class Solution{
    public:
    
    string PartyType(long long int a[], int n)
    {
        // Your code goes here
        unordered_map<long long int,long long int> f;
        for(long long int i=0;i<n;i++){
            f[a[i]]++;
        }
        for(auto i:f){
            if(i.second > 1){
                return "BOYS";
            }
        }
        return "GIRLS";
    }
};