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
    int depthOf(TreeNode* root, int acc) {
        if (root == nullptr) {
            return acc;
        } 
        
        int l_depth = depthOf(root->left, acc + 1);
        int r_depth = depthOf(root->right, acc + 1);

        if (abs(l_depth - r_depth) > 1) {
            return -1;
        } else {
            return max(l_depth, r_depth);
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        return (depthOf(root, 0) >= 0);
    }
};
