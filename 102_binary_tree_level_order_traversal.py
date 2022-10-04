# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        traversal = []
        queue = []
        cur_level = 0
        if root:
            queue.append((0, root))
        
        while len(queue) > 0:
            level = []
            while len(queue) > 0 and queue[0][0] == cur_level:
                cur_node = queue.pop(0)[1]
                level.append(cur_node.val)
                if cur_node.left:
                    queue.append((cur_level + 1, cur_node.left))
                if cur_node.right:
                    queue.append((cur_level + 1, cur_node.right))
            traversal.append(level)
            cur_level += 1
        
        return traversal
