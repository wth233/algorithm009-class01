/*
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
示例 1:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
输出: true
示例 2:

输入:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     if(matrix.size() == 0 || matrix[0].size() == 0) return false;

    //     vector<int> temp;
    //     for(int i = 0; i < matrix.size(); ++i)
    //         for(int j = 0; j < matrix[0].size(); ++j)
    //             temp.push_back(matrix[i][j]);

    //     int l = 0, r = temp.size() - 1;
    //     while(l <= r){
    //         int mid = (l + r) >> 1;
    //         if(temp[mid] == target) return true;

    //         if(temp[mid] < target) l = mid + 1;
    //         if(temp[mid] > target) r = mid - 1;
    //     }
    //     return false;
    // }

    //不开辟新数组 用二维矩阵直接二分
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int m = matrix.size(), n = matrix[0].size();

        int l = 0, r = m * n - 1;

        while(l <= r){
            int mid_index = (l + r) >> 1;
            int mid_element = matrix[mid_index / n][mid_index % n];
            if(mid_element == target) return true;

            if(mid_element < target) l = mid_index + 1;
            if(mid_element > target) r = mid_index - 1;
        }
        return false;
    }
};