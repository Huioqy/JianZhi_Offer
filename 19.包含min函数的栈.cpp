/*包含min函数的栈*/

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

/*
应用一个辅助栈，压的时候，如果A栈的压入比B栈压入大，B栈不压，，，，小于等于，AB栈同时压入，出栈，如果，AB栈顶元素不等，A出，B不出。
*/
class Solution {
public:
    
    stack<int> stack1,stack2;
    
    void push(int value) {
        stack1.push(value);
        if(stack2.empty()) stack2.push(value);
        //if(value<=stack2.top() || stack2.empty()) 
        if(value<=stack2.top()) stack2.push(value);
    }
    void pop() {
        if(stack1.top() == stack2.top())
            stack2.pop();
        stack1.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
};