/*从上往下打印二叉树*/

/*
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/*
队列 FIFO（First In First Out）
*/
/*
调用的时候要有头文件： #include<stdlib.h> 或 #include<cstdlib> +
#include<queue>       #include<queue>
详细用法:
定义一个queue的变量     queue<Type> M
查看是否为空范例        M.empty()    是的话返回1，不是返回0;
从已有元素后面增加元素   M.push()
输出现有元素的个数      M.size()
显示第一个元素          M.front()
显示最后一个元素        M.back()
清除第一个元素          M.pop()      注意，并不会返回被弹出元素的值。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> qTree;
        
        qTree.push(root);
        
        while(!qTree.empty()){
            TreeNode* node = qTree.front();//提取队列最前面的值
            qTree.pop();//清除队列最前面的值
            if(node == NULL) continue;
            res.push_back(node->val);
            qTree.push(node->left);//压入左边
            qTree.push(node->right);//压入右边
        }
        
        return res;
        
    }
};