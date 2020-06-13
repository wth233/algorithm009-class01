/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。


示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
    
    //解法1: 放置分界符，一旦弹出的节点是分界符，说明该层遍历结束
    // vector<vector<int>> levelOrder(TreeNode* root) {
    //     vector<vector<int>> res;
    //     vector<int> temp;

    //     if(root != nullptr){
    //         queue<TreeNode*> Q;
    //         TreeNode* dummy = new TreeNode(INT_MAX);

    //         Q.push(root);
    //         Q.push(dummy);

    //         while(!Q.empty()){
    //             TreeNode* cur = Q.front();
    //             Q.pop();

    //             if(cur == dummy){
    //                 res.push_back(temp);
    //                 temp.clear();
    //                 if(!Q.empty()) Q.push(dummy);
    //             }
    //             else{
    //                 temp.push_back(cur->val);
    //                 if(cur->left != nullptr) Q.push(cur->left);
    //                 if(cur->right != nullptr) Q.push(cur->right);
    //             }
    //         }

    //     }

    //     return res;

    // }

    //解法2: 用dfs，用level标识每一层
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> res;

        if(root != nullptr)
            helper(res, root, 0);

        return res;
    }

    void helper(vector<vector<int>>& res, TreeNode* root, int level){
        if (root == nullptr) return;

        if(level >= res.size()){
            vector<int> temp;
            res.push_back(temp);
        }
        res[level].push_back(root->val);
        helper(res, root->left, level + 1);
        helper(res, root->right, level + 1);
    }

};


