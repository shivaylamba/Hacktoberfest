# Description Link: https://leetcode.com/problems/stepping-numbers/

class Solution:
    def countSteppingNumbers(self, low, high):
        if high < 11:
            return [v for v in range(low, high + 1)]
        ans = [0] if low == 0 else []
        l = [v for v in range (1,10)]
        for val in l:
            if val > high:
                break
            if val >= low and val <= high:
                ans.append(val)
            if val % 10 == 0:
                l.append(val*10 + (val % 10 + 1))
            elif val % 10 == 9:
                l.append(val*10 + (val % 10 - 1))
            else:
                l.append(val*10 + (val % 10 - 1))
                l.append(val*10 + (val % 10 + 1))
        return ans