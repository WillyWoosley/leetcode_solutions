/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> traversal;
        int visit_depth = -1;
        queue<pair<int, TreeNode*>> visit;
        if (root != nullptr) {
            visit.push(make_pair(0, root));
        }

        while (!visit.empty()) {
            // Pop from front of queue
            int cur_depth;
            TreeNode* cur;
            tie(cur_depth, cur)= visit.front();
            visit.pop();

            // Add current node val to appropriate traversal level
            if (cur_depth == visit_depth) {
                traversal[visit_depth].push_back(cur->val);
            } else {
                traversal.push_back({cur->val});
                visit_depth = cur_depth;
            }

            // Enqueue any existant children
            if (cur->left != nullptr) {
                visit.push(make_pair(cur_depth + 1, cur->left));
            }
            if (cur->right != nullptr) {
                visit.push(make_pair(cur_depth + 1, cur->right));
            }
        }

        return traversal;
    }
};
