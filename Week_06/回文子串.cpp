/*
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindromic-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j] -> s[i...j]是否是回文子串
        //dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]

        if(s.size() == 0) return 0;
        int res = s.size();

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for(int i = 0; i < s.size(); ++i){
            dp[i][i] = true;
        }
        for(int i = s.size() - 1; i >= 0 ; --i){ //为什么不能从前往后？因为要从左下方获得值
            for(int j = i + 1; j < s.size(); ++j){
                if(s[i] == s[j]){
                    //bb
                    if(j - i == 1){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if(dp[i][j]) ++res;
            }
        }
        return res;

    }
};