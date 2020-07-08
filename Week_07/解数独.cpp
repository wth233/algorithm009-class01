/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。


Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return;
        helper(board);
    }

    bool helper(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == '.'){
                    for(char k = '1'; k <= '9'; ++k){
                        if(isVaild(board, i, j, k)){
                            board[i][j] = k;
                            if(helper(board)){
                                return true;
                            }
                            board[i][j] = '.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isVaild(vector<vector<char>>& board, int row, int col, char k){
        for(int i = 0; i < 9; ++i) {
            if(board[i][col] == k) return false;
            if(board[row][i] == k) return false;
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k) return false;
        }
        return true;
    }
};