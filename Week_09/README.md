# 学习心得

## 第19课 高级动态规划

### 常见的 DP 题目和状态方程

1. 爬楼梯

    递归公式:
    f(n) = f(n - 1) + f(n - 2) , f(1) = 1, f(0) = 0

2. 不同路径

    递归公式:
    f(x, y) = f(x-1, y) + f(x, y-1)

3. 打家劫舍

    dp[i]状态的定义: max $ of robbing A[0 -> i]
    
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])

    或者， 2维技巧：

    dp[i][0]状态定义:max $ of robbing A[0 -> i] 且没偷 nums[i] 
    
    dp[i][1]状态定义:max $ of robbing A[0 -> i] 且偷了 nums[i]
    
    dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
    
    dp[i][1] = dp[i - 1][0] + nums[i];

4.  最小路径和

    dp[i][j]状态的定义: minPath(A[1 -> i][1 -> j])
    
    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + A[i][j]

5.  股票买卖

    初始状态:
     
     dp[-1][k][0] = dp[i][0][0] = 0
     dp[-1][k][1] = dp[i][0][1] = -infinity

    状态转移方程:
     
     dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
     
     dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
    
    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/yi-ge-fang-fa-tuan-mie-6-dao-gu-piao-wen-ti-by-l-3/


## 第20课 字符串算法

### 字符串匹配算法

1. 暴力法(brute force) - O(mn)

2. Rabin-Karp 算法

3. KMP 算法

•
课后了解:

Boyer-Moore 算法:
https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html 

Sunday 算法:
https://blog.csdn.net/u012505432/article/details/52210975

