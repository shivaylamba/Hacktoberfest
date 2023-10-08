#include <iostream>
#include <vector>
using namespace std;

string longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();

    // Create a 2D vector to store LCS lengths.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Populate the dp table.
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                // If characters match, increment LCS length by 1.
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // If characters don't match, take max of LCS lengths without considering one character.
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS.
    int i = m, j = n;
    string result = "";
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            // If characters match, they are part of LCS.
            result = text1[i - 1] + result;
            --i;
            --j;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            // If not, move in the direction of higher LCS length.
            --i;
        } else {
            --j;
        }
    }

    return result;
}

int main() {
    string text1 = "abcdef";
    string text2 = "acbcf";

    string lcs = longestCommonSubsequence(text1, text2);

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
