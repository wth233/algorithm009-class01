/*
让我们一起来玩扫雷游戏！

给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：

如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。
 

示例 1：

输入: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

输出: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

解释:

示例 2：

输入: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

输出: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

解释:


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minesweeper
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
        //方向：上，下，左，右，左上，右上，左下，右下
        if(board.size() == 0 || board[0].size() == 0) return board;
        int row = board.size() - 1, col = board[0].size() - 1;
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        helper(board, click[0], click[1], row, col, dir);
        return board;
    }

    void helper(vector<vector<char>>& board, int cur_row, int cur_col, int row, int col, vector<vector<int>>& dir){
        //没越界 + 当前不是雷 dfs
        if(cur_row >= 0 && cur_row <= row && cur_col >= 0 && cur_col <= col && board[cur_row][cur_col] == 'E'){
            int count = 0;
            for(int i = 0 ; i < dir.size(); ++i){
                //扫查四周的雷
                if(cur_row + dir[i][0]>= 0 && cur_row + dir[i][0] <= row && cur_col + dir[i][1]>= 0 && cur_col + dir[i][1] <= col && board[cur_row + dir[i][0]][cur_col + dir[i][1]] == 'M') ++count;
            }

            if(count == 0){
                board[cur_row][cur_col] = 'B';
                for(int i = 0 ; i < dir.size(); ++i){
                    helper(board, cur_row + dir[i][0], cur_col + dir[i][1], row, col, dir);
                }
            }
            else{
                board[cur_row][cur_col] = count + '0';
            }
        }
    }


};
//深度优先遍历，遍历的先决条件某点不是地雷，同时检查八个方向是否有地雷，没地雷就dfs