# 学习心得

## 第13课 字典树和并查集

## 字典树

### 基本结构

字典树，即 Trie 树，又称单词查找树或键树，是一种树形结构。典型应用是用于统计和排序大量的字符串(但不仅限于 字符串)，所以经常被搜索引擎系统用于文本词频统计。

它的优点是: 最大限度地减少无谓的字符串比较，查询效率比哈希表高。

### 基本性质

1. 节点本身不存完整单词
2. 从根结点到某一结点，路径上经过的字符连接起来，为该结点对应的字符串
3. 每个节点是所有子节点路径代表的路径都不相同

节点存储额外都信息（如单词都频次）

### 核心思想

Trie 树的核心思想是空间换时间。 

利用字符串的公共前缀来降低查询时间的开销以达到提高效率的目的。

### Trie 树代码模板

```python
class Trie(object):
  
	def __init__(self): 
		self.root = {} 
		self.end_of_word = "#" 
 
	def insert(self, word): 
		node = self.root 
		for char in word: 
			node = node.setdefault(char, {}) 
		node[self.end_of_word] = self.end_of_word 
 
	def search(self, word): 
		node = self.root 
		for char in word: 
			if char not in node: 
				return False 
			node = node[char] 
		return self.end_of_word in node 
 
	def startsWith(self, prefix): 
		node = self.root 
		for char in prefix: 
			if char not in node: 
				return False 
			node = node[char] 
		return True
```

[C++实现链接](https://leetcode.com/problems/implement-trie-prefix-tree/discuss/58868/Implement-Trie-(Prefix-Tree)-C%2B%2B-Clean-Code-(array-or-map)) (array + map)

## 并查集 Disjoint Set

解决场景为组团和配对问题：需要很快的判断两个个体是否在一个团体中 （Group or not ?）

### 基本操作
makeSet(s):建立一个新的并查集，其中包含 s 个单元素集合。

unionSet(x, y):把元素 x 和元素 y 所在的集合合并，要求 x 和 y 所在的集合不相交，如果相交则不合并。

find(x):找到元素 x 所在的集合的代表，该操作也可以用于判断两个元 素是否位于同一个集合，只要将它们各自的代表比较一下就可以了。

### 并查集代码模板
```java
// Java
class UnionFind { 
	private int count = 0; 
	private int[] parent; 
	public UnionFind(int n) { 
		count = n; 
		parent = new int[n]; 
		for (int i = 0; i < n; i++) { 
			parent[i] = i;
		}
	} 
	public int find(int p) { 
		while (p != parent[p]) { 
			parent[p] = parent[parent[p]]; 
			p = parent[p]; 
		}
		return p; 
	}
	public void union(int p, int q) { 
		int rootP = find(p); 
		int rootQ = find(q); 
		if (rootP == rootQ) return; 
		parent[rootP] = rootQ; 
		count--;
	}
}
```

## 第14课 高级搜索

初级搜索
1. 朴素搜索
2. 优化方式: 不重复(fibonacci)、剪枝(生成括号问题)
3. 搜索方向:
	
	DFS: depth first search 深度优先搜索 
	
	BFS: breadth first search 广度优先搜索
	
	双向搜索、启发式搜索

### 启发式搜索

A*代码模板

```python
# Python
def AstarSearch(graph, start, end):
	pq = collections.priority_queue() # 优先级 —> 估价函数
	pq.append([start]) 
	visited.add(start)
	while pq: 
		node = pq.pop() # can we add more intelligence here ?
		visited.add(node)
		process(node) 
		nodes = generate_related_nodes(node) 
   		unvisited = [node for node in nodes if node not in visited]
		pq.push(unvisited)
```

## 第15课 AVL树和红黑树

平衡二叉树有很多种，具体可以看这个link: https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree 

大致要了解的平衡二叉树有: 

2-3 tree 

AVL tree 

B-Tree 

Red-black tree 

Splay tree 

如何保证一棵树的平衡？在每一步插入的时候就去判断它是否平衡，以及将它维护成平衡二叉树的状态

### AVL 树

1. 发明者 G. M. Adelson-Velsky 和 Evgenii Landis

2. Balance Factor(平衡因子): 是它的左子树的高度减去它的右子树的高度(有时相反)。 balance factor = {-1, 0, 1}

3. 通过旋转操作来进行平衡(四种)

4. https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree

### 旋转操作

右右子树 —> 左旋

左左子树 —> 右旋

左右子树 —> 左右旋

左右子树 —> 左右旋

### Red-black Tree

红黑树是一种近似平衡的二叉搜索树(Binary Search Tree)，它能够确保任何一个结点的左右子树的高度差小于两倍。具体来说，红黑树是满足如下条件的二叉搜索树:

• 每个结点要么是红色，要么是黑色

• 根节点是黑色

• 每个叶节点(NIL节点，空节点)是黑色的。

• 不能有相邻接的两个红色节点

• 从任一节点到其每个叶子的所有路径都包含相同数目的黑色节点。

### 对比
• AVL trees provide faster lookups than Red Black Trees because they are more strictly balanced.

• Red Black Trees provide faster insertion and removal operations than AVL trees as fewer rotations are done due to relatively relaxed balancing.

• AVL trees store balance factors or heights with each node, thus requires storage for an integer per node whereas Red Black Tree requires only 1 bit of information per node.

• Red Black Trees are used in most of the language libraries like map, multimap, multisetin C++ whereas AVL trees are used in databases where faster retrievals are required.