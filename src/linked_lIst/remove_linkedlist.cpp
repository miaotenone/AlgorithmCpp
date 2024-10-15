//
// Created by 14771 on 2024/9/19.
//题意：删除链表中等于给定值 val 的所有节点。
//示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]
//示例 2： 输入：head = [], val = 1 输出：[]
//示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]

#include "../utils/common_ds.h"

class Solution{
public:
    ListNode* removeElements_o(ListNode* head, int val){
        while(head!= nullptr && head->val==val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode* cur = head;

        while (cur != nullptr && cur->next!= nullptr){
            if(cur->next->val==val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            cur = cur->next;
        }
        return head;
    }

    ListNode* removeElements_d(ListNode* head, int val){
        ListNode* dummy_node = new ListNode(0);
        dummy_node->next = head;
        ListNode* cur = dummy_node;
        while (cur->next != nullptr){
            if(cur->next->val==val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                continue;
            }
            cur = cur->next;
        }
        head = dummy_node->next;
        delete dummy_node;
        return head;
    }
    ListNode* removeElements_r(ListNode* head, int val){
        if(head == nullptr){
            return head;
        }
        if(head->val = val){
            ListNode* newhead = removeElements_r(head->next,val);
            delete head;
            return newhead;
        }
        else{
            head->next = removeElements_r(head->next,val);
            return head;
        }
    }
};
int main(){
    const char* listnode_s = "1->2->6->3->4->5->6";
    ListNode* head = parse_list(listnode_s);
    int target = 6;
    Solution sl;
    sl.removeElements_d(head,target);
    string res_list = to_string(head);
    cout<<res_list<<endl;

    //create the nodelist and to string
//    ListNode *listNode = new ListNode(0);
//    ListNode *listNode1 = new ListNode(1);
//    ListNode *listNode2 = new ListNode(2);
//    listNode->next = listNode1;
//    listNode1->next = listNode2;
//    string res = to_string(listNode);
//    cout<<res<<endl;
}