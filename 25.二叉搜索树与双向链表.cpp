﻿/*二叉搜索树与双向链表*/

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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

/*
方法二：递归版
解题思路：
1.将左子树构造成双链表，并返回链表头节点。
2.定位至左子树双链表最后一个节点。
3.如果左子树链表不为空的话，将当前root追加到左子树链表。
4.将右子树构造成双链表，并返回链表头节点。
5.如果右子树链表不为空的话，将该链表追加到root节点之后。
6.根据左子树链表是否为空确定返回的节点。
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) 
            return NULL;
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL)
            return pRootOfTree;
        //1.将左子树构造成双链表，并返回链表头节点
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* leftLast = left;
        //2.定位至左子树双链表最后一个节点
        while(leftLast != NULL && leftLast->right != NULL)
                leftLast = leftLast->right;
        // 3.如果左子树链表不为空的话，将当前root追加到左子树链表
        if(leftLast != NULL){
            pRootOfTree->left = leftLast;
            leftLast->right = pRootOfTree;
        }
         // 4.将右子树构造成双链表，并返回链表头节点
        TreeNode* right = Convert(pRootOfTree->right);
        // 5.如果右子树链表不为空的话，将该链表追加到root节点之后
        if(right != NULL){
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        //左子树为空时，返回root
        return left!=NULL?left:pRootOfTree;
    }
};