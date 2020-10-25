# Description Link: https://leetcode.com/problems/valid-palindrome-iii/

class Solution:
    def lps(self, strs): 
        n = len(strs) 
        L = [[0 for x in range(n)] for x in range(n)] 
        for i in range(n): 
            L[i][i] = 1
        for cl in range(2, n+1): 
            for i in range(n-cl+1): 
                j = i+cl-1
                if strs[i] == strs[j] and cl == 2: 
                    L[i][j] = 2
                elif strs[i] == strs[j]:
                    L[i][j] = L[i+1][j-1] + 2
                else: 
                    L[i][j] = max(L[i][j-1], L[i+1][j])
        return L[0][n-1]

    def isValidPalindrome(self, s, k):
        return self.lps(s) + k >= len(s)