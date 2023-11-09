class Solution(object):
    def countHomogenous(self, s):
        """
        :type s: str
        :rtype: int
        """
        mod = 10**9 + 7
        count = 0
        prev = ''
        length = 0
        for c in s:
            if c == prev:
                length += 1
            else:
                prev = c
                length = 1
            count += length
        return count % mod
