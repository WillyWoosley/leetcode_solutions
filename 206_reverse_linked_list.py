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
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        res = None
        while head:
            temp = ListNode(head.val, res)
            res = temp
            head = head.next

        return res
