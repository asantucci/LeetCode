/* Given the root node of a binary search tree, return the sum 
   of values of all nodes with value between L and R (inclusive).

   The binary search tree is guaranteed to have unique values.
*/
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
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        // If we bottom out our recursion, simply utilize the additive identity.
        if (!root) return 0;
        // If our value is in range of [L,R], add it to a (recursive) sum.
        int value_add = root and root->val >= L and root->val <= R ? root->val : 0;
        return value_add + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};
