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
    ListNode* swapPairs(ListNode* head) {
        ListNode* last = new ListNode(0, head); // Dummy first element
        bool first_iter = true;

        // Go through, swap adjacent nodes while their are node couples to swap
        while (last->next != nullptr && last->next->next != nullptr) {
            ListNode* first = last->next;
            ListNode* second = last->next->next;

            last->next = second;
            first->next = second->next;
            second->next = first;

            // So that new 'head' is actual first element, not second
            if (first_iter) {
                head = second;
                first_iter = false;
            }

            last = first;
        }

        return head;
    }
};
