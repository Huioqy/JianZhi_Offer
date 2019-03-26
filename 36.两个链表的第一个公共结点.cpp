/*两个链表的第一个公共结点*/

/*
输入两个链表，找出它们的第一个公共结点。*/

/*
归并排序
先把数组分割成子数组，先统计出子数组内部的逆序对的数目，然后再统计出两个相邻子数组之间的逆序对的数目。
在统计逆序对的过程中，还需要对数组进行排序。
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int length1 = findlength(pHead1);
        int length2 = findlength(pHead2);
        if(length1 > length2) 
            pHead1 = walkstep(pHead1, length1 - length2);
        else 
            pHead2 = walkstep(pHead2, length2 - length1);
        while(pHead1!=NULL){
            if(pHead1 == pHead2) return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return NULL;
   }
    
    int findlength( ListNode* pHead){
        if(pHead == NULL) return NULL;
        int sum = 1;
        while(pHead=pHead->next) sum++;
        return sum;
    }
    
    ListNode* walkstep( ListNode* pHead, int len){
        while(len--)
            pHead = pHead->next;
        return pHead;
    }
    
};