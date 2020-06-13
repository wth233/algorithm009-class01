# 学习心得

## 第9课 深度优先搜索、广度优先搜索

每个节点都要访问、且仅访问一次

对于节点访问顺序第不同：

### 深度优先 DFS

递归写法

``` python
visited = set() 
def dfs(node, visited):
    if node in visited: # terminator
    	# already visited 
    	return 
	visited.add(node) 
	# process current node here. 
	...
	for next_node in node.children(): 
		if next_node not in visited: 
			dfs(next_node, visited)

```

非递归写法

``` python
def DFS(self, tree): 
	if tree.root is None: 
		return [] 
	visited, stack = [], [tree.root]
	while stack: 
		node = stack.pop() 
		visited.add(node)
		process (node) 
		nodes = generate_related_nodes(node) 
		stack.push(nodes) 
	# other processing work 
	...
```

### 广度优先 BFS

``` python
def BFS(graph, start, end):
    visited = set()
	queue = [] 
	queue.append([start]) 
	while queue: 
		node = queue.pop() 
		visited.add(node)
		process(node) 
		nodes = generate_related_nodes(node) 
		queue.push(nodes)
	# other processing work 
	...
```

二叉树DFS/BFS C++实现

``` C++
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
      /   \
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
```

## 第10课 贪心

每一步选择中都选择当前状态下最好的，从而希望导致全局结果是最优的。

贪心法也可以用作辅助算法或者直接解决一些要求结果不特别精确的问题。

### 适用贪心算法的场景
简单地说，问题能够分解成子问题来解决，子问题的最优解能递推到最终问题的最优解。这种子问题最优解称为最优子结构。

贪心算法与动态规划的不同在于它对每个子问题的解决方案都做出选择，不能回退。动态规划则会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能。

## 第11课 二分查找

```python
# Python
left, right = 0, len(array) - 1 
while left <= right: 
	  mid = (left + right) / 2 
	  if array[mid] == target: 
		    # find the target!! 
		    break or return result 
	  elif array[mid] < target: 
		    left = mid + 1 
	  else: 
		    right = mid - 1
```

### 二分查找的前提

1. 目标函数单调性(单调递增或者递减) 
2. 存在上下界(bounded)
3. 能够通过索引访问(index accessible)

[二分查找 + 牛顿法（Python 代码、Java 代码）](https://leetcode-cn.com/problems/sqrtx/solution/er-fen-cha-zhao-niu-dun-fa-python-dai-ma-by-liweiw/)

