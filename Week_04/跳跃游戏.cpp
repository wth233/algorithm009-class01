/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例 2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:

    //recursive 超时
    // bool canJump(vector<int>& nums) {
    //     if(nums.size() == 0) return false;
    //     return helper(nums, 0);
    // }

    // bool helper(vector<int>& nums, int index){
    //     if(index == nums.size() - 1){
    //         return true;
    //     }

    //     for(int i = 1; i <= nums[index]; ++i){
    //         if(helper(nums, i + index)) return true;
    //     }
    //     return false;
    // }

    //建一个数组 第一位为 true 剩下为false 超时
    // bool canJump(vector<int>& nums){
    //     if(nums.size() == 0) return false;
    //     vector<bool> flag(nums.size(), false);
    //     flag[0] = true;

    //     for(int i = 0; i < nums.size(); ++i){
    //         int index = nums[i];
    //         for(int j = 1; j <= index; ++j){
    //             flag[i + j] = true;
    //         }
    //     }

    //     for(int i = 0; i < flag.size(); ++i){
    //         if(flag[i] == false) return false;
    //     }
    //     return true;
    // }

    //贪心
    bool canJump(vector<int>& nums){
        if(nums.size() == 0) return false;

        int max_distance = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            if(i <= max_distance){
                max_distance = max(max_distance, i + nums[i]);
            }
            else
                break;
        }
        return max_distance >= nums.size() - 1;
    }
};