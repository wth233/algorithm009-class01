/*
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-segments-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int countSegments(string s) {
        return split(s, ' ').size();
    }

    // split function
    vector<string> split(string str, char a){
        vector<string> words;
        string s= "";
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == a){
                if(s.size())
                    words.push_back(s);
                s = "";
            }
            else{
                s += str[i];
            }
        }
        if(s.size()) words.push_back(s);

        return words;
    }
};