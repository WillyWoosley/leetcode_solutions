class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        low = 0
        high = len(nums)

        while low < high:
            cur = (low + high) // 2
            if nums[cur] == target:
                return cur
            elif nums[cur] < target:
                low = cur + 1
            else:
                high = cur
        
        return -1
