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
    bool isValidBSTHelper(TreeNode* root, long minVal, long maxVal) {
        if (root != nullptr) {
            if (root->val <= minVal) {
                return false;
            } else if (root->val >= maxVal){
                return false;
            } else {
                return (isValidBSTHelper(root->left, minVal, root->val) &&
                        isValidBSTHelper(root->right, root->val, maxVal));
            }
        } else {
            return true;
        }
    }

public:
    bool isValidBST(TreeNode* root) {
        long min = static_cast<long> (INT_MIN);
        long max = static_cast<long> (INT_MAX);
        return isValidBSTHelper(root, min - 1, max + 1);
    }
};
