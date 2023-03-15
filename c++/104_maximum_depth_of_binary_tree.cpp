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
private:
    int maxDepthHelper(TreeNode* root, int acc) {
        if (root == nullptr) {
            return acc;
        } else {
            return max(maxDepthHelper(root->left, acc+1),
                       maxDepthHelper(root->right, acc+1));
        }
    }
public:
    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root, 0);
    }
};
