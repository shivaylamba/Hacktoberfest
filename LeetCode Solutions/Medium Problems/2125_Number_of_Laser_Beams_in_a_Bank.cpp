/*
2125. Number of Laser Beams in a Bank
Anti-theft security devices are activated inside a bank. You are given a 0-indexed binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix. bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty, while'1' means the cell has a security device.

There is one laser beam between any two security devices if both conditions are met:

The two devices are located on two different rows: r1 and r2, where r1 < r2.
For each row i where r1 < i < r2, there are no security devices in the ith row.
Laser beams are independent, i.e., one beam does not interfere nor join with another.

Return the total number of laser beams in the bank.
Input: bank = ["011001","000000","010100","001000"]
Output: 8
Explanation: Between each of the following device pairs, there is one beam. In total, there are 8 beams:
 * bank[0][1] -- bank[2][1]
 * bank[0][1] -- bank[2][3]
 * bank[0][2] -- bank[2][1]
 * bank[0][2] -- bank[2][3]
 * bank[0][5] -- bank[2][1]
 * bank[0][5] -- bank[2][3]
 * bank[2][1] -- bank[3][2]
 * bank[2][3] -- bank[3][2]
Note that there is no beam between any device on the 0th row with any on the 3rd row.
This is because the 2nd row contains security devices, which breaks the second condition.
Example 2:
Input: bank = ["000","111","000"]
Output: 0
Explanation: There does not exist two devices located on two different rows.
 

Constraints:

m == bank.length
n == bank[i].length
1 <= m, n <= 500
bank[i][j] is either '0' or '1'.
*/
/*
         ==== Approacah==========
=>Variable Initialization:
ans stores the final result.
temp tracks the previous count of '1's encountered in the strings.
=>Iteration through Strings:
Loop through each string in tuhe bank vector.
=>Counting '1's:
Count the occurrences of '1' in each string using count and store the count in n.
=>Calculation based on Counts:
If n (the count of '1's) is zero, move to the next string.
=>If n is not zero:
Multiply the previous count (temp) by the current count (n) and add it to ans.
Update temp with the current count n for the next iteration.
=>Return the Final Result:
After iterating through all strings, return the accumulated value stored in ans.
Complexity

=>Time complexity:
O(n∗m)
=>Space complexity:
O(1)
*/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prc = 0;
        int tc=0;
        for(int i=0;i<bank.size();i++){
                    int crc=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1'){crc++;}
            }
            if(crc==0){
                continue;
            }
            tc+=crc*prc;
            prc=crc;
        }
        return tc;
    }
};