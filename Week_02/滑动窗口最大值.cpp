/*
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

 

进阶：

你能在线性时间复杂度内解决此题吗？

 

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 

提示：

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-maximum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class MonotonicQueue{
private:
    deque<int> d;

public:
    void push(int e){
        while(!d.empty() && e > d.back()){
            d.pop_back();
        }
        d.push_back(e);
    }

    void pop(){
        d.pop_front();
    }

    int max(){ return d.front();}

};

class Solution {
public:
    //暴力超时间
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> res;
    //     for(int i = 0; i < nums.size() - k + 1; i++){
    //         res.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
    //     }
    //     return res;
    // }

    //维护一个单调 deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue d;
        vector<int> res;

        for(int i = 0; i < nums.size(); ++i){
            if(i - k + 1 < 0){
                d.push(nums[i]);
            }
            else{
                d.push(nums[i]);
                res.push_back(d.max());
                if(nums[i - k + 1] == d.max()) d.pop(); 
                //i - k + 1为滑动窗口要滑走的第一位元素下标
            }

        }
        return res;
    }
};
