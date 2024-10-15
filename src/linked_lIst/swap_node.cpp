//
// Created by 14771 on 2024/9/19.
//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//你不能只是单纯地改变节点内部的值，而是需要实际的进行节点交换。

#include "../utils/common_ds.h"

class Solution{
public:
    ListNode* swap_node(ListNode* head){
        if (head== nullptr||head->next== nullptr) return nullptr;
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head;
        ListNode* cur = dummynode;//0
        ListNode* next = cur->next;//1
        ListNode* nnext = next->next;//2

        while (cur->next!= nullptr && next->next!=nullptr){
            ListNode* temp = nnext->next;
            cur->next = nnext;
            nnext->next = next;
            next->next = temp;
            cur = next;
            next = cur->next;
            nnext = next->next;
        }
        head = dummynode->next;
        delete dummynode;
        return head;
    }
};
int main(){
    const char* listnode_s = "1->2->6->3->4->5->6";
    ListNode* head = parse_list(listnode_s);
    Solution sl;
    ListNode* res = sl.swap_node(head);
    string res_list = to_string(res);
    cout<<res_list<<endl;
}
