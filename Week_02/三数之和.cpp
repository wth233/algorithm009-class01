/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //双指针
        //1.排序
        //2. -4 -1 -1 0 1 2
        //    |  |        |
        //    k  i        j
        // nums[i] + nums[j] = - nums[k]
        // If nums[i] + nums[j] < - nums[k], => i 右移
        // If nums[i] + nums[j] > - nums[k], => j 左移

        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        sort(nums.begin(), nums.end());

        for(int k = 0; k < nums.size() - 1; ++k){
            int i = k + 1;
            int j = nums.size() - 1;

            if(k > 0 && nums[k] == nums[k - 1]) continue;
            
            while(i != j){
                vector<int> temp;
                int s = nums[i] + nums[j];
                if(s < -nums[k]){
                    while(i < j && nums[i] == nums[++i]);//判重操作 **
                }
                else if(s > -nums[k]){
                    while(i < j && nums[j] == nums[--j]);
                }
                else{
                    temp.push_back(nums[k]);
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    res.push_back(temp);

                    while(i < j && nums[i] == nums[++i]);
                    while(i < j && nums[j] == nums[--j]);
                }
                
            }

            
        }
        return res;

    }
};