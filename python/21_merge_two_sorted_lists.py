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
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        merged = ListNode()
        cur = merged
        while list1 or list2:
            if not list1:
                cur.next = ListNode(list2.val)
                list2 = list2.next
            elif not list2:
                cur.next = ListNode(list1.val)
                list1 = list1.next
            else:
                if list1.val > list2.val:
                    cur.next = ListNode(list2.val)
                    list2 = list2.next
                else:
                    cur.next = ListNode(list1.val)
                    list1 = list1.next
            cur = cur.next

        return merged.next
