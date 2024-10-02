/*
241. Different Ways to Add Parentheses
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
Example 1:
Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:
Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
Constraints:
1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.
*/
class Solution {
private:
    // This function will break the expression at each operator and solve the parts separately
    vector<int> computeWays(string exp) {
        vector<int> result;

        // Loop through each character in the expression
        for (int i = 0; i < exp.size(); ++i) {
            char ch = exp[i];

            // If the character is an operator, we split the expression around it
            if (ch == '+' || ch == '-' || ch == '*') {
                // Solve the left part of the expression (before the operator)
                vector<int> left = computeWays(exp.substr(0, i));

                // Solve the right part of the expression (after the operator)
                vector<int> right = computeWays(exp.substr(i + 1));

                // Combine the results from the left and right parts using the operator
                for (int l : left) {
                    for (int r : right) {
                        if (ch == '+') {
                            result.push_back(l + r);
                        } 
                        else if (ch == '-') {
                            result.push_back(l - r);
                        } 
                        else if (ch == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If no operator is found, it means the expression is a single number
        if (result.empty()) {
            result.push_back(stoi(exp));  // Convert the string to an integer and add to result
        }

        return result;
    }

public:
    // This is the main function that will be called to get all possible results
    vector<int> diffWaysToCompute(string exp) {
        return computeWays(exp);  // Call recursion
    }
};