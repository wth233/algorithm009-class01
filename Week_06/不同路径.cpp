/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右
示例 2:

输入: m = 7, n = 3
输出: 28

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 && n == 0) return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for(int i = 0; i < n; ++i){
            dp[i][m - 1] = 1;
        }

        for(int j = 0; j < m; ++j){
            dp[n - 1][j] = 1;
        }

        for(int i = n - 2; i >= 0; --i){
            for(int j = m - 2; j >= 0; --j){
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];

    }
};