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

test = Solution()

print(test.search([1], 1))
print(test.search([1], 2))
print(test.search([1, 2, 3, 4, 5], 1))
print(test.search([1, 2, 3, 4, 5], 2))
print(test.search([1, 2, 3, 4, 5], 3))
print(test.search([1, 2, 3, 4, 5], 4))
print(test.search([1, 2, 3, 4, 5], 5))
print(test.search([1, 2, 3, 4, 5], 6))
print(test.search([1, 3, 4, 5, 6], 2))
print(test.search([1, 2, 3, 4, 5], -1))
print(test.search([1, 2, 3, 4], 1))
print(test.search([1, 2, 3, 4], 2))
print(test.search([1, 2, 3, 4], 3))
print(test.search([1, 2, 3, 4], 4))
print(test.search([1, 2, 3, 4], -1))
print(test.search([1, 2, 3, 4], 5))
print(test.search([1, 2, 4, 5], 3))
print(test.search([1, 2], -1))
print(test.search([1, 2], 3))
print(test.search([1, 2], 1))
print(test.search([1, 2], 2))

