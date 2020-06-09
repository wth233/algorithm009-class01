/*
示例:

输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));

        helper(res, temp, 0, n);

        return res;
    }

    void helper(vector<vector<string>>& res, vector<string>& temp, int row, int n){
        if(row == n){
            res.push_back(temp);
            return;
        }

        for(int col = 0; col < n; ++col){
            if(isVaild(temp, row, col, n)){
                temp[row][col] = 'Q';
                helper(res, temp, row + 1, n);
                temp[row][col] = '.';
            }
        }
    }

    bool isVaild(vector<string>& temp, int row, int col, int n){
        for(int i = 0; i < row ; ++i){
            if(temp[i][col] == 'Q') return false;
        }

        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0 ; --i, --j){
            if(temp[i][j] == 'Q') return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < n ; --i, ++j){
            if(temp[i][j] == 'Q') return false;
        }
        return true;
    }
};