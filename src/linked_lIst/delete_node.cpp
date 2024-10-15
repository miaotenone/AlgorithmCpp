// 倒数第几个应使用双指针法，先将一个移动n，再移动至终点
// Created by 14771 on 2024/9/19.
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//进阶：你能尝试使用一趟扫描实现吗？
// 输入：head = [1,2,3,4,5], n = 2 输出：[1,2,3,5]
//输入：head = [1], n = 1 输出：[]
//输入：head = [1,2], n = 1 输出：[1]

#include "../utils/common_ds.h"

class Solution{
public:
    // fastptr moves n,slowptr and fastptr move the end of ll together
    ListNode* delete_node(ListNode* head, int count_backwards){
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* fastptr = dummynode;
        ListNode* slowptr = dummynode;
        for (int i = 0; i < count_backwards; ++i) {
            if (fastptr->next== nullptr){
                return nullptr;
            }
            fastptr = fastptr->next;
        }
        while (fastptr->next!=nullptr){
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        slowptr->next = slowptr->next->next;
        head = dummynode->next;
        delete dummynode;
        return head;
    }
};

int main(){
    const char* listnode_s = "1->2->6->3->4->5->6";
    ListNode* head = parse_list(listnode_s);
    Solution sl;
    ListNode* res = sl.delete_node(head,2);
    string res_list = to_string(res);
    cout<<res_list<<endl;
}