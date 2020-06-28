/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(i == 0 && j == 0){
                    continue;
                } 
                else if(i == 0){
                    //只能从左边来
                    grid[i][j] = grid[i][j - 1] + grid[i][j];
                }
                else if(j == 0){
                    //只能从上边来
                    grid[i][j] = grid[i - 1][j] + grid[i][j];
                }
                else{
                    grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
                }
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};