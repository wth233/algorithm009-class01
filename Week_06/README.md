# 学习心得

## 第12课 动态规划

存最优解：缓存数组 + 每一步淘汰次优的状态

### 关键点

动态规划 和 递归或者分治 没有根本上的区别(关键看有无最优的子结构)

**共性:找到重复子问题**

差异性:最优子结构、中途可以淘汰次优解

### Fibonacci 记忆式递归
``` c++
int fib (int n, int[] memo) {
  if (n <= 1) {
    return n;
    }
  if (memo[n] == 0) {
    memo[n] = fib (n - 1) + fib (n - 2);
  }
  return memo[n];
}
```
O(2^n) -> O(n) (Memoization)

### 动态规划关键点

1. 最优子结构 opt[n] = best_of(opt[n-1], opt[n-2], ...)

2. 储存中间状态:opt[i]

3. 递推公式(美其名曰:状态转移方程或者 DP 方程)

    Fib: opt[i] = opt[n-1] + opt[n-2]

    二维路径:opt[i,j] = opt[i+1][j] + opt[i][j+1] (且判断a[i,j]是否空地)

