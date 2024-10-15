//
// Created by 14771 on 2024/9/19.
//题意：反转一个单链表。
//示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL

#include "../utils/common_ds.h"

class Solution{
public:
    ListNode* reverse_ll_r(ListNode* cur,ListNode* last_node = nullptr){
        if(cur == nullptr){
            return last_node;
        }
        ListNode* temp = cur->next;
        cur->next = last_node;

        return reverse_ll_r(temp,cur);
    }

    ListNode* reverse_ll_ptr2(ListNode* head){
        ListNode* last_node,*cur,*next;
        cur = head;
        next = head->next;
        last_node = nullptr;
        while(next != nullptr){
            cur->next = last_node;
            last_node = cur;
            cur = next;
            next = next->next;
        }
        cur->next = last_node;
        return cur;
    }
};

int main(){
    const char* listnode_s = "1->2->6->3->4->5->6";
    ListNode* head = parse_list(listnode_s);
    Solution sl;
    ListNode* res = sl.reverse_ll_r(head);
    string res_list = to_string(res);
    cout<<res_list<<endl;
}