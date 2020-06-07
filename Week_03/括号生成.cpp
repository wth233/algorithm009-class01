/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        recur(n, 0, 0, "");
        return res;
    }

    void recur(int n, int left, int right, string s){
        //terminator
        if(left == n && right == n){
            res.push_back(s);
            return;
        } 
        
        //process logic

        //drill down
        if(left < n) recur(n, left + 1, right, s + '(');
        if(left > right ) recur(n, left, right + 1, s + ')');

    }
};

//3 left， 3 right
//left 只没用完一直可以加
//right 没用完 + left > right 可以加