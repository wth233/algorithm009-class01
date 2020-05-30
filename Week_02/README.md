# Week02 学习心得

## 第五课 哈希表、映射、集合

Hash table: Key-value 映射到表中一个位置，加快访问速度，映射函数叫作散列函数 (Hash Fuction)，存放记录到数组叫作哈希表。

哈希碰撞：要存储的不同数据，经过哈希函数后得到了相同的结果。

拉链式解决冲突法 =》在冲突的位置拉出来一个链表

Time Complexity Worst =〉退化成链表 O(n)

### C++中的map、hash_map、unordered_map
原文：https://blog.csdn.net/u014209688/article/details/95366594?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.nonecase

map底层是用红黑树实现的，空间复杂度为O(n)，是随着节点的增加才增加，而查找的时间时间复杂度则固定是O(log(n))了。因为红黑树本来就是一种二叉搜索树，所以从begin()遍历到end()得到的key值是有序的，这也是map的一个特点。
 
hash_map是SGI实现，而unordered_map是C++11标准中新增的。它们都是用hash表实现的，使用开链法解决冲突问题。但是由于用的是hash表，其特性已经决定使用的空间基本到会比实际需要的空间大。保存的数据不是有序的，不能像map那样子通过遍历得到一个有序的结果。查找的时间复杂度可以达到O(1)，基本上都是比map快的。在unordered_map中，链表节点用的是称为bucket（桶）的数据结构。

虽然大多数情况下hash table实现的map都会比红黑树实现的map查找快，但不是绝对的，因为冲突过多的话，可能耗费时间比map还要多。所以对于前者基本上都会有个rehash的操作，而由于rehash的处理不一样，也导致了hash_map和unordered_map的性能有一些差别。

### 写题4步

1. clarification
2. possible solution -> optimal time & space
3. code
4. test case

## 第六课 树、二叉树、二叉搜索树

链表是特殊化的树，树是特殊化的图

``` C++
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
```

前序 根-左-右

``` C++
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res; 
    }

    void helper(TreeNode* root, vector<int>& res){
       if(root != nullptr){
           res.push_back(root->val);
           if(root->left != nullptr){
               helper(root->left, res);
           }
           if(root->right != nullptr){
               helper(root->right, res);
           }
       }
    }
};
```

中序 左-根-右

``` C++
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res; 
    }

    void helper(TreeNode* root, vector<int>& res){
       if(root != nullptr){
           if(root->left != nullptr){
               helper(root->left, res);
           }
           res.push_back(root->val);
           if(root->right != nullptr){
               helper(root->right, res);
           }
       }
    }
};
```

后序 左-右-根（类似上面代码）

二叉搜索树：空树 或者 满足以下条件的二叉树：

1. 左子树上所有节点的值均小于根节点

2. 右子树上所有节点的值均大于根节点

3. 以此类推：左右子树也分别为二叉搜索树

结论：中序遍历是升序遍历

查询、插入、删除：O(logN)

删除：如果是叶节点直接删除，如果是根结点，找到比这个根节点大的最小的叶节点充当新的根结点

## 堆、二叉堆、图

Heap: 可以迅速找到一堆数中的最大/最小值的数据结构

根结点最大（小）：大（小）顶/根堆

常见的堆：二叉堆、斐波那契堆

find-max: O(1), delete-max: O(logN), insert(create): O(logN) or O(1)

### 二叉堆

完全二叉树来实现

二叉堆（大顶）满足以下性质：

1. 是一棵完全树

2. 树中的任意节点的值总是 >= 其子节点的值

二叉堆的实现细节：

1. 一般通过“数组“来实现

2. 假设“第一个元素”在数组索引为0的位置时，其父节点和子节点的位置关系如下：

（1）索引为i的左儿子的索引是2i+1

（2）索引为i的右儿子的索引是2i+2

（3）索引为i的父节点的索引是floor((i-1)/2)


Insert：O(logN)

1. 新元素一律先插入到堆的尾部

2. 依次向上调整整个堆的结构，如果新插入元素大于父亲节点就和父亲节点进行交换

Delete MAX：

1. 将堆尾替换到顶部

2. 依次从根向下调整整个堆的结果（HeapifyDown），选最大的子节点和顶部元素进行交换

### 图 参考链接

连通图个数： https://leetcode-cn.com/problems/number-of-islands/

拓扑排序（Topological Sorting）： https://zhuanlan.zhihu.com/p/34871092

最短路径（Shortest Path）：Dijkstra https://www.bilibili.com/video/av25829980?from=search&seid=13391343514095937158

最小生成树（Minimum Spanning Tree）： https://www.bilibili.com/video/av84820276?from=search&seid=17476598104352152051
