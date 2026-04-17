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
    // Helper function: check if two trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // dono NULL
        if (p == NULL && q == NULL)
            return true;

        // ek NULL, ek nahi
        if (p == NULL || q == NULL)
            return false;

        // value check
        if (p->val != q->val)
            return false;

        // left + right check
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    // Main function
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // base case
        if (root == NULL)
            return false;

        // check current node
        if (isSameTree(root, subRoot))
            return true;

        // recursive call left + right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
