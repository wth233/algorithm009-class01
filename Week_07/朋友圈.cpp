/*
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。

给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:

输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:

输入: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
注意：

N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/friend-circles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
public:
    //DFS
    // int findCircleNum(vector<vector<int>>& M) {
    //     if(M.size() == 0 || M[0].size() == 0) return 0;

    //     vector<int> visited(M.size(), 0);

    //     int res = 0;

    //     for(int i = 0; i < M.size(); ++i){
    //         if(visited[i] == 0){
    //             ++res;
    //             dfs(M, visited, i);
    //         }
    //     }
    //     return res;
    // }

    // void dfs(vector<vector<int>>& M, vector<int>& visited, int i){
    //     for(int j = 0; j < M.size(); ++j){
    //         if(M[i][j] == 1 && visited[j] == 0){
    //             visited[j] = 1;
    //             dfs(M, visited, j);
    //         }
    //     }
    // }

    //并查集
    /*find的作用是找到一个元素所在集合的代表元素；
    union的作用就是将两个元素分别所在的集合合并成一个集合，就是将其中一个元素的代表元素变成另一个元素的代表元素*/

    int count = 0;
    int find(vector<int>& parent, int p){
        while(parent[p] != p){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    void Union(vector<int>& parent, int p, int q){
        int rootP = find(parent, p); 
		int rootQ = find(parent, q); 
		if (rootP == rootQ) return; 
        parent[rootP] = rootQ;
        --count;
    }

    int findCircleNum(vector<vector<int>>& M) {
        vector<int> parent(M.size(), 0);

        count = M.size();

        for(int i = 0; i < parent.size(); ++i){
            parent[i] = i;
        }

        for(int i = 0; i < M.size(); ++i){
            for(int j = 0; j < M[0].size(); ++j){
                if(M[i][j] == 1){
                    Union(parent, i, j);
                }
            }
        }

        return count;
    }
};