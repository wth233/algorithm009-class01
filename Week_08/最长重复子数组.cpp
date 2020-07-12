/*
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例：

输入：
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：
长度最长的公共子数组是 [3, 2, 1] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //dp[i][j] A[0~i], B[0~j]最长公共子数组长度

        //A[i - 1] == B[j - 1] dp[i][j] = dp[i - 1][j - 1] + 1
        //A[i - 1] != B[j - 1] dp[i][j] = 0;
        //  dp[i][j] = max(dp[i-1][j-1]+(A[i-1] == B[j-1]?1:0),dp[i-1][j],dp[i][j-1])

        if(A.size() == 0 || B.size() == 0) return 0;
        int res = 0;

        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

        dp[0][0] = 0;

        for(int i = 1; i <= A.size(); ++i){
            for(int j = 1; j <= B.size(); ++j){
                if(A[i - 1] == B[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return res;

    }
};