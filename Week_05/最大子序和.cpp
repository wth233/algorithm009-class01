/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:

    //暴力法 固定头指针i，移动尾指针j, 找max
    //O(n^2)
    // int maxSubArray(vector<int>& nums) {
    //     int max_val = INT_MIN;

    //     for(int i = 0; i < nums.size(); ++i){
    //         int sum = 0;
    //         for(int j = i; j < nums.size(); ++j){
    //             sum += nums[j];
    //             if(sum > max_val) max_val = sum;
    //         }
    //     }

    //     return max_val;
    // }

    //dp
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, 0);
    //     dp[0] = nums[0];
    //     int max_val = dp[0];

    //     //dp[i]表示nums中以nums[i]结尾的最大子序和
    //     for(int i = 1; i < n; ++i){
    //         dp[i] = max(dp[i - 1] + nums[i], nums[i]);
    //         max_val = max(max_val, dp[i]);
    //     }
    //     return max_val;
        
    // }

    //Greedy
    //从左到右 如果sum<0重新找子串，再比较max
    int maxSubArray(vector<int>& nums) {
        int max_val = INT_MIN;
        int sum = 0;

        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            max_val = max(max_val, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return max_val;
    }
};