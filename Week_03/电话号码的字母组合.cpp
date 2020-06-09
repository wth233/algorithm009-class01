/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if(digits.size() == 0) return res;

        unordered_map<char, string> mymap = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};


        helper(res, mymap, digits, "", 0);

        return res;
    }

    void helper(vector<string>& res, unordered_map<char, string> mymap, string digits, string letter, int index){
        if(index == digits.size()){
            res.push_back(letter);
            return;
        }

        string letters = mymap[digits[index]];
        for(int i = 0; i < letters.size(); ++i){
            letter = letter + letters[i];
            helper(res, mymap, digits, letter, index + 1);
            letter.pop_back();
        }
        
    }
};