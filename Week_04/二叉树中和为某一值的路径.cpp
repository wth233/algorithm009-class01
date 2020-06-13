/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;

        if(root != nullptr){
            helper(res, temp, root, 0, sum);
        }

        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& temp, TreeNode* root, int now_sum, int sum){
        now_sum += root->val; 
        temp.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            if(now_sum == sum){
                res.push_back(temp);
                return;
            }
        }
        

        if(root->left != nullptr){
            helper(res, temp, root->left, now_sum, sum);
            temp.pop_back();
        }

        if(root->right != nullptr){
            helper(res, temp, root->right, now_sum, sum);
            temp.pop_back();
        }
    }
};