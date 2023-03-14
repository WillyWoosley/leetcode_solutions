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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur_node = head;
        ListNode* prev = nullptr;

        while (cur_node != nullptr) {
            ListNode* temp = cur_node->next;
            cur_node->next = prev;
            prev = cur_node;
            cur_node = temp;
        }
        
        return prev;
    }
};
