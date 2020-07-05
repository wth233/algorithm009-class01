/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

示例:

输入: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//Trie Node class
class TrieNode{
public:
    TrieNode* children[26];
    string word = "";

    TrieNode(){
        for(int i = 0; i < 26; ++i){
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    int rows, cols;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if(board.size() == 0 || board[0].size() == 0) return res;

        rows = board.size();
        cols = board[0].size();

        TrieNode* root = new TrieNode();

        //create Trie
        for(auto word : words){
            TrieNode* cur = root;
            for(auto i : word){
                if(cur->children[i - 'a'] == nullptr){
                    cur->children[i - 'a'] = new TrieNode();
                }
                cur = cur->children[i - 'a']; 
            }
            cur->word = word;
        }

        //DFS
        for(int i = 0 ; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                DFS(root, i, j, board, res);
            }
        }
        return res;
    }

    void DFS(TrieNode* root, int row, int col, vector<vector<char>>& board, vector<string>& res){
        char origin_char = board[row][col];
        if(board[row][col] == '@' || root->children[board[row][col] - 'a'] == nullptr) return;

        root = root->children[board[row][col] - 'a'];

        if(root->word != ""){
            res.push_back(root->word);
            root->word = ""; //防止重复
        }

        board[row][col] = '@';
        if(row > 0) DFS(root, row - 1, col, board, res);
        if(col > 0) DFS(root, row, col - 1, board, res);
        if(row + 1 < rows) DFS(root, row + 1, col, board, res);
        if(col + 1 < cols) DFS(root, row, col + 1, board, res);

        board[row][col] = origin_char;
    }
};

//1. create Trie
//2. board DFS