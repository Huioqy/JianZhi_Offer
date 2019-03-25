/*二叉树中和为某一值的路径*/

/*
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
*/

/*
递归先序遍历树，把结点加入路径。
若该结点是叶子结点则比较当前路径和是否等于期待和。
弹出结点，每一轮递归返回到父结点时，当前路径也应该回退一个结点
 
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
    vector<vector<int>> res;
    vector<int> path;
    
    void find(TreeNode* root,int targrt){
        if(root == NULL) return;
        path.push_back(root->val);
        
        if(root->left == NULL 
           && root->right==NULL 
           && targrt == root->val){
            res.push_back(path);
        }
        if(root->left != NULL)
            find(root->left, targrt - root->val);
        if(root->right != NULL)
            find(root->right, targrt - root->val);
        path.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }
    
        
};