class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_count = dict()
        for c in s:
            if char_count.get(c):
                char_count[c] += 1
            else:
                char_count[c] = 1
        
        longest = 0
        singleton = False
        for v in char_count.values():
            if v % 2 == 0:
                longest += v
            else:
                singleton = True
                longest += v - 1
        
        return longest + singleton
