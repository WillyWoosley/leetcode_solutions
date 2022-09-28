class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        charmap1 = [-1] * 128
        charmap2 = [-1] * 128
        for (c1, c2) in zip(map(ord, s), map(ord, t)):
            if charmap1[c1] >= 0 or charmap2[c2] >= 0:
                if charmap1[c1] != c2 or charmap2[c2] != c1:
                    return False
            else:
                charmap1[c1] = c2
                charmap2[c2] = c1
        
        return True
