﻿/*合并两个排序的链表*/

/*
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        //新建节点，用来存合并的链表。
        ListNode* result = NULL;
        ListNode* current = NULL;
         
        if(pHead1 == NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        /*
        //递归
        if(pHead1->val <= pHead2->val){
            result = pHead1;
            result->next = Merge(pHead1->next, pHead2);
        } else {
            result = pHead2;
            result->next = Merge(pHead1, pHead2->next);
        }
        */
        //非递归版本
        while(pHead1 != NULL && pHead2 != NULL){
            if(pHead1->val <= pHead2->val){
                if(result == NULL){
                    current = result = pHead1;
                } else {
                    current->next = pHead1;
                    current = current->next;
                }
                pHead1 = pHead1->next;
            } else {
                if(result == NULL){
                    current = result = pHead2;
                } else {
                    current->next = pHead2;
                    current = current->next;
                }
                pHead2 = pHead2->next;
            }
        }
        //把未结束的链表连接到合并后的链表尾部
        if(pHead1 == NULL){
            current->next = pHead2;
        }
        if(pHead2 == NULL){
            current->next = pHead1;
        }
         
        return result;
    }
};
