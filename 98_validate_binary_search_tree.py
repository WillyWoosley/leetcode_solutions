# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.isValidHelper(root, None, None)
    
    def isValidHelper(self, root, minVal, maxVal):
        """
        :type root: TreeNode
        :type minVal, maxVal: int
        :rtype: bool
        """
        if root:
            if minVal and root.val <= minVal.val:
                return False
            if maxVal and root.val >= maxVal.val:
                return False
            return self.isValidHelper(root.left, minVal, root) and \
                   self.isValidHelper(root.right, root, maxVal)
        else:
            return True
