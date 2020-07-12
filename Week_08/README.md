# 学习心得

## 第16课 位运算

### 指定位置的位运算

1. 将x最右边的n位清零:x&(~0<<n)

2. 获取x的第n位值(0或者1):(x>>n)&1

3. 获取x的第n位的幂值:x&(1<<n)

4. 仅将第n位置为1:x|(1<<n)

5. 仅将第n位置为0:x&(~(1<<n))

6. 将x最高位至第n位(含)清零:x&((1<<n)-1)

7. 将第n位至第0位(含)清零:x&(~((1<<(n+1))-1))

### 实战位运算要点

• 判断奇偶:

x%2==1 —>(x&1)==1 x%2==0 —>(x&1)==0

• x>>1—>x/2.

即: x=x/2; —> x=x>>1;

mid=(left+right)/2; —> mid=(left+right)>>1;

• X=X&(X-1)清零最低位的1

• X&-X=>得到最低位的 1

• X&~X=>0

## 第17课 布隆过滤器和LRU缓存

### Bloom Filter vs Hash Table
一个很长的二进制向量和一系列随机映射函数。布隆过滤器可以用于检索一个元素**是否在一个集合中**。

优点是空间效率和查询时间都远远超过一般的算法，

缺点是有一定的误识别率和删除困难。

查不到一定不在，查到有可能在


### LRU Cache

• 两个要素: 大小 、替换策略

• Hash Table + Double LinkedList

• O(1) 查询 O(1) 修改、更新

```python
# Python 
class LRUCache(object): 
	def __init__(self, capacity): 
		self.dic = collections.OrderedDict() 
		self.remain = capacity
	def get(self, key): 
		if key not in self.dic: 
			return -1 
		v = self.dic.pop(key) 
		self.dic[key] = v   # key as the newest one 
		return v 
	def put(self, key, value): 
		if key in self.dic: 
			self.dic.pop(key) 
		else: 
			if self.remain > 0: 
				self.remain -= 1 
			else:   # self.dic is full
				self.dic.popitem(last=False) 
		self.dic[key] = value
```