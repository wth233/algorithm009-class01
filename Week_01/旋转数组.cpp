/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:

输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:

尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        //暴力
        // int n = nums.size();
        // k %= n;
        // for(int j = 0; j < k; j++){
        //     int temp = nums[n- 1];
        //     for(int i = n - 1 - 1; i >= 0; i--){
        //         nums[i + 1] = nums[i];
        //     }
        //     nums[0] = temp;
        // }

        //旋转数组
        /*
        k%n 个尾部元素会被移动到头部，剩下的元素会被向后移动。
        1.将所有元素反转 2. 然后反转前 k 个元素 3.再反转后面 n−k 个元素

        原始数组                  : 1 2 3 4 5 6 7
        反转所有数字后             : 7 6 5 4 3 2 1
        反转前 k 个数字后          : 5 6 7 4 3 2 1
        反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果
        */

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k % nums.size());
        reverse(nums.begin() + k % nums.size(), nums.end());

    }
};