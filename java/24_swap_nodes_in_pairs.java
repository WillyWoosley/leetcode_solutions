/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        helper(head);
        return head;
    }
    
    public void helper(ListNode head) {
        ListNode n;
        int v;
        
        if (head == null) {
            return;
        } else {
            if (head.next == null) {
                return;
            } else {
                n = head.next;
            }
        }
        
        helper(n.next);
        v = n.val;
        n.val = head.val;
        head.val = v;
    }
}
