/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left_node = head;
        ListNode* right_node = head;

        // Find pointer to kth node
        for (int i = 1; i < k; i++) {
            left_node = left_node->next;
        }

        // Slide pointer that's k back from 'cur' forward while
        // cur isn't null, finding n-kth node
        ListNode* cur = left_node;
        while (cur->next != nullptr) {
            cur = cur->next;
            right_node = right_node->next;
        }

        // Swap vals and return
        swap(left_node->val, right_node->val);
        return head;
    }
};
