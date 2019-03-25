/*顺时针打印矩阵*/

/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
        
        if(row == 0 || col == 0) return res;
        int top = 0, left = 0;
        int bottom = row-1, right = col-1; 
        
        while(left<=right && top<=bottom){
            //top left -> top right
            for(int i=left;i<=right;++i){
                res.push_back(matrix[top][i]);
            }
            //top+1 right -> bottom right
            for(int j=top+1;j<=bottom;++j){
                res.push_back(matrix[j][right]);
            }
            //bottom right-1 -> bottom left
            if(top!=bottom)
            for(int k=right-1;k>=left;--k){
                res.push_back(matrix[bottom][k]);
            }
            //bottom-1 left -> top+1 left
            if(left!=right)
            for(int g=bottom-1;g>=top+1;--g){
                res.push_back(matrix[g][left]);
            }
            left++;
            top++;
            right--;
            bottom--;
        }
        return res;
    }
};