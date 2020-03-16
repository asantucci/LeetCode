/* Given an n-ary tree, return the postorder traversal of 
   its nodes' values.

   Nary-Tree input serialization is represented in their 
   level order traversal, each group of children is separated 
   by the null value (See examples).
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
    vector<int> helper(Node* root, vector<int>& result) {
        if (root) {
            for (Node* child : root->children)
                helper(child, result);
            result.push_back(root->val);
        }
        return result;
    }
    vector<int> postorder(Node* root) {
        vector<int> result;
        return helper(root, result);
    }
};
