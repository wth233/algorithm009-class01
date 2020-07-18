/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

示例 1:

输入: "aba"
输出: True
示例 2:

输入: "abca"
输出: True
解释: 你可以删除c字符。
*/
class Solution {
public:
    bool validPalindrome(string s) {
        int low = 0, high = s.size() - 1;

        while(low < high){
            if(s[low] == s[high]){
                ++low;
                --high;
            }
            else{
                return check(s, low + 1, high) || check(s, low, high - 1);
            }
        }
        return true;
    }

    bool check(string s, int low, int high){
        for(int i = low, j = high; i < j; ++i, --j){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};