/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1

示例:

输入: [2,1,5,6,2,3]
输出: 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-rectangle-in-histogram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //暴力 枚举
        // if(heights.size() == 0) return 0;
        // if(heights.size() == 1) return heights[0];
        // int area = 0;
        // for(int i = 0; i < heights.size(); ++i){
        //     for(int j = i; j < heights.size(); ++j){
        //         int min_height = *min_element(heights.begin() + i, heights.begin() + j + 1);
        //         int length = j - i + 1;
        //         area = max(area, min_height * length);
        //     }
        // }
        // return area;

        //单调栈
        stack<int> s;
        s.push(-1);
        int area = 0;

        if(heights.size() == 0) return 0;
        if(heights.size() == 1) return heights[0];

        for(int i = 0; i < heights.size(); ++i){
            while(s.top() != -1 && heights[i] <= heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                int l = i - s.top() - 1;
                area = max(area, h * l);
            }
            s.push(i);
        }

        // case [1, 1]
        while (s.top() != -1){
            int h = heights[s.top()];
            s.pop();
            int l = heights.size() - s.top() - 1;
            area = max(area, h * l);

        }

        return area;


    }
};