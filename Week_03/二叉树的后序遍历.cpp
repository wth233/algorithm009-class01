/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     helper(root, res);
    //     return res;
    // }

    // void helper(TreeNode* root, vector<int>& res){
    //     if(root != nullptr){
    //         if(root->left != nullptr) helper(root->left, res);
    //         if(root->right != nullptr) helper(root->right, res);
    //         res.push_back(root->val);
    //     }
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        if(root == nullptr) return res;
        TreeNode* cur = root;
        s.push(root);

        while(s.size()){
            cur = s.top();
            s.pop();
            res.push_back(cur->val);
            
            if(cur->left != nullptr) s.push(cur->left);
            if(cur->right != nullptr) s.push(cur->right);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};