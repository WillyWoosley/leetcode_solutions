/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool lowestCommonAncestorHelper(TreeNode* root, int p, int q) {
        if (root == nullptr) {
            return false;
        }

        int found_tally = 0;
        bool found_left = lowestCommonAncestorHelper(root->left, p, q);
        bool found_right = lowestCommonAncestorHelper(root->right, p, q);

        // Already found ancestor somewhere lower in traversal, so
        // just abort
        if (ancestor != nullptr) {
            return true;
        }

        if (root->val == p || root->val == q) {
            found_tally += 1;
        }
        if (found_left) {
            found_tally += 1;
        }
        if (found_right) {
            found_tally += 1;
        }

        if (found_tally == 2) {
            ancestor = root;
        }

        if (found_tally > 0) {
            return true;
        } else {
            return false;
        }
    }
public:
    TreeNode* ancestor = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool found = lowestCommonAncestorHelper(root, p->val, q->val);
        return ancestor;
    }
};
