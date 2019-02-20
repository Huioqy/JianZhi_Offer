/*链表中倒数第k个结点*/

/*
输入一个链表，输出该链表中倒数第k个结点。
*/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

/*
时间复杂度O(n),一次遍历即可
两个指针，一个先跑一个后跑，保持k-1的距离
先跑指针到达末尾，后跑指针即为倒数第k个
*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k==0)
            return NULL;
        ListNode *pHead = pListHead,*pTail = pListHead;
         for(int i=1;i<k;++i)
        {
            if(pHead->next!=NULL)
                pHead=pHead->next;
            else
                return NULL;
        }
        while(pHead->next!=NULL)
        {
            pHead=pHead->next;
            pTail=pTail->next;
        }
        return pTail;

    }
};