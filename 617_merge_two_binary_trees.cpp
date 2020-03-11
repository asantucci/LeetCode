/* Given two binary trees and imagine that when you put one 
   of them to cover the other, some nodes of the two trees 
   are overlapped while the others are not.

   You need to merge them into a new binary tree. The merge 
   rule is that if two nodes overlap, then sum node values up 
   as the new value of the merged node. Otherwise, the NOT null 
   node will be used as the node of new tree.
*/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // We will maintain that t1 is the merged tree. So, if it's NULL
        // we'd prefer to swap with the other tree (potentially NULL as well, but that's OK).
        if (!t1) swap(t1, t2);
        if (!t2) return t1;  // If only one tree left, return it.
        // Otherwise, both t1 and t2 are non-NULL, and we simply merge the values into t1.
        t1->val += t2->val;
        // We then recurse, setting left and right children to the result of a call to
        // mergeTrees.
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
