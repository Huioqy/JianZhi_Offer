/*平衡二叉树*/

/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/*
平衡二叉树（Balanced Binary Tree），具有以下性质：
它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。

最直接的做法，遍历每个结点，借助一个获取树深度的递归函数，
根据该结点的左右子树高度差判断是否平衡，然后递归地对左右子树进行判断。

这种做法有很明显的问题，在判断上层结点的时候，会多次重复遍历下层结点，增加了不必要的开销。
如果改为从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；
如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次。
*/
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return getDepth(pRoot) != -1 ;
    }

    int getDepth(TreeNode* pRoot){
        if(pRoot == NULL) return 0;
        int left = getDepth(pRoot->left);
        if(left == -1) return -1;//不平衡
        int right = getDepth(pRoot->right);
        if(right == -1) return -1;//不平衡
        //平衡返回高度，不平衡返回-1
        return abs(left-right) > 1 ? -1 : 1 + max(left,right);
        //（条件表达式）？（条件为真时的表达式）：（条件为假时的表达式）
    }
};

/*
public classSolution {
    public boolean IsBalanced_Solution(TreeNode root) {
        if(root == null) {
            return true;
        }
        return Math.abs(maxDepth(root.left) - maxDepth(root.right)) <= 1 &&
            IsBalanced_Solution(root.left) && IsBalanced_Solution(root.right);
    }

    private int maxDepth(TreeNode root) {
        if(root == null) {
            return 0;
        }
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}

*/
