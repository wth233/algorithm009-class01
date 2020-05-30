/*
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。

例如，给定一个 3叉树 :

       1
    / \  \
   3  2   4
  /  \
 5    6

返回其层序遍历:

[
     [1],
     [3,2,4],
     [5,6]
]
 

说明:

树的深度不会超过 1000。
树的节点总数不会超过 5000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(root != nullptr) helper(root, res, 0);
        return res;
    }

    void helper(Node* root, vector<vector<int>>& res, int level){
        if(res.size() <= level){
            res.push_back({});
        }
        res[level].push_back(root->val);
        for(int i = 0; i < root->children.size(); ++i){
            helper(root->children[i], res, level + 1);
        }
    }
};