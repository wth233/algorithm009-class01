/*
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> words;
        split(words, str, ' ');

        if(words.size() != pattern.length())
            return false;
        for(int i = 0; i < pattern.length(); i++){
            for(int j = i + 1; j < pattern.length(); j++){
                if((pattern[i] == pattern[j] && words[i] != words[j]) ||
                    (pattern[i] != pattern[j] && words[i] == words[j]))
                    return false;
            }
        }
        return true;

    }

    //split function
    vector<string> split(vector<string>& words, string str, char a){
        string s;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == a){
                if(s.size()){
                    words.push_back(s);
                }
                s = "";
            }
            else{
                s += str[i];
            }
        }
        if(s.size())
            words.push_back(s);
        
        return words;
    }
        
};