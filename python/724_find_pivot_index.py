class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        arr_total = 0
        for x in nums:
            arr_total += x
        
        left_total = 0
        for i, x in enumerate(nums):
            if (arr_total - x) / 2 == left_total and (arr_total - x) % 2 == 0:
                return i
            left_total += x

        return -1
