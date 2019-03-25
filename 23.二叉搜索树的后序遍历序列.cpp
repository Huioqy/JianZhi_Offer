/*二叉搜索树的后序遍历序列*/

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
/*
后序遍历 左子树 右子树 根
采用分治法的思想，找到根结点、左子树的序列、右子树的序列，分别判断左右子序列是否为二叉树的后序序列。

由题意可得：
1. 后序遍历序列的最后一个元素为二叉树的根节点；
2. 二叉搜索树左子树上所有的结点均小于根结点、右子树所有的结点均大于根结点。

算法步骤如下：
1. 找到根结点；
2. 遍历序列，找到第一个大于等于根结点的元素i，则i左侧为左子树、i右侧为右子树；
3. 我们已经知道i左侧所有元素均小于根结点，那么再依次遍历右侧，看是否所有元素均大于根结点；若出现小于根结点的元素，则直接返回false；若右侧全都大于根结点，则：
4. 分别递归判断左/右子序列是否为后序序列；
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        
        vector<int> leftTree,rightTree;
        int len = sequence.size();
        int root= sequence[len-1]; // 根结点
        int index = 0; // 标记左右子树界限
        int i=0;
        
        // 找到第一个大于根结点的位置，则左边为左子树，右边为右子树
        for(;i<len-1;++i)
        {
            if(sequence[i]>root) break; 
        }
         // 循环时去除root，因此为len-1
        // 有一个小于root，则返回false
        for(int j=i;j<len-1;++j)
        {
            if(sequence[j]<root) return false; 
        }
         
        // 即有左子树
        if(i!=0)
        {
            for(int m=0;m<i;++m)
            {
                leftTree.push_back(sequence[m]);
            }
        }
        // 即有右子树
        if(i!=len-2)
        {
            for(int j=i;j<len-1;++j)
            {
                rightTree.push_back(sequence[j]);
            }
        }
         
        bool left = true,right = true; // 看左右子树是否是二叉搜索树
        if(leftTree.size()>1) VerifySquenceOfBST(leftTree);
        if(rightTree.size()>1) VerifySquenceOfBST(rightTree);
         
        return (left&&right);
    }
};