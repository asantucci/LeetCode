/* Given an n-ary tree, return the preorder traversal of its nodes' values.

   Nary-Tree input serialization is represented in their level order traversal, 
   each group of children is separated by the null value (See examples).
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> helper(Node* root, vector<int> &vals) {
        if (root) {
            vals.push_back(root->val);
            for (const auto &child : root->children)
                helper(child, vals);
        }
        return vals;
    }
    vector<int> preorder(Node* root) {
        vector<int> vals{};
        return helper(root, vals);
    }
};
