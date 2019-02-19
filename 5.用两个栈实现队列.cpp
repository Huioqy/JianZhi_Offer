/*用两个栈实现队列*/

/*
入队时stack1.push，出队时，先判断stack2中是否有数据，若有直接pop，否则将stack1中的数据出栈，stack2入栈。
但还需要考虑到两者都不存在数据的情况，若要循环，还要将stack2中的数据作为1中的入栈。
*/
/*
stack<int> s;  //定义一个名为s，保存整形元素的栈
s.push(i); //元素i入栈
s.pop(); //删除栈顶元素
s.top(); //返回栈顶元素
s.empty();  //判断栈是否为空，空则返回true
s.size();  //返回栈中包含的元素个数

queue<int> q;  //定义一个名为q， 保存整形元素的队列
q.push(i);  //向队列中添加元素i
q.pop();  //删除此时队列中最早进入的元素
q.front();  //返回此时队列中最早进入的元素
q.back();  //返回此时队列中最后进入的元素
q.empty();  //判断队列是否为空
q.size();  //返回队列包含的元素个数
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp = stack2.top();
        stack2.pop();
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};