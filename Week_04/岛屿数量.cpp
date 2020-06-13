/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1:

输入:
11110
11010
11000
00000
输出: 1
示例 2:

输入:
11000
11000
00100
00011
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int num = 0;

        for(int row = 0; row < grid.size(); ++row)
            for(int col = 0; col < grid[0].size(); ++col){
                if(grid[row][col] == '1'){
                    ++num;
                    dfs(grid, row, col);
                }
            }
        
        return num;

    }

    void dfs(vector<vector<char>>& grid, int row, int col){
        grid[row][col] = '0';
        if(row - 1 >= 0 && grid[row - 1][col] == '1') dfs(grid, row - 1, col);
        if(col - 1 >= 0 && grid[row][col - 1] == '1') dfs(grid, row, col - 1);
        if(row + 1 < grid.size() && grid[row + 1][col] == '1') dfs(grid, row + 1, col);
        if(col + 1 < grid[0].size() && grid[row][col + 1] == '1') 
            dfs(grid, row, col + 1);
    }
};