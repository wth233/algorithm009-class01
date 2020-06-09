/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/majority-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // unordered_map<int, int> hashmap;
        // for(int i = 0; i < nums.size(); ++i){
        //     ++hashmap[nums[i]];
        //     if(hashmap[nums[i]]> nums.size()/2) return nums[i];
        // }
        // return 0;

        //Divide and Conquer
        // a = [1, 2, 2, 2, 1, 1, 1, 1]
        // a1 = [1, 2, 2, 2] 众数是2
        // a2 = [1, 1, 1, 1] 众数是1
        // 不一样，比较一下1，2在a中的数量大小，发现1是众数

        return helper(nums, 0, nums.size() - 1);

    }

    int helper(vector<int>& nums, int left, int right){
        if(left == right) return nums[left];
        int mid = (left + right) / 2;

        int left_majority = helper(nums, left, mid);
        int right_majority = helper(nums, mid + 1, right);

        int left_count = majorityCount(nums, left, mid, left_majority);
        int right_count = majorityCount(nums, mid + 1, right, right_majority);

        return left_count > right_count? left_majority : right_majority;
    }

    int majorityCount(vector<int>& nums, int left, int right, int majority_num){
        int count;
        for(int i = left; i <= right; ++i){
            if(nums[i] == majority_num) ++count;
        }
        return count;
    }


};