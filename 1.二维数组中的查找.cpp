/*二维数组中的查找*/

/*在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rowCount = array.size();
        int colCount = array[0].size();
        for (int i=0;i<colCount;i++){
            if (target >= array[i][0] && target <= array[i][colCount-1]){
                for (int j=0;j<colCount;j++){
                    if (target == array[i][j]) return true;
                }
            }
        }
        return false;
    }
};