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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse slow to middle of the linked list
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the back half of the linked list
        ListNode* prev = nullptr;
        while (slow != nullptr) {
            swap(slow->next, prev);
            swap(slow, prev);
        }

        // Compare pairs and keep track of maximum
        int pair_max = 0;
        while (prev != nullptr) {
            pair_max = max(pair_max, prev->val + head->val);
            prev = prev->next;
            head = head->next;
        }

        return pair_max;
    }
};
