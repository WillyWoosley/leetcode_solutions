class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        maxProf = 0
        left = 0
        right = 0

        while right < len(prices):
            curProf = prices[right] - prices[left]
            maxProf = max(maxProf, curProf)
            if curProf < 0:
                left += 1
            else:
                right += 1

        return maxProf
