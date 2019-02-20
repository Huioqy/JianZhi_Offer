/*反转链表*/

/*
输入一个链表，反转链表后，输出新链表的表头。
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
递归的方法其实是非常巧的，它利用递归走到链表的末端，
然后再更新每一个node的next 值 ，实现链表的反转。
而newhead 的值没有发生改变，为该链表的最后一个结点，
所以，反转后，我们可以得到新链表的head。
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
         //第二种方法是：递归方法 
        if(pHead==NULL||pHead->next==NULL) return pHead;
         
        //先反转后面的链表，走到链表的末端结点
        ListNode* pReverseNode=ReverseList(pHead->next);
         
        //再将当前节点设置为后面节点的后续节点
        pHead->next->next=pHead;
        pHead->next=NULL;
         
        return pReverseNode;
        
        //第一种方法是：非递归方法:三个指针在链表上同时滑动
        /*
        if(pHead==NULL) return NULL;//注意程序鲁棒性
         
        ListNode* pNode=pHead;//当前指针
        ListNode* pPrev=NULL;//当前指针的前一个结点
        ListNode* pReverseHead=NULL;//新链表的头指针
         
        while(pNode!=NULL){//当前结点不为空时才执行
            ListNode* pNext=pNode->next;//链断开之前一定要保存断开位置后边的结点
             
            if(pNext==NULL)//当pNext为空时，说明当前结点为尾节点
                pReverseHead=pNode;
  
            pNode->next=pPrev;//指针反转
            pPrev=pNode;
            pNode=pNext;
        }
        return pReverseHead;
        */
    }
};