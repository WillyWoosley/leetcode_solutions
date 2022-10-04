# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children

class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        stack = [root]
        traversal = []

        while len(stack) > 0:
            cur = stack.pop()
            traversal.append(cur.val)
            for child in reversed(cur.children):
                stack.append(child)
        
        return traversal
