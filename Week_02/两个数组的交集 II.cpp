/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //效率太低
    //执行用时 :60 ms, 在所有 C++ 提交中击败了7.01%的用户
    //内存消耗 :11.3 MB, 在所有 C++ 提交中击败了7.41%的用户

    // vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    //     unordered_map<int, int> map1;
    //     unordered_map<int, int> map2;
    //     vector<int> a;

    //     for(int i = 0; i < nums1.size(); i++){
    //         ++map1[nums1[i]];
    //     }

    //     for(int i = 0; i < nums2.size(); i++){
    //         ++map2[nums2[i]];
    //     }
    //     unordered_map<int, int>:: iterator it1; 
    //     unordered_map<int, int>:: iterator it2; 
    //     for(it1 = map1.begin(); it1 != map1.end(); it1++){
    //         for(it2 = map2.begin(); it2 != map2.end(); it2++){
    //             if(it1->first == it2->first){
    //                 int n = min(it1->second, it2->second);
    //                 for(int i = 0; i < n; i++){
    //                     a.push_back(it1->first);
    //                 }
    //             }
    //         }
    //     }
    //     return a;
    // }

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //用 No.242 的思路 一个map, nums1->+, nums2->- 
        unordered_map<int, int> map;
        vector<int> a;

        for(int i = 0; i < nums1.size(); i++){
            ++map[nums1[i]];
        }

        for(int i = 0; i < nums2.size(); i++){
            if(map[nums2[i]]-- > 0){
                a.push_back(nums2[i]);
            }
        }
        return a;
    }
};