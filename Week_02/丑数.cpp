/*
我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  

1 是丑数。
n 不超过1690。
注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chou-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        // uglynumber = 2^x * 3^y * 5^z
        vector<int> nums;
        nums.push_back(1);

        int x = 0, y = 0, z = 0;

        for(int i = 1; i < n; ++i){
            const int next2 = nums[x] * 2;
            const int next3 = nums[y] * 3;
            const int next5 = nums[z] * 5;

            const int next = min(next2, min(next3, next5));
            nums.push_back(next);

            if(next == next2) ++x;
            if(next == next3) ++y;
            if(next == next5) ++z;
        }

        return nums[n - 1];
    }
};