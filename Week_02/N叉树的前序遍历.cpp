/*
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :

      1
    / \  \
   3  2   4
  /  \
 5    6


返回其前序遍历: [1,3,5,6,2,4]。

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
    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(Node* root, vector<int>& res){
        if(root == nullptr) return;

        res.push_back(root->val);

        for(int i = 0; i < root->children.size(); ++i){
            helper(root->children[i], res);
        }
    }
};