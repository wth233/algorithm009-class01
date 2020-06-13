/*
一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。

假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。

例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。

与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。

现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变化次数。如果无法实现目标变化，请返回 -1。

注意:

起始基因序列默认是合法的，但是它并不一定会出现在基因库中。
所有的目标基因序列必须是合法的。
假定起始基因序列与目标基因序列是不一样的。
示例 1:

start: "AACCGGTT"
end:   "AACCGGTA"
bank: ["AACCGGTA"]

返回值: 1
示例 2:

start: "AACCGGTT"
end:   "AAACGGTA"
bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]

返回值: 2
示例 3:

start: "AAAAACCC"
end:   "AACCCCCC"
bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]

返回值: 3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-genetic-mutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        string char_array = "ACGT";

        unordered_set<string> bank_set(bank.begin(), bank.end());
        unordered_set<string> visited;

        if(bank_set.find(end) == bank_set.end() || bank.size() == 0) return -1;

        queue<string> Q;
        Q.push(start);

        int len = start.size();
        int step = 0;

        while(!Q.empty()){
            ++step;

            int curSize = Q.size();
            for(int i = 0 ; i < curSize; ++i){
                string now = Q.front();
                Q.pop();

                for(int j = 0; j < len; ++j){
                    char originchar = now[j];

                    for(int k = 0; k < char_array.size(); ++k){
                        now[j] = char_array[k];
                        if(bank_set.find(now) != bank_set.end()){
                            if(now == end) return step;
                            if(visited.find(now) == visited.end()){
                                Q.push(now);
                                visited.insert(now);
                            }
                        }
                    }
                    now[j] = originchar;
                }
            }
        }
        return -1;
    }
};