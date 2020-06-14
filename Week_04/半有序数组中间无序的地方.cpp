/*
使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方
说明：同学们可以将自己的思路、代码写在第 4 周的学习总结中
*/
class Solution{
public:
    int find_unordered_place(vector<int>& nums){

        if(nums.empty()) return -1;

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int mid = (l + r) >> 1;

            if(mid + 1 <= nums.size() - 1 && nums[mid] > nums[mid + 1]) return mid + 1;
            if(mid - 1 >= 0 && nums[mid - 1] > nums[mid]) return mid;

            if(nums[l] <= nums[mid]){
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

int main(){
    Solution s;
    vector<int> nums1 = {3, 4, 5, 6, 0, 1, 2};
    cout<<s.find_unordered_place(nums1)<<endl; //4

    vector<int> nums2 ={1, 2, 3, 4};
    cout<<s.find_unordered_place(nums2)<<endl; //-1

    vector<int> nums3 ={3, 4, 0, 1, 2};
    cout<<s.find_unordered_place(nums3)<<endl; //2

    vector<int> nums4 ={2, 2, 2};
    cout<<s.find_unordered_place(nums4)<<endl; //-1
}