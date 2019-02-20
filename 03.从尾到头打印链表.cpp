/*从尾到头打印链表*/

/*输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。*/

/*
std::stack
template<
    class T,
    class Container = std::deque<T>
> class stack;
std::stack 类是容器适配器，它给予程序员栈的功能——特别是 FILO （先进后出）数据结构。

T	-	存储的元素类型。
back()
push_back()
pop_back()


*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

//利用栈实现先进后出的思路
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        std::stack<int> nodes;
        vector<int> outnodes;
        
        while(head!=NULL){
            nodes.push(head->val);
            head = head->next;
        }
        while(!nodes.empty()){
            outnodes.push_back(nodes.top());
            nodes.pop();
        }
        return outnodes;
    }
};

//push_back vector 然后 reverse