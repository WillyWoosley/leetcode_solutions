class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) < 1:
            return True
        
        match = 0
        for c in t:
            if c == s[match]:
                match += 1
                if match == len(s):
                    return True
        
        return match == len(s)

test = Solution()
