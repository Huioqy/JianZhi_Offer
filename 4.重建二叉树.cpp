/*重建二叉树*/

/*输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 先序遍历第一个位置肯定是根节点node，
  中序遍历的根节点位置在中间p，在p左边的肯定是node的左子树的中序数组，p右边的肯定是node的右子树的中序数组
  另一方面，先序遍历的第二个位置到p，也是node左子树的先序子数组，剩下p右边的就是node的右子树的先序子数组
  把四个数组找出来，分左右递归调用即可
*/

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0 || pre.size() == 0){
            return NULL;
        }
        // root is the pre's fisrt element
        int val = pre[0]; 
        vector<int> pre_left, pre_right, vin_left, vin_right;
        // find root position in pre
        int p_val = 0;
        for(p_val; p_val < vin.size(); p_val++){
            if(vin[p_val] == val) 
                break;
        }
        //Construct the left pre and in 
        for(int i=0; i<p_val; i++){
            pre_left.push_back(pre[i+1]);
            vin_left.push_back(vin[i]);    
        }
        //Construct the right pre and in 
        for(int i=p_val+1; i<vin.size(); i++){
            pre_right.push_back(pre[i]);
            vin_right.push_back(vin[i]);   
        }
        TreeNode* node = new TreeNode(val);
        node->left = reConstructBinaryTree(pre_left,vin_left);
        node->right = reConstructBinaryTree(pre_right,vin_right);
        return node;
    }
};