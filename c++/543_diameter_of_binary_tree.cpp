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
    // Returns tuple of <max diameter seen, tree depth>
    tuple<int, int> diameterOfBinaryTreeHelper(TreeNode* root) {
        if (root == nullptr) {
            return make_tuple(0, 0);
        }

        int max_l, depth_l, max_r, depth_r;
        tie(max_l, depth_l) = diameterOfBinaryTreeHelper(root->left);
        tie(max_r, depth_r) = diameterOfBinaryTreeHelper(root->right);
 
        int pivot = depth_l + depth_r;
        int new_max = max(pivot, max(max_l, max_r));
        int max_depth = max(depth_l, depth_r) + 1;

        return make_tuple(new_max, max_depth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return get<0>(diameterOfBinaryTreeHelper(root));
    }
};
