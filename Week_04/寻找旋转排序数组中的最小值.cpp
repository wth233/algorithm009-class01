/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];

        int l = 0;
        int r = nums.size() - 1;

        if(nums[0] < nums[r]) return nums[0];

        while(l <= r){
            int mid = (l + r) >> 1;

            if(mid + 1 <= nums.size() - 1 && nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]) return nums[mid];

            if(nums[l] < nums[mid]){
                //左边有序 查右边
                l = mid + 1;
            }
            else{
                //右边有序 查左边
                r = mid - 1;
            }
        }
        return -1;
    }
};