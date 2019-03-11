/*复杂链表的复制*/

/*
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

/*
哈希表 无序映射
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;
        unordered_map<RandomListNode*, RandomListNode*> M;
        for(RandomListNode *p=pHead;p!=NULL;p=p->next)
            M[p] = new RandomListNode(p->label);
         
        for(RandomListNode *p=pHead;p!=NULL;p=p->next)
        {
            M[p]->next = M[p->next];
            M[p]->random = M[p->random];
        }
        return M[pHead];
    }
};


/*
哈希表 无序映射
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
         
        //定义一个哈希表
        unordered_map<RandomListNode*,RandomListNode*> table;
         
        // 开辟一个头结点
        RandomListNode* pClonedHead=new RandomListNode(pHead->label);
        pClonedHead->next=NULL;
        pClonedHead->random=NULL;
         
        // 将头结点放入map中
        table.insert(make_pair(pHead,pClonedHead));
         
        //设置操作指针
        RandomListNode* pNode=pHead->next;
        RandomListNode* pClonedNode=pClonedHead;
         
        // 第一遍先将简单链表复制一下
        while(pNode!=NULL)
        {
            // 不断开辟pNode的拷贝结点
            RandomListNode* pClonedTail=new RandomListNode(pNode->label);
            pClonedTail->next=NULL;
            pClonedTail->random=NULL;
             
            //连接新节点，更新当前节点
            pClonedNode->next=pClonedTail;
            pClonedNode=pClonedTail;
             
            //将对应关系  插入到哈希表中
            table.insert(make_pair(pNode,pClonedTail));
             
            //向后移动操作节点
            pNode=pNode->next;
        }
         
        //需从头开始设置random节点，设置操作指针
        pNode=pHead;
        pClonedNode=pClonedHead;
         
        // 根据map中保存的数据，找到对应的节点
        while(pNode!=NULL)
        {
             
            if(pNode->random!=NULL)
            {
                //找到对应节点，更新复制链表
                pClonedNode->random=table.find(pNode->random)->second;
            }
             
            //向后移动操作节点
            pNode=pNode->next;
            pClonedNode=pClonedNode->next;
        }
         
        return pClonedHead;
    }
};

/*
递归 not working
*/

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
         
        //开辟一个新节点
        RandomListNode* pClonedHead=new RandomListNode(pHead->label);
        pClonedHead->next = pHead->next;
        pClonedHead->random = pHead->random;
         
        //递归其他节点
        pClonedHead->next=Clone(pHead->next);
         
        return pClonedHead;
    }
};


/*
    三步法
（1）在旧链表中创建新链表，此时不处理新链表的兄弟节点
（2）很具旧链表的兄弟节点，初始化新链表的兄弟节点
（3）从旧链表中拆分得到新链表
*/


class Solution {
public:
    //复制原始链表的任一节点N并创建新节点N'，再把N'链接到N的后边
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=new RandomListNode(0);
            pCloned->label=pNode->label;
            pCloned->next=pNode->next;
            pCloned->random=NULL;
              
            pNode->next=pCloned;
              
            pNode=pCloned->next;
        }
    }
    //如果原始链表上的节点N的random指向S，则对应的复制节点N'的random指向S的下一个节点S'
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=pNode->next;
            if(pNode->random!=NULL)
                pCloned->random=pNode->random->next;
            pNode=pCloned->next;
        }
    }
    //把得到的链表拆成两个链表，奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表
    RandomListNode* ReConnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        RandomListNode* pClonedHead=NULL;
        RandomListNode* pClonedNode=NULL;
          
        //初始化
        if(pNode!=NULL)
        {
            pClonedHead=pClonedNode=pNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
              
        }
        //循环
        while(pNode!=NULL)
        {
            pClonedNode->next=pNode->next;
            pClonedNode=pClonedNode->next;
            pNode->next=pClonedNode->next;
            pNode=pNode->next;
        }
          
        return pClonedHead;
          
    }
    //三步合一
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReConnectNodes(pHead);
    }
};
