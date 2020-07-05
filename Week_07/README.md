# 学习心得

## 第13课 字典树和并查集

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

