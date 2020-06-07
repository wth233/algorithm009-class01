/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
 

限制：

0 <= 链表长度 <= 10000
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;

        // while(head != nullptr){
        //     res.push_back(head->val);
        //     head = head->next;
        // }
        // reverse(res.begin(), res.end());

        // return res;

        //若用递归 要定义成员变量 vector<int> res
        //若用stack，先依次压入再弹出存到res中

        //改变链表的方法

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;

        while(cur != nullptr){
            next = cur->next;

            cur->next = pre;

            pre = cur;
            cur = next;
        }

        while(pre){
            res.push_back(pre->val);
            pre = pre->next;
        }

        return res;
    }
};