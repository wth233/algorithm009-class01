/*
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

示例 1:

输入: "12"
输出: 2
解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2:

输入: "226"
输出: 3
解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int numDecodings(string s) {
        //dp[i] 0~i可以组成的解码数
        if(s[0] == '0') return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 1; i < s.size(); ++i){
            if(s[i] == '0'){
                if(s[i - 1] == '1' || s[i - 1] == '2'){
                    dp[i + 1] = dp[i - 1];
                } 
                else{
                    return 0;
                }
            }
            else if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6' && s[i] >= '0')){
                dp[i + 1] = dp[i] + dp[i - 1];
            }
            else{
                dp[i + 1] = dp[i];
            }
        }
        return dp[s.size()];
    }
};