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

## 第18课 排序算法

### 快排代码

```java
/ Java
public static void quickSort(int[] array, int begin, int end) {
    if (end <= begin) return;
    int pivot = partition(array, begin, end);
    quickSort(array, begin, pivot - 1);
    quickSort(array, pivot + 1, end);
}
static int partition(int[] a, int begin, int end) {
    // pivot: 标杆位置，counter: 小于pivot的元素的个数
    int pivot = end, counter = begin;
    for (int i = begin; i < end; i++) {
        if (a[i] < a[pivot]) {
            int temp = a[counter]; a[counter] = a[i]; a[i] = temp;
            counter++;
        }
    }
    int temp = a[pivot]; a[pivot] = a[counter]; a[counter] = temp;
    return counter;
}
```

### 归并排序
```java
// Java

public static void mergeSort(int[] array, int left, int right) {
    if (right <= left) return;
    int mid = (left + right) >> 1; // (left + right) / 2

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
}

public static void merge(int[] arr, int left, int mid, int right) {
        int[] temp = new int[right - left + 1]; // 中间数组
        int i = left, j = mid + 1, k = 0;

        while (i <= mid && j <= right) {
            temp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        }

        while (i <= mid)   temp[k++] = arr[i++];
        while (j <= right) temp[k++] = arr[j++];

        for (int p = 0; p < temp.length; p++) {
            arr[left + p] = temp[p];
        }
        // 也可以用 System.arraycopy(a, start1, b, start2, length)
    }
```

归并 和 快排 具有相似性，但步骤顺序相反

归并:先排序左右子数组，然后合并两个有序子数组

快排:先调配出左右子数组，然后对于左右子数组进行排序

### 堆排序

堆排序代码 - C++
```c++
void heap_sort(int a[], int len) {
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 0; i < len; i++) {
        q.push(a[i]);
	}
    for(int i = 0; i < len; i++) {
        a[i] = q.pop();
	} 
} 
```
Java手动维护堆

```java
// Java
static void heapify(int[] array, int length, int i) {
    int left = 2 * i + 1, right = 2 * i + 2；
    int largest = i;
    if (left < length && array[left] > array[largest]) {
        largest = left;
    }
    if (right < length && array[right] > array[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = array[i]; array[i] = array[largest]; array[largest] = temp;
        heapify(array, length, largest);
    }
}
public static void heapSort(int[] array) {
    if (array.length == 0) return;
    int length = array.length;
    for (int i = length / 2-1; i >= 0; i-) 
        heapify(array, length, i);
    for (int i = length - 1; i >= 0; i--) {
        int temp = array[0]; array[0] = array[i]; array[i] = temp;
        heapify(array, i, 0);
    }
}
```
十大经典排序算法（动图演示）

https://www.cnblogs.com/onepixel/p/7674659.html