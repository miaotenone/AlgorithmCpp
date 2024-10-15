//
// Created by 14771 on 2024/9/19.
//题意： 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
//-------------------------------------------------------
//从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点。
#include "../utils/common_ds.h"

class Solution{
public:
    ListNode* is_circular_ll(ListNode* head){
        if(head->next== nullptr||head->next->next== nullptr){return nullptr;}
        ListNode* fast_node = head->next->next;
        ListNode* slow_node = head->next;
        while (fast_node!=slow_node){
            if(fast_node->next== nullptr||fast_node->next->next== nullptr){return nullptr;}
            fast_node = fast_node->next->next;
            slow_node = slow_node->next;
        }
        slow_node = head;
        while (fast_node != slow_node){
            slow_node = slow_node->next;
            fast_node = fast_node->next;
        }
        return fast_node;
    }
};

int main(){
    const char* listnode_s = "1->2->6->3->4->5->6";//6-3
    ListNode* head = parse_list(listnode_s);
    ListNode* temp = head;
    ListNode* node;
    int index = 0;
    while (temp->next!= nullptr){
        if(index++ == 3){node = temp;}
        temp = temp->next;
    }
    temp->next = node;
    Solution sl;
    ListNode* res = sl.is_circular_ll(head);
    cout<<res->val<<endl;
}