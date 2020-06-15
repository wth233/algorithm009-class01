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
    vector<int> twoSum(vector<int>& nums, int target) {
        //暴力 O(n^2)
        //i: 0 ~ size, j: i ~ size, nums[j] == target - nums[i]，放res return
        // vector<int> res;
        // for(int i = 0; i < nums.size(); ++i){
        //     for(int j = i + 1; j < nums.size(); ++j){
        //         if(nums[j] == target - nums[i]){
        //             res.push_back(i);
        //             res.push_back(j);
        //         }
        //     }
        // }
        // return res;

        //hash O(n)
        //一遍hash先存 数:下标
        //两遍hash找target - nums[i]，且不能是当前下标
        // vector<int> res;
        // unordered_map<int, int> hashmap;
        // for(int i = 0; i < nums.size(); ++i){
        //     hashmap[nums[i]] = i;
        // }
        // unordered_map<int, int>::iterator it;
        
        // for(int i = 0; i < nums.size(); ++i){
        //     if(hashmap.find(target - nums[i]) != hashmap.end() 
        //     && hashmap[target - nums[i]] != i){
        //         res.push_back(i);
        //         res.push_back(hashmap[target - nums[i]]);
        //         return res;
        //     }
        // }
        // return {};

        //一遍hash
        vector<int> twoSum(vector<int>& nums, int target){
            vector<int> res;
            unordered_map<int, int> hashmap;

            for(int i = 0; i < nums.size(); ++i){

                if(hashmap.find(target - nums[i]) != hashmap.end()){
                    res.push_back(hashmap[target - nums[i]]);
                    res.push_back(i);
                    return res;
                }
                hashmap[nums[i]] = i;
            }
        return {};
    }

    }
};