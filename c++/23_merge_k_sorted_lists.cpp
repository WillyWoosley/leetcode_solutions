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
 // Comparator class to use as custom comparison function in min-heap
class CompareNode {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> heads;

        // Put all first elements in priority queue
        for (ListNode* list : lists) {
            if (list != nullptr) {
                heads.push(list);
            }
        }

        // Cover some empty edge cases
        if (lists.size() == 0 || heads.empty()) {
            return nullptr;
        }

        // Ugly setup code to start off list/keep reference to head
        ListNode* merged_list = heads.top();
        heads.pop();
        if (merged_list->next != nullptr) {
            heads.push(merged_list->next);
        }
        ListNode* cur = merged_list;


        // While there are still un-merged elements, keep popping them off min-heap,
        // putting them in merged list, and pushing children onto min-heap
        while (!heads.empty()) {
            ListNode* next_node = heads.top();
            heads.pop();

            cur->next = next_node;
            cur = next_node;
            if (next_node->next != nullptr) {
                heads.push(next_node->next);
            }
        }

        return merged_list;
    }
};
