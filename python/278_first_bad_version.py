# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
def isBadVersion(version):
    pass

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        low = 1
        high = n
        
        while low < high:
            cur = (low + high) // 2
            if isBadVersion(cur):
                high = cur
            else:
                low = cur + 1

        return low