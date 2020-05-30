/*
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        vector<vector<string>> res;
        temp = strs;

        unordered_map<string, vector<int>> mymap;

        for(int i = 0; i < strs.size(); ++i){
            sort(strs[i].begin(), strs[i].end());
            mymap[strs[i]].push_back(i);
        }

        unordered_map<string, vector<int>>:: iterator it;
        for(it = mymap.begin(); it != mymap.end(); ++it){
            vector<string> a;
            for(int i = 0; i < it->second.size(); ++i){
                a.push_back(temp[it->second[i]]);
            }
            res.push_back(a);
        }
        return res;
    }
};