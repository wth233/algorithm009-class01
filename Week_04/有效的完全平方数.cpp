/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-perfect-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:

    //二分
    //left = 2， right = num/2， mid = (left+right)/2
    //若 mid * mid > num => right = mid - 1，否则 left = mid + 1
    //循环走完 没有找到返回false
    // bool isPerfectSquare(int num) {
    //     if(num < 2) return true;

    //     long left = 2;
    //     long right = num / 2;

    //     while(left <= right){
    //         long mid = left + (right - left) / 2;
    //         if(mid * mid == num) return true;
    //         if(mid * mid > num) right = mid - 1;
    //         if(mid * mid < num) left = mid + 1;
    //     }
    //     return false;
    // }

    //牛顿迭代最后得到 Xk+1 = 1/2(Xk + num/Xk)
    // bool isPerfectSquare(int num) {
    //     if(num < 2) return true;

    //     long x = num / 2; 
    //     while(x * x > num){
    //         x = (x + num / x) / 2;
    //     }
    //     return (x * x == num);

    // }

    //数学规律
    // 1 4=1+3 9=1+3+5 16=1+3+5+7
    bool isPerfectSquare(int num){
        int odd = 1;
        while(num > 0){
            num -= odd;
            odd += 2;
        }

        return (num == 0);
    }
};