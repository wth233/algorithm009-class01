/*
给定一个非空二维矩阵 matrix 和一个整数 k，找到这个矩阵内部不大于 k 的最大矩形和。

示例:

输入: matrix = [[1,0,1],[0,-2,3]], k = 2
输出: 2 
解释: 矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
说明：

矩阵内的矩形区域面积必须大于 0。
如果行数远大于列数，你将如何解答呢？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0) return 0;

        int row_num = matrix.size(), col_num = matrix[0].size();
        int res = INT_MIN;

        for(int l = 0; l < col_num; ++l){
            vector<int> sums(row_num, 0);
            for(int r = l; r < col_num; ++r){
                for(int row = 0; row < row_num; ++row){
                    sums[row] += matrix[row][r];
                }

                // 2.Find the max subarray no more than K 
                res = max(MaxSubSum(sums, k), res);
            }
        }
        return res;
    }

    int MaxSubSum(vector<int>& sums, int k){
        int max_val = INT_MIN;
        for(int i = 0; i < sums.size(); ++i){
            int sum = 0;
            for(int j = i; j < sums.size();++j){
                sum += sums[j];
                if(sum <= k){
                    max_val = max(max_val, sum);
                }
            }
        }
        return max_val;
    }
};

// 1.矩形最大值 + 2.不超过k的1D数组连续一段的最大值