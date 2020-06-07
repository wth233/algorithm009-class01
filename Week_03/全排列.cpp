/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;

        helper(res, temp, nums, 0);

        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int> nums, int count){
        if(count == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
            temp.push_back(nums[i]);
            helper(res, temp, nums, count + 1);
            temp.erase(temp.end() - 1);
        }
    }
};