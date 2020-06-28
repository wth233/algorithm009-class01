/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    // 左递归 && 右在dict

    //memory
    // unordered_map<string, bool> mem;

    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> dict(wordDict.begin(), wordDict.end());
    //     return helper(s, dict);
    // }

    // bool helper(string s, unordered_set<string>& dict){
    //     if(mem.count(s)) return mem[s];
    //     if(dict.count(s)){
    //         mem[s] = true;
    //         return mem[s];
    //     }

    //     //split
    //     for(int i = 0; i < s.size(); ++i){
    //         string left = s.substr(0, i);
    //         string right = s.substr(i);

    //         if(dict.count(right) && helper(left, dict))
    //             return true;
    //     }

    //     mem[s] = false;
    //     return mem[s];
    // }

    //dp[i] = dp[j] && check(s[j...i-1])
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);

        dp[0] = true;

        for(int i = 1; i <= s.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(dp[j] && dict.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};