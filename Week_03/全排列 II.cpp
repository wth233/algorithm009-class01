/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        helper(res, temp, nums, visited);

        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int> nums, vector<bool>& visited){
        if(temp.size() == nums.size()){
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); ++i){
            if(visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) continue;
            
            temp.push_back(nums[i]);
            visited[i] = true;
            helper(res, temp, nums, visited);
            temp.erase(temp.end() - 1);
            visited[i] = false;
            
        }
    }
};