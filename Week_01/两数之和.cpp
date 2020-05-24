/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

 

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //暴力法
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> result;
    //     for(int i = 0; i < nums.size(); i++){
    //         int new_target = target - nums[i];
    //         for(int j = i+1; j<nums.size();j++){
    //             if(nums[j] == new_target){
    //                 result.push_back(i);
    //                 result.push_back(j);
    //                 }
    //         }
    //     }
    //     if(result.size()!=0)
    //         return result;
    //     else{
    //         result = {-1, -1};
    //         return result;
    //     }
    // }

    //hash map
    vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> record;
    vector<int> result;
    for(int i = 0 ; i < nums.size() ; i ++){
        int complement = target - nums[i];
        if(record.find(complement)!= record.end()) {
            result.push_back(record[complement]);
            result.push_back(i);
            return result;
        }
        record[nums[i]] = i;
    }
    return {-1, -1};
}
};