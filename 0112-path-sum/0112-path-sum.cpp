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
    bool hasPathSum(TreeNode* root, int targetSum) {
         // 1. If tree is empty
        if (root == NULL)
            return false;

        // 2. If leaf node
        if (root->left == NULL && root->right == NULL) {
            return targetSum == root->val;
        }

        // 3. Check left OR right subtree
        int remainingSum = targetSum - root->val;

        return hasPathSum(root->left, remainingSum) ||
               hasPathSum(root->right, remainingSum);
    
    }
};