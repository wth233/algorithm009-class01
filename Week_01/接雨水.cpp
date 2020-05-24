/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0, i = 0;
        stack<int> s;

        while (i < height.size()){
            while(!s.empty() && height[i] > height[s.top()]){
                int lowest = s.top();
                s.pop();

                //left -> s.top();
                //right -> i

                if(s.empty()) break;

                int h = min(height[s.top()], height[i]) - height[lowest];
                int l = i - s.top() - 1;

                area = area + h * l;
            }
            s.push(i);
            ++i;
        }
        return area;

    }
};