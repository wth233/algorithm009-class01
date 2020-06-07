/*
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        for(int i = 0; i < inorder.size(); ++i){
            if(inorder[i] == preorder[0]){

                vector<int> pre_left;
                pre_left.assign(preorder.begin() + 1, preorder.begin() + i + 1);

                vector<int> pre_right;
                pre_right.assign(preorder.begin() + i + 1, preorder.end());

                vector<int> in_left;
                in_left.assign(inorder.begin(), inorder.begin() + i);

                vector<int> in_right;
                in_right.assign(inorder.begin() + i + 1, inorder.end());

                root->left = buildTree(pre_left, in_left);
                root->right = buildTree(pre_right, in_right);

                break;
            }
        }
        return root;

    }
};

//前序的第一个元素为root，中序以root开始：向左为左子树，向右为右子树