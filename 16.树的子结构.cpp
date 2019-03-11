/*树的子结构*/

/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

/*
先找根节点，找到之后再递归检查子节点

其中需要注意的是：
1. 测试用例如果pRoot2为空的话，返回的false而不是我们认为的空树应该是所有树的子树
2. 再判断是否子树的过程中，应该先判断pRoot2是否为空，为空则表明子树的所有节点都比较完了，应该是子树返回True
3. 要养成一个习惯，对任何一个树节点进行访问时，一定要提前检测该节点是否为空
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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        //题目要求，空树不是任何树的子结构
        if (pRoot1 == NULL || pRoot2 == NULL) return false;
        //根节点
        return subtree_check(pRoot1, pRoot2)//看看B是不是以A的根为根的子结构
            || HasSubtree(pRoot1->left,pRoot2) //递归A的左子树，看看做子树中有没有B子结构
            || HasSubtree(pRoot1->right,pRoot2);//同上，递归A的右子树
           
    }
    
    //递归子节点
    bool subtree_check(TreeNode* pRoot1, TreeNode* pRoot2){
        if(pRoot2 == NULL)
            return true;
        //此处为p2 == null 是匹配完成的条件
        //最开始p2肯定不为NULL,这是在主程序HasSubtree中判断过的。
        //递归中，如果p2为空了，则表示上一层的递归中的p2已经匹配完了
        if(pRoot1 == NULL)
            return false;
        return pRoot1->val == pRoot2->val 
            && subtree_check(pRoot1->left,pRoot2->left) 
            && subtree_check(pRoot1->right,pRoot2->right);
    }
};