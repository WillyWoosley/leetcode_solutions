# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __str__(self):
        cur = self
        res = "Linked List: "
        while cur:
            res += str(cur.val) + " "
            cur = cur.next
        return res

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        count = 0
        middle = head
        while head:
            count += 1
            if count % 2 == 0:
                middle = middle.next
            head = head.next
        
        return middle
