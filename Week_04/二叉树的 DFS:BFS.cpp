#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// 二叉树的 DFS/BFS
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/*
       1
      /  \
     2     3
    / \   / \
   4   5 6   7
*/

// recursive dfs
void dfs1(TreeNode* head){
    if(head != nullptr){
        cout<<head->val<<",";
        dfs1(head->left);
        dfs1(head->right);
    }
}

// no recursive dfs
void dfs2(TreeNode* head){
    if(head != nullptr){
        stack<TreeNode*> S;
        S.push(head);

        while(!S.empty()){
            TreeNode* cur = S.top();
            S.pop();
            cout<<cur->val<<",";
            if(cur->right != nullptr) S.push(cur->right);
            if(cur->left != nullptr) S.push(cur->left);
        }
    }
}

void bfs(TreeNode* head){
    if(head != nullptr){
        queue<TreeNode*> Q;
        Q.push(head);

        while(!Q.empty()){
            TreeNode* cur = Q.front();
            Q.pop();
            cout<<cur->val<<",";
            if(cur->left != nullptr) Q.push(cur->left);
            if(cur->right != nullptr) Q.push(cur->right);
        }
    }
}

int main() {
    TreeNode* head = new TreeNode(1);
    head->left = new TreeNode(2);
    head->right = new TreeNode(3);
    head->left->left = new TreeNode(4);
    head->left->right = new TreeNode(5);
    head->right->left = new TreeNode(6);
    head->right->right = new TreeNode(7);

    std::cout << "==============DFS1==============\n";
    dfs1(head);
    std::cout << "\n==============DFS2==============\n";
    dfs2(head);
    std::cout << "\n==============BFS===============\n";
    bfs(head);
    return 0;
}
